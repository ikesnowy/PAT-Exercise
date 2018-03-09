#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

unordered_map<string, set<string> > dictionary[5];

void keyword_login(string full, string id)
{
	// split
	int start = 0;
	for (int i = 0; i < (int)full.length(); i++)
	{
		if (full[i] == ' ')
		{
			dictionary[2][full.substr(start, i - start)].insert(id);
			start = i + 1;
		}
	}
	dictionary[2][full.substr(start, full.length() - start)].insert(id);
}

int main()
{
	int book_num;
	cin >> book_num;
	int i = 0;
	string id;
	string temp;
	for (i = 0; i < book_num; i++)
	{
		cin >> id;
		getline(cin, temp);
		getline(cin, temp);
		dictionary[0][temp].insert(id);
		getline(cin, temp);
		dictionary[1][temp].insert(id);
		getline(cin, temp);
		keyword_login(temp, id);
		getline(cin, temp);
		dictionary[3][temp].insert(id);
		getline(cin, temp);
		dictionary[4][temp].insert(id);
	}

	int query = 0;
	cin >> query;
	set<int> result;
	string key;
	int item;
	while (query--)
	{
		scanf("%d: ", &item);
		getline(cin, key);
		cout << item << ": " << key << endl;
		item--;
		if (dictionary[item].find(key) == dictionary[item].end())
		{
			cout << "Not Found" << endl;
		}
		else
		{
			set<string>::iterator it;
			for (it = dictionary[item][key].begin(); it != dictionary[item][key].end(); it++)
			{
				cout << *(it) << endl;
			}
		}
		result.clear();
	}
	return 0;
}