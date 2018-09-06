#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct node
{
	char name[15];
	int wealth;
	int age;
};

bool cmp(node * a, node * b)
{
	if (a->wealth == b->wealth)
		if (a->age == b->age)
			return strcmp(a->name, b->name) < 0;
		else
			return a->age < b->age;
	else
		return a->wealth > b->wealth;
}

node * total[100010];
node * valid[100010];
int validNum = 0;
int age[202];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		node * temp = new node();
		scanf("%s %d %d", temp->name, &(temp->age), &(temp->wealth));
		total[i] = temp;
	}

	sort(total, total + n, cmp);

	for (int i = 0; i < n; i++)
	{
		if (age[total[i]->age] < 100)
			valid[validNum++] = total[i];
	}

	int m, left, right;
	for (int j = 0; j < k; j++)
	{
		scanf("%d %d %d", &m, &left, &right);
		printf("Case #%d:\n", j + 1);
		int printed = 0;
		for (int i = 0; i < validNum && printed < m; i++)
		{
			if (valid[i]->age >= left && valid[i]->age <= right)
			{
				printf("%s %d %d\n", valid[i]->name, valid[i]->age, valid[i]->wealth);
				printed++;
			}
		}

		if (printed == 0)
			printf("None\n");
	}

	return 0;
}