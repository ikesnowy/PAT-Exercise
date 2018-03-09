#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

class phone_records
{
public:
	int time;
	bool state_flag;

	phone_records()
	{
		time = 0;
		state_flag = false;
	}

	bool operator < (phone_records other)
	{
		return time < other.time;
	}
};

class customer
{
public:
	string name;
	vector<phone_records> monthly_records;

	bool operator < (customer other)
	{
		return name < other.name;
	}
};

int hourly_rate[24];
double daily_rate = 0;
vector<customer> all_customers;
int month;

double caculate_bill(int start, int end)
{
	int start_day = start / 1440;
	start = start % 1440;
	int start_hour = start / 60;
	int start_minute = start % 60;

	int end_day = end / 1440;
	end = end % 1440;
	int end_hour = end / 60;
	int end_minute = end % 60;

	if (start_day == end_day)
	{
		if (start_hour == end_hour)
		{
			return hourly_rate[start_hour] * (end_minute - start_minute) * 0.01;
		}
		else
		{
			double sum = 0;
			for (int i = start_hour; i < end_hour; i++)
			{
				sum += (60 - start_minute) * hourly_rate[i] * 0.01;
				start_minute = 0;
			}
			sum += end_minute * hourly_rate[end_hour] * 0.01;
			return sum;
		}
	}
	else
	{
		double sum = 0;
		for (int i = start_hour; i < 24; i++)
		{
			sum += (60 - start_minute) * hourly_rate[i] * 0.01;
			start_minute = 0;
		}
		start_day++;
		sum += (end_day - start_day) * daily_rate;
		for (int j = 0; j < end_hour; j++)
		{
			sum += (60 - start_minute) * hourly_rate[j] * 0.01;
			start_minute = 0;
		}
		sum += end_minute * hourly_rate[end_hour] * 0.01;
		return sum;
	}
}

int main()
{
	int i = 0, j = 0, k = 0;
	for (i = 0; i < 24; i++)
	{
		cin >> hourly_rate[i];
		daily_rate += hourly_rate[i] * 60 * 0.01;
	}

	int records_sum;
	cin >> records_sum;
	while (records_sum--)
	{
		string name, state;
		int day, hour, minute;
		cin >> name;
		scanf("%d:%d:%d:%d", &month, &day, &hour, &minute);
		cin >> state;
		phone_records record;
		record.time = day * 1440 + hour * 60 + minute;
		record.state_flag = (state == "on-line") ? false : true;
		for (i = 0; i < (int)all_customers.size(); i++)
		{
			if (all_customers[i].name == name)
			{
				all_customers[i].monthly_records.push_back(record);
				break;
			}
		}
		if (i == (int)all_customers.size())
		{
			customer cust;
			cust.name = name;
			cust.monthly_records.push_back(record);
			all_customers.push_back(cust);
		}
	}

	for (i = 0; i < (int)all_customers.size(); i++)
	{
		sort(all_customers[i].monthly_records.begin(), all_customers[i].monthly_records.end());
	}

	sort(all_customers.begin(), all_customers.end());

	for (i = 0; i < (int)all_customers.size(); i++)
	{
		double sum = 0;
		bool expected = false;
		bool has_bill = false;
		int start_temp, end_temp;
		
		for (k = 0; k < (int)all_customers[i].monthly_records.size(); k++)
		{
			if (all_customers[i].monthly_records.at(k).state_flag == false)
			{
				expected = true;
				start_temp = all_customers[i].monthly_records.at(k).time;
			}
			else
			{
				if (!expected)
					continue;
				end_temp = all_customers[i].monthly_records.at(k).time;
				double one_bill = caculate_bill(start_temp, end_temp);
				sum += one_bill;

				if (!has_bill)
				{
					cout << all_customers[i].name << " " << setw(2) << setfill('0') << month << endl;
					has_bill = true;
				}
				cout << setw(2) << setfill('0') << start_temp / 1440 << ":";
				cout << setw(2) << setfill('0') << (start_temp % 1440) / 60 << ":";
				cout << setw(2) << setfill('0') << (start_temp % 1440) % 60;
				cout << " ";
				cout << setw(2) << setfill('0') << end_temp / 1440 << ":";
				cout << setw(2) << setfill('0') << (end_temp % 1440) / 60 << ":";
				cout << setw(2) << setfill('0') << (end_temp % 1440) % 60;
				cout << " ";
				cout << end_temp - start_temp << " ";

				cout << "$" << fixed << setprecision(2) << one_bill << endl;
				expected = !expected;
			}
		}
		if (has_bill)
			cout << "Total amount: $" << fixed << setprecision(2) << sum << endl;
	}
	return 0;
}