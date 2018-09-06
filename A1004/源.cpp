#include <cstdio>
#include <vector>
using namespace std;

vector<int> family[110];
int gen[110] = { 0 };

int n, m;

int maxDepth = 1;
void dfs(int root, int depth)
{
	if (depth > maxDepth)
		maxDepth = depth;
	if (family[root].size() == 0)
		gen[depth]++;
	for (int i = 0; i < family[root].size(); i++)
		dfs(family[root][i], depth + 1);
}

int main()
{
	scanf("%d %d", &n, &m);
	int id, kids, temp;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &id, &kids);
		for (int j = 0; j < kids; j++)
		{
			scanf("%d", &temp);
			family[id].push_back(temp);
		}
	}

	dfs(1, 1);

	int sum = 0;
	for (int i = 1; i <= maxDepth; i++)
	{
		if (i != 1)
			printf(" ");
		printf("%d", gen[i]);
	}

	printf("\n");
	return 0;
}