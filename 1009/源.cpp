#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int inf = 9999999;

int distGraph[500][500];
int costGraph[500][500];
int dist[500];
int cost[500];
int pre[500];

void printPath(int startCity, int endCity)
{
	if (startCity != endCity)
	{
		printPath(startCity, pre[endCity]);
	}

	cout << endCity << " ";
}

void dijkstra(int startCity, int cityNumber)
{
	bool isVisited[500];
	// init SSSP
	for (int i = 0; i < 500; i++)
	{
		dist[i] = inf;
		cost[i] = inf;
		pre[i] = i;
		isVisited[i] = false;
	}

	dist[startCity] = 0;
	cost[startCity] = 0;
	
	for (int j = 0; j < cityNumber; j++)
	{
		int k = -1;
		for (int i = 0; i < cityNumber; i++)
		{
			if (!isVisited[i] && (k < 0 || dist[i] < dist[k]))
			{
				k = i;
			}
		}

		isVisited[k] = true;

		for (int i = 0; i < cityNumber; i++)
		{
			if (!isVisited[i] && distGraph[k][i] != -1)
			{
				int tempDist = dist[k] + distGraph[k][i];
				int tempCost = cost[k] + costGraph[k][i];
				if (tempDist < dist[i] ||
					(tempDist == dist[i] && tempCost < cost[i]))
				{
					pre[i] = k;
					dist[i] = tempDist;
					cost[i] = tempCost;
				}
			}
		}
	}
}

int main()
{
	int cityNumber, edgeNumber, startCity, endCity;
	cin >> cityNumber >> edgeNumber >> startCity >> endCity;

	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			distGraph[i][j] = inf;
			costGraph[i][j] = inf;
		}
	}

	int x, y, distance, travelCost;
	while (edgeNumber--)
	{
		cin >> x >> y >> distance >> travelCost;
		distGraph[x][y] = distance;
		distGraph[y][x] = distance;
		costGraph[x][y] = travelCost;
		costGraph[y][x] = travelCost;
	}
	
	dijkstra(startCity, cityNumber);
	printPath(startCity, endCity);
	cout << dist[endCity] << " " << cost[endCity] << endl;
	return 0;
}