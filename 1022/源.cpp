#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int atoi(char a)
{
	if (a >= '0' && a <= '9')
		return a - '0';
	else
		return a - 'a' + 10;
}

int smallestRadix(string n)
{
	int max = 2;
	for (int i = 0; i < n.length(); i++)
	{
		if (atoi(n[i]) + 1 > max)
			max = atoi(n[i]) + 1;
	}
	return max;
}

long long anytodecimal(string number, long long radix, long long target)
{
	long long sum = 0;
	int length = number.length();
	long long power = 1;
	for (int i = length - 1; i >= 0; i--)
	{
		int n = atoi(number[i]);
		if (n >= radix)
			return target - 1;
		sum += atoi(number[i]) * power;
		power *= radix;
	}
	return sum;
}

int main()
{
	string a, b;
	long long tag, radix;

	cin >> a >> b >> tag >> radix;

	long long target = 0;
	int minRadix = 0;
	string needTry;
	if (tag == 1)
	{
		target = anytodecimal(a, radix, -1);
		needTry = b;
		minRadix = smallestRadix(a);
	}
	else
	{
		target = anytodecimal(b, radix, -1);
		needTry = a;
		minRadix = smallestRadix(b);
	}

	bool isFind = false;
	long long lo = minRadix;
	long long hi = target;
	long long minium = hi;
	while (lo <= hi)
	{
		long long mid = lo + (hi - lo) / 2;
		long long tryResult = anytodecimal(needTry, mid, target);
		if (target == tryResult)
		{
			if (mid <= minium)
			{
				minium = mid;
				hi = mid - 1;
				isFind = true;
			}
		}
		else if (target < tryResult)
		{
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}

	if (isFind)
		cout << minium << endl;
	else
		cout << "Impossible" << endl;
	return 0;
}