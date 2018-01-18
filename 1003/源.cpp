#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student
{
public:
	string name;
	string ID;
	int grade;

	string toString()
	{
		return name + " " + ID;
	}

	bool operator < (Student other)
	{
		return grade > other.grade;
	}

	bool operator > (Student other)
	{
		return grade < other.grade;
	}
};

int main()
{
	vector<Student> students;
	int n = 0;
	cin >> n;
	while (n--)
	{
		Student temp;
		cin >> temp.name >> temp.ID >> temp.grade;
		students.push_back(temp);
	}
	int upperbound, lowerbound;
	cin >> lowerbound >> upperbound;

	sort(students.begin(), students.end());

	bool isfind = false;
	for (vector<Student>::iterator i = students.begin(); i < students.end(); i++)
	{
		if ((*i).grade >= lowerbound && (*i).grade <= upperbound)
		{
			cout << (*i).toString() << endl;
			isfind = true;
		}
	}

	if (!isfind)
	{
		cout << "NONE" << endl;
	}

	return 0;
}