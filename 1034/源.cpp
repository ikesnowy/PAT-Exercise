#include <iostream>
#include <string>
using namespace std;

int digit[10] = { 0 };
void checkA(string a)
{
	int i = 0;
	for (i = 0; i < a.length(); i++)
	{
		int index = a[i] - '0';
		digit[index] = 1;
	}
}

bool checkB(string b)
{
	int i = 0;
	for (i = 0; i < b.length(); i++)
	{
		int index = b[i] - '0';
		digit[index]--;
	}
	for (i = 0; i < 10; i++)
	{
		if (digit[i] != 0)
			return false;
	}
	return true;
}

string double_number(string a)
{
	string b;
	int temp = 0, carry = 0;
	for (int i = a.length() - 1; i >= 0; i--)
	{
		temp = (a[i] - '0') * 2 + carry;
		carry = temp / 10;
		temp = temp % 10;
		b = ((char)(temp + '0')) + b;
	}
	if (carry != 0)
		b = ((char)(carry + '0')) + b;
	return b;
}

int main()
{
	string a;
	cin >> a;
	string b = double_number(a);
	checkA(a);
	if (checkB(b))
	{
		cout << "Yes" << endl;
		cout << b << endl;
		return 0;
	}

	cout << "No" << endl;
	cout << b << endl;
	return 0;
}