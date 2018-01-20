#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main()
{
	stack<pair<int, bool> > s;
	vector<int> post;
	int commandNum = 0;
	cin >> commandNum;
	commandNum *= 2;

	string command;
	int parameter = 0;
	string result;

	while (commandNum--)
	{
		cin >> command;
		if (command == "Push")
		{
			cin >> parameter;
			s.push(make_pair(parameter, false));
		}
		else
		{
			if (s.top().second == false)
			{
				s.top().second = true;
			}
			else
			{
				while (s.top().second == true)
				{
					post.push_back(s.top().first);
					s.pop();
				}
				s.top().second = true;
			}
		}
	}
	
	while (!s.empty())
	{
		post.push_back(s.top().first);
		s.pop();
	}

	cout << *(post.begin());
	for (vector<int>::iterator i = post.begin() + 1; i < post.end(); i++)
	{
		cout << " " << *i;
	}

	return 0;
}