#include <iostream>
#include <string>
using namespace std;

struct node
{
	string name;
	string id;
} grades[101];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int g;
		string name, id;
		cin >> name >> id >> g;
		grades[g].name = name;
		grades[g].id = id;
	}

	int left, right;
	cin >> left >> right;
	bool isPrinted = false;
	for (int i = right; i >= left; i--)
	{
		if (grades[i].name.length() != 0)
		{
			cout << grades[i].name << " " << grades[i].id << endl;
			isPrinted = true;
		}
	}
	if (!isPrinted)
		cout << "NONE" << endl;

	return 0;
}
