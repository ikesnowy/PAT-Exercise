#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

const int MAXN = 100005;

struct node
{
	int products;
	vector<int> childs;
}Node[MAXN];

double totalSale = 0;
int n;
double p, r;

void dfs(int root, double ratio)
{
	if (root == n)
		return;
	totalSale += Node[root].products * ratio * p;
	for (int i = 0; i < Node[root].childs.size(); i++)
		dfs(Node[root].childs[i], ratio * r);
}

int main()
{
	cin >> n >> p >> r;
	r = 1.0 + r / 100;
	for (int i = 0; i < n; i++)
	{
		int childNum = 0;
		cin >> childNum;
		if (childNum == 0)
		{
			cin >> Node[i].products;
			continue;
		}
		Node[i].products = 0;
		while (childNum--)
		{
			int child;
			cin >> child;
			Node[i].childs.push_back(child);
		}
	}

	dfs(0, 1.0);

	printf("%.1f", totalSale);
	return 0;
}