#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

const int INF = 99999999;

int n;

string startCity;
map<string, int> citynames;
string cityID[205];
int graph[205][205];
int happiness[205];

int num[205];
int dist[205];
bool visited[205];
int dist_happiness[205];
int bypass[205];
int pre[205];

void dijkstra(int source)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		dist[i] = INF;
		visited[i] = false;
		bypass[i] = 0;
		dist_happiness[i] = 0;
		num[i] = 0;
	}
	num[source] = 1;
	dist[source] = 0;
	for (i = 0; i < n; i++)
	{
		int min = INF, u = -1;
		for (j = 0; j < n; j++)
		{
			if (visited[j] == false && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		}
		if (u == -1)
			return;
		visited[u] = true;
		for (j = 0; j < n; j++)
		{
			if (visited[j] == false && graph[u][j] != INF)
			{
				if (graph[u][j] + dist[u] < dist[j])
				{
					num[j] = num[u];
					dist[j] = graph[u][j] + dist[u];
					pre[j] = u;
					bypass[j] = bypass[u] + 1;
					dist_happiness[j] = happiness[j] + dist_happiness[u];
				}
				else if (graph[u][j] + dist[u] == dist[j])
				{
					num[j] += num[u];
					if (dist_happiness[u] + happiness[j] > dist_happiness[j])
					{
						dist[j] = graph[u][j] + dist[u];
						pre[j] = u;
						bypass[j] = bypass[u] + 1;
						dist_happiness[j] = happiness[j] + dist_happiness[u];
					}
					else if (dist_happiness[u] + happiness[j] == dist_happiness[j])
					{
						if (bypass[u] + 1 < bypass[j])
						{
							dist[j] = graph[u][j] + dist[u];
							pre[j] = u;
							bypass[j] = bypass[u] + 1;
							dist_happiness[j] = happiness[j] + dist_happiness[u];
						}
					}
				}
			}
		}
	}
}

void print(int s)
{
	if (s == 0)
	{
		cout << cityID[s] << "->";
		return;
	}
	print(pre[s]);
	cout << cityID[s] << "->";
}

int main()
{
	int i = 0, j = 0;
	int edgeNum;
	cin >> n >> edgeNum >> startCity;
	string tempCity;
	citynames[startCity] = 0;
	happiness[0] = 0;
	cityID[0] = startCity;
	for (i = 1; i < n; i++)
	{
		cin >> tempCity >> happiness[i];
		citynames[tempCity] = i;
		cityID[i] = tempCity;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			graph[i][j] = INF;
		}
	}

	string edgeA, edgeB;
	while (edgeNum--)
	{
		cin >> edgeA >> edgeB;
		int a = citynames[edgeA];
		int b = citynames[edgeB];
		cin >> graph[a][b];
		graph[b][a] = graph[a][b];
	}

	dijkstra(0);

	cout << num[citynames["ROM"]] << " ";
	cout << dist[citynames["ROM"]] << " ";
	cout << dist_happiness[citynames["ROM"]] << " " << dist_happiness[citynames["ROM"]] / bypass[citynames["ROM"]] << endl;
	print(pre[citynames["ROM"]]);
	cout << "ROM" << endl;
	return 0;
}