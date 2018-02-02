#include <iostream>
#include <iomanip>
using namespace std;

double A[1001];
double B[1001];
double sum[2001];

int main()
{
	for (int i = 0; i < 1001; i++)
	{
		A[i] = 0;
		B[i] = 0;
	}

	for (int i = 0; i < 2001; i++)
	{
		sum[i] = 0;
	}

	int index;
	double coefficient;
	int itemNum;

	cin >> itemNum;
	while (itemNum--)
	{
		cin >> index >> coefficient;
		A[index] = coefficient;
	}

	cin >> itemNum;
	while (itemNum--)
	{
		cin >> index >> coefficient;
		B[index] = coefficient;
	}

	for (int i = 0; i < 1001; i++)
	{
		for (int j = 0; j < 1001; j++)
		{
			sum[i + j] += A[i] * B[j];
		}
	}

	// get non zero number
	int nonZero = 0;
	for (int i = 0; i < 2001; i++)
	{
		if (sum[i] != 0)
			nonZero++;
	}

	cout << nonZero;
	if (nonZero == 0)
	{
		cout << endl;
		return 0;
	}

	for (int i = 2000; i >= 0; i--)
	{
		if (sum[i] != 0)
			cout << " " << i << " " << fixed << setprecision(1) << sum[i];
	}
	cout << endl;

	return 0;
}