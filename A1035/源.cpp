#include <iostream>
#include <string>
#include <vector>
using namespace std;

string accounts[1005];
string passwords[1005];
int N;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> accounts[i] >> passwords[i];

	vector<int> modifiedIndex;
	for (int i = 0; i < N; i++)
	{
		bool nowModified = false;
		for (int j = 0; j < passwords[i].length(); j++)
		{
			if (passwords[i][j] == '1')
			{
				passwords[i][j] = '@';
				nowModified = true;
			}
			else if (passwords[i][j] == '0')
			{
				passwords[i][j] = '%';
				nowModified = true;
			}
			else if (passwords[i][j] == 'l')
			{
				passwords[i][j] = 'L';
				nowModified = true;
			}
			else if (passwords[i][j] == 'O')
			{
				passwords[i][j] = 'o';
				nowModified = true;
			}
		}
		if (nowModified)
		{
			modifiedIndex.push_back(i);
		}
	}

	if (modifiedIndex.size() != 0)
	{
		cout << modifiedIndex.size() << endl;
		for (int i = 0; i < modifiedIndex.size(); i++)
		{
			cout << accounts[modifiedIndex[i]] << " " << passwords[modifiedIndex[i]] << endl;
		}
	}
	else
	{
		if (N == 1)
			cout << "There is 1 account and no account is modified" << endl;
		else
			cout << "There are " << N << " accounts and no account is modified" << endl;
	}

	return 0;
}