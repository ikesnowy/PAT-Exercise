#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

struct node
{
	string ID;
	string name;
	int grade;
}nodes[100005];

bool cmp1(node a, node b)
{
	return a.ID < b.ID;
}

bool cmp2(node a, node b)
{
	if (a.name == b.name)
		return a.ID < b.ID;
	else
		return a.name < b.name;
}

bool cmp3(node a, node b)
{
	if (a.grade == b.grade)
		return a.ID < b.ID;
	else
		return a.grade < b.grade;
}

bool(*cmps[])(node, node) = { cmp1, cmp2, cmp3 };

int main()
{
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> nodes[i].ID >> nodes[i].name;
		scanf("%d", &nodes[i].grade);
	}

	sort(nodes, nodes + n, cmps[c - 1]);

	for (int i = 0; i < n; i++)
	{
		cout << nodes[i].ID << " " << nodes[i].name;
		printf(" %d\n", nodes[i].grade);
	}

	return 0;
}