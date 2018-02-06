#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	string result;
	double sum = 1;
	for (int i = 0; i < 3; i++)
	{
		double max = 0;
		int choice = 1;
		cin >> max;
		double temp;
		for (int j = 2; j <= 3; j++)
		{
			cin >> temp;
			if (temp > max)
			{
				max = temp;
				choice = j;
			}
		}
		if (choice == 1)
			result += "W ";
		else if (choice == 2)
			result += "T ";
		else
			result += "L ";
		sum *= max;
	}

	sum *= 0.65;
	sum -= 1;
	sum *= 2;

	int num = sum * 1000;
	if (num % 10 == 5)
		num++;
	sum = num / 1000.0;

	cout << result;
	cout << fixed << setprecision(2) << sum << endl;
	return 0;
}