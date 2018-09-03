#include <iostream>
#include <string>
using namespace std;

struct student
{
	string name;
	string ID;
	int grade;
};

bool cmp(student a, student b)
{
	return a.grade < b.grade;
}

int main()
{
	student maleSmallest;
	student femaleLargest;

	maleSmallest.grade = 1000;
	femaleLargest.grade = -1;

	int number;
	cin >> number;
	while (number--)
	{
		student temp;
		char gender;
		cin >> temp.name >> gender >> temp.ID >> temp.grade;
		if (gender == 'M' && temp.grade < maleSmallest.grade)
			maleSmallest = temp;
		else if (gender == 'F' && temp.grade > femaleLargest.grade)
			femaleLargest = temp;
	}

	if (femaleLargest.grade == -1)
		cout << "Absent" << endl;
	else
		cout << femaleLargest.name << " " << femaleLargest.ID << endl;

	if (maleSmallest.grade == 1000)
		cout << "Absent" << endl;
	else
		cout << maleSmallest.name << " " << maleSmallest.ID << endl;

	if (maleSmallest.grade == 1000 || femaleLargest.grade == -1)
		cout << "NA" << endl;
	else
		cout << femaleLargest.grade - maleSmallest.grade << endl;

	return 0;
}