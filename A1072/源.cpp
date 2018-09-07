#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x7fffffff;
const int MAXN = 1100;

double G[MAXN][MAXN];
int houseNum, gasNum, n;
double maxRange;

double d[MAXN];
bool isVisited[MAXN] = { false };
double minDistance = 0;
double minAvg = INF;
int minGasStation = INF;

void dijkstra(int s)
{
	fill(d, d + MAXN, INF);
	fill(isVisited, isVisited + MAXN, false);
	d[s] = 0;

	for (int i = 1; i < n; i++)
	{
		int u = -1;
		double MIN = INF;
		for (int j = 1; j <= n; j++)
		{
			if (isVisited[j] == false && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1)
			return;
		isVisited[u] = true;
		for (int v = 1; v <= n; v++)
		{
			if (isVisited[v] == false && G[u][v] != INF)
			{
				if (d[u] + G[u][v] < d[v])
					d[v] = d[u] + G[u][v];
			}
		}

	}
}

int stoi(char input[])
{
	int i = 0, len = strlen(input), ID = 0;
	while (i < len)
	{
		if (input[i] != 'G')
			ID = ID * 10 + input[i] - '0';
		i++;
	}
	if (input[0] == 'G')
		return ID + houseNum;
	return ID;
}

int main()
{
	int roads;
	scanf("%d %d %d %lf", &houseNum, &gasNum, &roads, &maxRange);

	fill(G[0], G[0] + MAXN * MAXN, INF);

	char u[5], v[5];
	int x, y;
	for (int i = 0; i < roads; i++)
	{
		scanf("%s %s", &u, &v);
		x = stoi(u);
		y = stoi(v);
		scanf("%lf", &G[x][y]);
		G[y][x] = G[x][y];
	}
	n = houseNum + gasNum;
	for (int i = houseNum + 1; i <= n; i++)
	{
		dijkstra(i);
		double tempMin = INF;
		double tempAvg = 0;
		for (int j = 1; j <= houseNum; j++)
		{
			if (d[j] > maxRange)
			{
				tempMin = -1;
				break;
			}

			if (tempMin > d[j])
				tempMin = d[j];
			tempAvg += d[j];
		}
		tempAvg /= houseNum;
		if (tempMin > minDistance)
		{
			minDistance = tempMin;
			minAvg = tempAvg;
			minGasStation = i;
		}
		else if (tempMin == minDistance && tempAvg < minAvg)
		{
			minAvg = tempAvg;
			minGasStation = i;
		}
		else if (tempMin == minDistance && tempAvg == minAvg && i < minGasStation)
		{
			minGasStation = i;
		}
	}

	if (minGasStation == INF)
		printf("No Solution");
	else
	{
		printf("G%d\n", minGasStation - houseNum);
		printf("%.1lf %.1lf", minDistance, minAvg);
	}
	return 0;
}