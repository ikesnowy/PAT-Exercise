#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class student
{
public:
	int ID;
	string name;
	int grade;
};

bool asycendingID(student a, student b)
{
	return a.ID < b.ID;
}

bool asycendingName(student a, student b)
{
	if (a.name != b.name)
	{
		return a.name < b.name;
	}
	else
	{
		return a.ID < b.ID;
	}
}

bool asycendingGrade(student a, student b)
{
	if (a.grade != b.grade)
	{
		return a.grade < b.grade;
	}
	else
	{
		return a.ID < b.ID;
	}
}

int main()
{
	vector<student> list;
	int N, C;
	cin >> N >> C;
	while (N--)
	{
		student s;
		cin >> s.ID >> s.name >> s.grade;
		list.push_back(s);
	}

	if (C == 1)
	{
		sort(list.begin(), list.end(), asycendingID);
	}
	else if (C == 2)
	{
		sort(list.begin(), list.end(), asycendingName);
	}
	else if (C == 3)
	{
		sort(list.begin(), list.end(), asycendingGrade);
	}

	for (vector<student>::iterator i = list.begin(); i < list.end(); i++)
	{
		cout << setw(6) << setfill('0');
		cout << (*i).ID << " " << (*i).name << " ";
		cout << setw(1);
		cout << (*i).grade << endl;
	}
	return 0;
}