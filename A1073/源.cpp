#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	char signExp;
	char temp[10010];
	scanf("%s", &temp);
	string number(temp);
	if (number[0] == '-')
		cout << '-';

	int E = number.find('E');
	signExp = number[E + 1];

	int exp = 0;
	int exponent = 1;
	for (int i = number.length() - 1; i > E + 1; i--)
	{
		exp += (number[i] - '0') * exponent;
		exponent *= 10;
	}

	if (signExp == '-')
	{
		cout << "0.";
		for (int i = 0; i < exp - 1; i++)
			printf("0");
		for (int i = 1; i < E; i++)
		{
			if (number[i] == '.')
				continue;
			else
				cout << number[i];
		}
		cout << endl;
	}
	else
	{
		for (int i = 1; i < E; i++)
		{
			if (number[i] == '.')
				continue;
			cout << number[i];
			if (i == exp + 2 && E - 3 != exp)
				cout << ".";
		}

		for (int i = 0; i < exp - E + 3; i++)
			printf("0");
		cout << endl;
	}
	return 0;
}