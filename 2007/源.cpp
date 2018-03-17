#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int factor_length = 1;
	int max_factor_length = 1;
	int max_factor_start = 2;
	bool isFind = false;
	while (factor_length < 12)
	{
		int factor_start = 2;
		while (factor_start * factor_start < n)
		{
			int factor = factor_start;
			for (int i = 1; i < factor_length; i++)
			{
				factor *= factor_start + i;
			}
			if (n % factor == 0)
			{
				if (max_factor_length < factor_length || !isFind)
				{
					max_factor_length = factor_length;
					max_factor_start = factor_start;
				}
				isFind = true;
			}
			factor_start++;
		}
		factor_length++;
	}
	if (!isFind)
	{
		max_factor_length = 1;
		max_factor_start = n;
	}
	cout << max_factor_length << endl;
	cout << max_factor_start;
	for (int i = 1; i < max_factor_length; i++)
	{
		cout << "*" << max_factor_start + i;
	}
	cout << endl;
	return 0;
}