#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int N = s.length();
	int n1 = (s.length() + 2) / 3;
	int n3 = n1;
	int n2 = s.length() + 2 - 2 * n1;

	for (int i = 0; i < n1 - 1; i++)
	{
		cout << s[i];
		for (int j = 0; j < n2 - 2; j++)
		{
			cout << " ";
		}
		cout << s[s.length() - i - 1] << endl;
	}

	for (int i = 0; i < n2; i++)
	{
		cout << s[n1 - 1 + i];
	}
	cout << endl;
	return 0;
}