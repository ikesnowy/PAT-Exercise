#include <iostream>
#include <string>
using namespace std;

string all[102];

int main()
{
	int n;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++)
	{
		getline(cin, all[i]);
	}
	string result;
	for (int i = 1; i <= all[0].length(); i++)
	{
		char check = all[0][all[0].length() - i];
		bool allSame = true;
		for (int j = 1; j < n; j++)
		{
			int realIndex = all[j].length() - i;
			if (realIndex < 0)
			{
				allSame = false;
				break;
			}
			if (all[j][realIndex] != check)
			{
				allSame = false;
				break;
			}
		}
		if (allSame)
			result = check + result;
		else
			break;
	}

	if (result.length() == 0)
		cout << "nai" << endl;
	else
		cout << result << endl;
	return 0;
}