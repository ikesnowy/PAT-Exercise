#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
	int weight;
	vector<int> childs;
} tree[110];

vector<int> path;
int n, m, s;


bool cmp(int a, int b)
{
	return tree[a].weight > tree[b].weight;
}

void printPath()
{
	for (int i = 0; i < path.size(); i++)
	{
		if (i != 0)
			printf(" ");
		printf("%d", path[i]);
	}
	printf("\n");
}

void dfs(int root, int sum)
{
	if (sum + tree[root].weight > s)
		return;
	path.push_back(tree[root].weight);
	if (sum + tree[root].weight == s && tree[root].childs.size() == 0)
	{
		printPath();
		path.pop_back();
		return;
	}

	for (int i = 0; i < tree[root].childs.size(); i++)
		dfs(tree[root].childs[i], sum + tree[root].weight);
	path.pop_back();
	return;
}

int main()
{
	scanf("%d %d %d", &n, &m, &s);
	for (int i = 0; i < n; i++)
		scanf("%d", &tree[i].weight);

	int id, kids, temp;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &id, &kids);
		for (int j = 0; j < kids; j++)
		{
			scanf("%d", &temp);
			tree[id].childs.push_back(temp);
		}
		sort(tree[id].childs.begin(), tree[id].childs.end(), cmp);
	}

	dfs(0, 0);

	return 0;
}