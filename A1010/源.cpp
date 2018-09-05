#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int atoi(char a)
{
	if (a >= '0' && a <= '9')
		return a - '0';
	else
		return a - 'a' + 10;
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

int cmp(string N2, long long radix, long long target)
{
	long long num = anytodecimal(N2, radix, target);
	if (num < 0)
		return 1;
	else if (num < target)
		return -1;
	else if (num > target)
		return 1;
	else
		return 0;	
}

int main()
{
	string N1, N2;
	long long tag, radix;

	cin >> N1 >> N2 >> tag >> radix;

	if (tag != 1)
		swap(N1, N2);
	long long target = anytodecimal(N1, radix, -1);

	bool isFind = false;
	long long lo = 2;
	long long hi = 99999999999999;
	long long minium = hi;
	while (lo <= hi)
	{
		long long mid = lo + (hi - lo) / 2;
		int flag = cmp(N2, mid, target);
		if (flag == 0)
		{
			if (mid < minium)
			{
				minium = mid;
				hi = mid - 1;
				isFind = true;
			}
		}
		else if (flag == 1)
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