#include <iostream>
#include <string>
using namespace std;

string english[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int digitSum(string number)
{
	int sum = 0;
	for (int i = 0; i < number.length(); i++)
	{
		sum += number[i] - '0';
	}
	return sum;
}

string itos(int number)
{
	string toString;
	while (number != 0)
	{
		char n = number % 10 + '0';
		toString = n + toString;
		number /= 10;
	}

	return toString;
}

int main()
{
	string number;
	cin >> number;
	int sum = digitSum(number);
	string sumDigit = itos(sum);
	cout << english[sumDigit[0] - '0'];
	for (int i = 1; i < sumDigit.length(); i++)
	{
		cout << " " << english[sumDigit[i] - '0'];
	}
	cout << endl;
	return 0;
}