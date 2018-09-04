#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct node
{
	int id;
	int rank;
	int sum;
	int fullMarkTime;
	int problemList[7] = { 0, -2, -2, -2, -2, -2, -2 };
} nodes[10010];

int n, k, m;
int problems[8];

bool cmp(node a, node b)
{
	if (a.sum == b.sum)
		if (a.fullMarkTime == b.fullMarkTime)
			return a.id < b.id;
		else
			return a.fullMarkTime > b.fullMarkTime;
	else
		return a.sum > b.sum;
}

int main()
{
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &(problems[i]));
	}

	int userid, problemid, score;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &userid, &problemid, &score);
		if (nodes[userid].problemList[problemid] < score)
			nodes[userid].problemList[problemid] = score;
	}

	for (int i = 1; i <= n; i++)
	{
		nodes[i].id = i;
		nodes[i].sum = 0;
		nodes[i].fullMarkTime = 0;
		bool hasSubmit = false;
		for (int j = 1; j <= k; j++)
		{
			if (nodes[i].problemList[j] >= 0)
			{
				nodes[i].sum += nodes[i].problemList[j];
				hasSubmit = true;
			}

			if (nodes[i].problemList[j] == problems[j])
				nodes[i].fullMarkTime++;
		}
		if (!hasSubmit)
			nodes[i].sum = -1;
	}

	sort(nodes + 1, nodes + n + 1, cmp);

	nodes[1].rank = 1;
	for (int i = 2; i <= n; i++)
	{
		if (nodes[i].sum == nodes[i - 1].sum)
			nodes[i].rank = nodes[i - 1].rank;
		else
			nodes[i].rank = i;
	}

	for (int i = 1; i <= n; i++)
	{
		if (nodes[i].sum < 0)
			break;
		printf("%d %05d %d", nodes[i].rank, nodes[i].id, nodes[i].sum);

		for (int j = 1; j <= k; j++)
		{
			if (nodes[i].problemList[j] == -2)
				printf(" -");
			else if (nodes[i].problemList[j] == -1)
				printf(" 0");
			else
				printf(" %d", nodes[i].problemList[j]);
		}
		printf("\n");
	}

	return 0;
}