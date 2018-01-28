#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main()
{
	double poly[1001];
	for (int i = 0; i < 1001; i++)
		poly[i] = 0;
	int n;
	cin >> n;
	while (n--)
	{
		int index;
		double value;
		cin >> index >> value;
		poly[index] += value;
	}
	cin >> n;
	while (n--)
	{
		int index;
		double value;
		cin >> index >> value;
		poly[index] += value;
	}

	int sum = 0;
	for (int i = 1000; i >= 0; i--)
	{
		if (poly[i] != 0)
			sum++;
	}

	cout << sum;
	if (sum != 0)
	{
		for (int i = 1000; i >= 0; i--)
		{
			if (poly[i] != 0)
			{
				printf(" %d %.1lf", i, poly[i]);
			}
		}
	}

	return 0;
}