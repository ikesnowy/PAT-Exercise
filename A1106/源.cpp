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

double minDepth = 100010;
int minNodes = 0;
void dfs(int root, double depth)
{
	if (chain[root].childs.size() == 0)
	{
		if (depth < minDepth)
		{
			minDepth = depth;
			minNodes = 1;
		}
		else if (depth == minDepth)
		{
			minNodes++;
		}

		return;
	}
	for (int i = 0; i < chain[root].childs.size(); i++)
		dfs(chain[root].childs[i], depth + 1);
}

int main()
{
	scanf("%d %lf %lf", &n, &basePrice, &rate);
	rate = 1 + rate / 100.0;
	int after, kid;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &after);
		for (int j = 0; j < after; j++)
		{
			scanf("%d", &kid);
			chain[i].childs.push_back(kid);
		}
	}

	dfs(0, 0);
	printf("%.4lf %d\n", pow(rate, minDepth) * basePrice, minNodes);

	return 0;
}