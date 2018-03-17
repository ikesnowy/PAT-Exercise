#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <map>
using namespace std;

class record
{
public:
	string plate;
	int time;
	bool state;

	bool operator < (record other)
	{
		if (plate == other.plate)
		{
			return time < other.time;
		}
		return plate < other.plate;
	}
};

vector<record> records;
map<string, int> plates;
int delta[24 * 3600 + 1] = { 0 };

int main()
{
	int i, j;
	int record_sum, query_sum;
	cin >> record_sum >> query_sum;
	string plate, state;
	int h, m, s;
	for (i = 0; i < record_sum; i++)
	{
		cin >> plate;
		scanf("%d:%d:%d", &h, &m, &s);
		cin >> state;
		record readIn;
		readIn.plate = plate;
		readIn.time = h * 3600 + m * 60 + s;
		readIn.state = (state == "in");
		plates[plate] = 0;
		records.push_back(readIn);
	}

	sort(records.begin(), records.end());

	string nowPlate;
	for (i = 0; i < record_sum; i++)
	{
		nowPlate = records[i].plate;
		if (!records[i].state)
			continue;
		while (records[i].state && records[i].plate == nowPlate)
			i++;
		if (records[i].plate != nowPlate)
		{
			i--;
			continue;
		}
		else
		{
			delta[records[i - 1].time]++;
			delta[records[i].time]--;
			plates[nowPlate] += records[i].time - records[i - 1].time;
		}
	}

	map<string, int>::iterator it = plates.begin();
	int max_time = (*it).second;
	vector<string> max_plates;
	max_plates.push_back((*it).first);
	it++;
	for (; it != plates.end(); it++)
	{
		if ((*it).second > max_time)
		{
			max_time = (*it).second;
			max_plates.clear();
			max_plates.push_back((*it).first);
		}
		else if ((*it).second == max_time)
		{
			max_plates.push_back((*it).first);
		}
	}

	for (i = 1; i <= 24 * 3600; i++)
	{
		delta[i] += delta[i - 1];
	}

	while (query_sum--)
	{
		scanf("%d:%d:%d", &h, &m, &s);
		cout << delta[h * 3600 + m * 60 + s] << endl;
	}

	sort(max_plates.begin(), max_plates.end());

	cout << max_plates[0];
	for (i = 1; i < max_plates.size(); i++)
	{
		cout << " " << max_plates[i];
	}
	cout << " ";
	cout << setw(2) << setfill('0') << max_time / 3600 << ":";
	max_time = max_time % 3600;
	cout << setw(2) << setfill('0') << max_time / 60 << ":";
	cout << setw(2) << setfill('0') << max_time % 60 << endl;
	return 0;
}