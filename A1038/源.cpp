#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string allStr[10005];

bool cmp(string a, string b)
{
	return a + b < b + a;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> allStr[i];
	}

	sort(allStr, allStr + n, cmp);

	string result;
	for (int i = 0; i < n; i++)
	{
		result += allStr[i];
	}

	int zeroIndex = result.find_first_not_of('0');
	if (zeroIndex == string::npos)
		result = "0";
	else
		result = result.substr(zeroIndex);

	cout << result << endl;
	return 0;
}