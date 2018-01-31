#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class people
{
public:
	int ID;
	vector<people*> childs;
};

vector<people*> family;

people* findPeople(int ID)
{
	people * nowPeople = NULL;
	// check whether it was someone's child
	for (vector<people*>::iterator i = family.begin(); i < family.end(); i++)
	{
		if ((*i)->ID == ID)
		{
			nowPeople = *i;
		}
	}
	return nowPeople;
}

void count()
{
	vector<people*> thisLevel;
	vector<people*> nextLevel;
	nextLevel.push_back(findPeople(1));

	while (!nextLevel.empty())
	{
		int levelSum = 0;
		thisLevel.clear();
		thisLevel.assign(nextLevel.begin(), nextLevel.end());
		nextLevel.clear();

		for (vector<people*>::iterator i = thisLevel.begin(); i < thisLevel.end(); i++)
		{
			if ((*i)->childs.empty())
			{
				levelSum++;
			}
			else
			{
				nextLevel.insert(nextLevel.end(), (*i)->childs.begin(), (*i)->childs.end());
			}
		}
		cout << levelSum;
		if (!nextLevel.empty())
			cout << " ";
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int ID;
		cin >> ID;
		people * nowPeople = findPeople(ID);
		// if it is a new ID
		if (nowPeople == NULL)
		{
			nowPeople = new people();
			nowPeople->ID = ID;
			family.push_back(nowPeople);
		}

		int childrenNum = 0;
		cin >> childrenNum;
		while (childrenNum--)
		{
			int childID;
			cin >> childID;
			people * child = findPeople(childID);
			if (child == NULL)
			{
				child = new people();
				child->ID = childID;
				family.push_back(child);
			}

			nowPeople->childs.push_back(child);
		}
	}

	count();
	return 0;
}