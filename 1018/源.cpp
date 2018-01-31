#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class check_time
{
public:
	int hour;
	int minute;
	int second;

	bool operator > (check_time other)
	{
		if (hour == other.hour)
		{
			if (minute == other.minute)
			{
				return second > other.second;
			}
			else
			{
				return minute > other.minute;
			}
		}
		else
		{
			return hour > other.hour;
		}
	}

	bool operator < (check_time other)
	{
		if (hour == other.hour)
		{
			if (minute == other.minute)
			{
				return second < other.second;
			}
			else
			{
				return minute < other.minute;
			}
		}
		else
		{
			return hour < other.hour;
		}
	}
};

class student
{
public:
	string ID;
	check_time signIn;
	check_time signOut;
};

int main()
{
	vector<student> records;
	int n = 0;
	cin >> n;
	while (n--)
	{
		student checkRecord;
		cin >> checkRecord.ID;
		scanf("%d:%d:%d", &checkRecord.signIn.hour, &checkRecord.signIn.minute, &checkRecord.signIn.second);
		scanf("%d:%d:%d", &checkRecord.signOut.hour, &checkRecord.signOut.minute, &checkRecord.signOut.second);
		records.push_back(checkRecord);
	}

	check_time firstSignIn;
	firstSignIn.hour = 24;
	firstSignIn.minute = 60;
	firstSignIn.second = 60;
	string firstStudentID;
	for (vector<student>::iterator i = records.begin(); i < records.end(); i++)
	{
		if ((*i).signIn < firstSignIn)
		{
			firstSignIn = (*i).signIn;
			firstStudentID = (*i).ID;
		}
	}

	check_time lastSignOut;
	lastSignOut.hour = 0;
	lastSignOut.minute = 0;
	lastSignOut.second = 0;
	string lastStudentID;
	for (vector<student>::iterator i = records.begin(); i < records.end(); i++)
	{
		if ((*i).signOut > lastSignOut)
		{
			lastSignOut = (*i).signOut;
			lastStudentID = (*i).ID;
		}
	}

	cout << firstStudentID << " " << lastStudentID << endl;
	return 0;
}