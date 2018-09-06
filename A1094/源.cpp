#include <cstdio>
#include <vector>
using namespace std;

vector<int> family[110];
int gen[110] = { 0 };

int n, m;

void dfs(int root, int depth)
{
	gen[depth]++;
	for (int i = 0; i < family[root].size(); i++)
		dfs(family[root][i], depth+1);
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

	int maxGen = 1;
	for (int i = 1; i < 110; i++)
		if (gen[i] > gen[maxGen])
			maxGen = i;

	printf("%d %d\n", gen[maxGen], maxGen);
	return 0;
}