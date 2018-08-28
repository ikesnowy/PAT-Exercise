#include <iostream>
#include <string>
#include <stack>
#include <set>
using namespace std;

multiset<int> s1;
multiset<int> s2;
stack<int> s;

void add(int e)
{
	if (s1.size() == s2.size())
	{
		s2.insert(e);
		s1.insert(*s2.begin());
		s2.erase(s2.begin());
	}
	else
	{
		s1.insert(e);
		s2.insert(*s1.rbegin());
		s1.erase(s1.find(*s1.rbegin()));
	}
}

void remove(int e)
{
	multiset<int>::iterator t1 = s1.find(e), t2 = s2.find(e);
	if (s2.size() == s1.size())
	{
		if (t2 != s2.end())
			s2.erase(t2);
		else
		{
			s1.erase(t1);
			s1.insert(*s2.begin());
			s2.erase(s2.begin());
		}
	}
	else if (t1 != s1.end())
	{
		s1.erase(t1);
	}
	else
	{
		s2.erase(t2);
		s2.insert(*s1.rbegin());
		s1.erase(s1.find(*s1.rbegin()));
	}
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string command;
		cin >> command;
		if (command == "Push")
		{
			int e;
			cin >> e;
			s.push(e);
			add(e);
		}
		else if (command == "Pop")
		{
			if (s.empty())
			{
				cout << "Invalid" << endl;
				continue;
			}
			cout << s.top() << endl;
			remove(s.top());
			s.pop();
		}
		else
		{
			if (s.empty())
			{
				cout << "Invalid" << endl;
				continue;
			}

			cout << *s1.rbegin() << endl;
		}
	}
	return 0;
}