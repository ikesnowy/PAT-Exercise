#include <iostream>
using namespace std;

int graph[1001][1001];
bool isVisited[1001];

void dfs(int start, int deleted)
{
	isVisited[start] = true;
	for (int i = 1; i < 1001; i++)
	{
		if (graph[start][i] != 0 && !isVisited[i] && i != deleted)
		{
			dfs(i, deleted);
		}
	}
}

int main()
{
	int cityNum, edgeNum, queryNum;
	cin >> cityNum >> edgeNum >> queryNum;
	for (int i = 1; i < 1001; i++)
	{
		for (int j = 1; j < 1001; j++)
		{
			graph[i][j] = 0;
		}
	}
	int cityA, cityB;
	while (edgeNum--)
	{
		cin >> cityA >> cityB;
		graph[cityA][cityB] = 1;
		graph[cityB][cityA] = 1;
	}

	while (queryNum--)
	{
		// init
		for (int i = 1; i < 1001; i++)
		{
			isVisited[i] = false;
		}
		int components = 0;

		int cityDeleted;
		cin >> cityDeleted;
		for (int i = 1; i <= cityNum; i++)
		{
			if (i != cityDeleted && !isVisited[i])
			{
				components++;
				dfs(i, cityDeleted);
			}
		}

		if (components != 0)
			components--;

		cout << components << endl;
	}
	return 0;
}