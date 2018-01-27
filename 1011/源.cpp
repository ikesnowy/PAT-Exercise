#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class student
{
public:
	string name;
	string ID;
	int grade;

	bool operator < (student other)
	{
		return grade > other.grade;
	}
};

int main()
{
	vector<student> males;
	vector<student> females;

	int total;
	cin >> total;
	while (total--)
	{
		student anonymous;
		string gender;
		cin >> anonymous.name >> gender >> anonymous.ID >> anonymous.grade;
		if (gender == "M")
		{
			males.push_back(anonymous);
		}
		else
		{
			females.push_back(anonymous);
		}
	}

	sort(males.begin(), males.end());
	sort(females.begin(), females.end());

	bool isAbsent = false;
	//first line
	if (females.size() != 0)
	{
		cout << females.begin()->name << " " << females.begin()->ID << endl;
	}
	else
	{
		cout << "Absent" << endl;
		isAbsent = true;
	}
	// second line
	if (males.size() != 0)
	{
		cout << males.rbegin()->name << " " << males.rbegin()->ID << endl;
	}
	else
	{
		cout << "Absent" << endl;
		isAbsent = true;
	}
	// third line
	if (isAbsent)
	{
		cout << "NA" << endl;
	}
	else
	{
		cout << females.begin()->grade - males.rbegin()->grade << endl;
	}

	return 0;
}