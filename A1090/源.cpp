#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

struct node
{
	vector<int> childs;
} chain[100010];

double basePrice, rate;
int n;

double maxDepth = 0;
int maxNodes = 0;
void dfs(int root, double depth)
{
	if (depth == maxDepth)
	{
		maxNodes++;
	}
	else if (depth > maxDepth)
	{
		maxDepth = depth;
		maxNodes = 1;
	}

	for (int i = 0; i < chain[root].childs.size(); i++)
		dfs(chain[root].childs[i], depth + 1);
}

int main()
{
	scanf("%d %lf %lf", &n, &basePrice, &rate);
	rate = 1 + rate / 100.0;
	int before, root;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &before);
		if (before == -1)
		{
			root = i;
			continue;
		}
		chain[before].childs.push_back(i);
	}

	dfs(root, 0);
	printf("%.2lf %d\n", pow(rate, maxDepth) * basePrice, maxNodes);

	return 0;
}