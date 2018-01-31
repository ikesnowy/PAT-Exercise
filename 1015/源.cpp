#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int inf = 999999;
const int MAX = 510;

int distGraph[510][510];
bool visited[510];
int people[510];

int dist[510];
int SSSPNum[510];
int weight[510];

void Dijkstra(int start, int cityNum)
{
	// Init SSSP
	for (int i = 0; i < MAX; i++)
	{
		dist[i] = inf;
		visited[i] = false;
		SSSPNum[i] = 0;
		weight[i] = 0;
	}
	weight[start] = people[start];
	dist[start] = 0;
	SSSPNum[start] = 1;

	for (int i = 0; i < cityNum; i++)
	{
		int u = -1, MIN = inf;
		for (int j = 0; j < cityNum; j++)
		{
			if (dist[j] < MIN && !visited[j])
			{
				u = j;
				MIN = dist[j];
			}
		}
		if (u == -1)
			return;

		visited[u] = true;
		for (int v = 0; v < cityNum; v++)
		{
			if (!visited[v] && distGraph[u][v] != inf)
			{
				if (dist[u] + distGraph[u][v] == dist[v])
				{
					// max people
					if (weight[u] + people[v] > weight[v])
						weight[v] = weight[u] + people[v];
					// update SSSP number
					SSSPNum[v] += SSSPNum[u];
				}
				else if (dist[u] + distGraph[u][v] < dist[v])
				{
					// update the SSSP length
					dist[v] = dist[u] + distGraph[u][v];
					weight[v] = weight[u] + people[v];
					SSSPNum[v] = SSSPNum[u];
				}
			}
		}
	}
}

int main()
{
	int cityNum = 0;
	int edgeNum = 0;
	int startCity = 0;
	int endCity = 0;
	cin >> cityNum >> edgeNum >> startCity >> endCity;

	for (int i = 0; i < cityNum; i++)
	{
		cin >> people[i];
	}

	// Init dist graph
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			distGraph[i][j] = inf;
		}
	}

	for (int i = 0; i < edgeNum; i++)
	{
		int start, end, length;
		cin >> start >> end >> length;
		distGraph[start][end] = length;
		distGraph[end][start] = length;
	}

	Dijkstra(startCity, cityNum);
	cout << SSSPNum[endCity] << " " << weight[endCity] << endl;
	return 0;
}