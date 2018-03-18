#include <iostream>
#include <string>
using namespace std;

string reverse(string s)
{
	string r;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		r += s[i];
	}
	return r;
}

int main()
{
	int n;
	cin >> n;
	string origin;
	getline(cin, origin);
	getline(cin, origin);
	n--;
	origin = reverse(origin);
	string comp;
	getline(cin, comp);
	n--;
	comp = reverse(comp);
	int common_length = 0;
	for (int i = 0; i < comp.length() && i < origin.length(); i++)
	{
		if (comp[i] == origin[i])
			common_length++;
		else
			break;
	}

	while (n--)
	{
		getline(cin, comp);
		comp = reverse(comp);
		for (int i = 0; i < common_length; i++)
		{
			if (comp[i] != origin[i])
			{
				common_length = i;
				break;
			}
		}
	}

	if (common_length == 0)
	{
		cout << "nai" << endl;
		return 0;
	}

	string result = origin.substr(0, common_length);
	result = reverse(result);
	cout << result << endl;
	return 0;
}