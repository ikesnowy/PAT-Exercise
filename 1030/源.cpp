#include <iostream>
#include <string>
using namespace std;

long long any[32];
int decimal_to_any(long long decimal, long long base)
{
	if (decimal == 0)
	{
		any[0] = 0;
		return 0;
	}
	int length = 0;
	while (decimal != 0)
	{
		long long temp = decimal % base;
		any[length] = temp;
		length++;
		decimal /= base;
	}
	return length;
}

int main()
{
	long long num, base;
	cin >> num >> base;
	int number = decimal_to_any(num, base);
	int i = 0;
	for (i = 0; i < number / 2; i++)
	{
		if (any[i] != any[number - i - 1])
		{
			cout << "No" << endl;
			break;
		}
	}
	if (i == number / 2)
		cout << "Yes" << endl;
	int j = 0;
	for (j = number - 1; j > 0; j--)
	{
		cout << any[j] << " ";
	}
	cout << any[0] << endl;
	return 0;
}