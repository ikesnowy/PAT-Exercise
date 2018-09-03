#include <iostream>
#include <string>
using namespace std;

string num[10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
string digit[5] = { "Yi", "Wan", "Qian", "Bai", "Shi" };
string digitForSection[3] = { "", "Wan", "Yi" };

int main()
{
	string number;
	cin >> number;

	if (number == "0")
	{
		cout << "ling" << endl;
		return 0;
	}

	if (number[0] == '-')
	{
		cout << "Fu ";
		number.erase(0, 1);
	}

	int t = number.length() % 4;
	if (t != 0)
	{
		t = 4 - t;
		while (t--)
		{
			number = '0' + number;
		}
	}

	int sections = number.length() / 4;
	bool spaceAhead = true;
	bool firstNumber = true;
	for (int i = 0; i < sections; i++)
	{
		bool continuousZero = false;
		int left = 0 + 4 * i;
		bool fullZero = true;
		for (int j = 0; j < 4; j++)
		{
			if (number[left + j] != '0')
			{
				if (continuousZero)
				{
					if (!spaceAhead)
						cout << " ";
					else
						spaceAhead = false;

					cout << num[0];
					continuousZero = false;
				}

				if (!spaceAhead)
					cout << " ";
				else
					spaceAhead = false;

				cout << num[number[left + j] - '0'];
				fullZero = false;
				if (j < 3)
				{
					if (!spaceAhead)
					{
						cout << " ";
					}
					cout << digit[2 + j];
				}
			}
			else
			{
				if (i == 0 && fullZero)
					continue;
				continuousZero = true;
			}
		}

		if (!fullZero && sections - i != 1)
		{
			cout << " " << digitForSection[sections - i - 1];
		}

	}

	return 0;
}