#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<string> usernames;
	vector<string> passwords;
	vector<int> modified;
	int total = 0;
	cin >> total;
	while (total--)
	{
		string username;
		string password;
		cin >> username >> password;

		usernames.push_back(username);
		bool isModified = false;
		for (string::iterator i = password.begin(); i < password.end(); i++)
		{
			if (*i == '0')
			{
				*i = '%';
				isModified = true;
			}
			else if (*i == '1')
			{
				*i = '@';
				isModified = true;
			}
			else if (*i == 'l')
			{
				*i = 'L';
				isModified = true;
			}
			else if (*i == 'O')
			{
				*i = 'o';
				isModified = true;
			}
		}

		if (isModified)
			modified.push_back(usernames.size() - 1);
		passwords.push_back(password);
	}

	if (modified.size() == 0)
	{
		if (usernames.size() == 1)
		{
			cout << "There is " << usernames.size() << " account and no account is modified";
		}
		else
		{
			cout << "There are " << usernames.size() << " accounts and no account is modified";
		}
		return 0;
	}

	cout << modified.size() << endl;
	for (int i = 0; i < modified.size(); i++)
	{
		cout << usernames.at(modified.at(i)) << " " << passwords.at(modified.at(i)) << endl;
	}
	return 0;
}