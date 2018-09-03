#include <iostream>
#include <string>
using namespace std;

string day[8] = { "", "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

int hourChange(char c)
{
	if (c <= '9' && c >= '0')
		return c - '0';
	else
		return c - 'A' + 10;
}

int main()
{
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;

	int week = 0;
	int hour = 0;
	int minute = 0;
	for (int i = 0; i < s1.length() && i < s2.length(); i++)
	{
		if (s1[i] == s2[i])
		{
			if (week == 0)
			{
				if (s1[i] >= 'A' && s1[i] <= 'G')
				{
					week = s1[i] - 'A' + 1;
				}
			}
			else
			{
				if (s1[i] >= 'A' && s1[i] <= 'N')
				{
					hour = hourChange(s1[i]);
					break;
				}
				else if (s1[i] >= '0' && s1[i] <= '9')
				{
					hour = hourChange(s1[i]);
					break;
				}
			}
		}
	}

	for (int i = 0; i < s3.length() && i < s4.length(); i++)
	{
		if (s3[i] == s4[i])
		{
			if ((s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z'))
			{
				minute = i;
				break;
			}
		}

	}

	cout << day[week] << " ";

	if (hour < 10)
		cout << "0" << hour;
	else
		cout << hour;

	cout << ":";

	if (minute < 10)
		cout << "0" << minute;
	else
		cout << minute;
	cout << endl;

	return 0;
}