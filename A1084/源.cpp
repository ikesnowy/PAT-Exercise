#include <iostream>
#include <string>
using namespace std;

int main()
{
	string origin;
	string typed;
	bool printed[128];
	for (int i = 0; i < 128; i++)
		printed[i] = false;
	cin >> origin >> typed;
	for (int i = 0; i < origin.length(); i++)
		if (origin[i] >= 'a' && origin[i] <= 'z')
			origin[i] -= 'a' - 'A';

	for (int i = 0; i < typed.length(); i++)
		if (typed[i] >= 'a' && typed[i] <= 'z')
			typed[i] -= 'a' - 'A';

	int i = 0, j = 0;
	for (; i < origin.length(); i++, j++)
	{
		if (origin[i] != typed[j])
		{
			if (!printed[origin[i]])
			{
				cout << origin[i];
				printed[origin[i]] = true;
			}
			j--;
		}
	}
	cout << endl;
	return 0;
}