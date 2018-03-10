#include <iostream>
#include <string>
using namespace std;

bool check(string a)
{
	for (int i = 0; i < a.length() / 2; i++)
	{
		if (a[i] != a[a.length() - i - 1])
			return false;
	}
	return true;
}

string plus_string(string a, string b)
{
	int lengthA = a.length() - 1;
	int lengthB = b.length() - 1;
	string result;
	int carry = 0;
	int now = 0;
	while (lengthA >= 0 || lengthB >= 0)
	{
		now = carry;
		if (lengthA >= 0)
			now += a[lengthA] - '0';
		if (lengthB >= 0)
			now += b[lengthB] - '0';

		carry = now / 10;
		now = now % 10;
		result = ((char)(now + '0')) + result;
		lengthA--;
		lengthB--;
	}
	if (carry != 0)
		result = ((char)(carry + '0')) + result;
	return result;
}

string reverse_string(string a)
{
	string b;
	for (int i = a.length() - 1; i >= 0; i--)
	{
		b += a[i];
	}
	return b;
}

int main()
{
	string a;
	int max_time;
	cin >> a >> max_time;
	int now_time = 0;
	while (!check(a) && now_time < max_time)
	{
		a = plus_string(a, reverse_string(a));
		now_time++;
	}
	if (now_time > max_time)
		cout << a << endl << max_time << endl;

	cout << a << endl;
	cout << now_time << endl;
	return 0;
}