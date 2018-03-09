#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int reverse_by_radix(int decimal, int radix)
{
	int result = 0;
	while (decimal != 0)
	{
		result = result * radix + decimal % radix;
		decimal /= radix;
	}
	return result;
}

bool isPrime(int number)
{
	if (number <= 1)
		return false;
	int range = (int)sqrt(number);
	for (int i = 2; i <= range; i++)
	{
		if (number % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int number, radix;
	while (true)
	{
		cin >> number;
		if (number < 0)
			break;
		cin >> radix;
		if (isPrime(number) && isPrime(reverse_by_radix(number, radix)))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}