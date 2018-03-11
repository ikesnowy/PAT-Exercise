#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int INF = 9999999;

int visited[505] = { false };
int graph[505][505];
int dist[505];
int bikes[505];
vector<int> pre[505];

int n;

void dijkstra(int source)
{
	int i = 0, j = 0;

	for (i = 0; i < n; i++)
	{
		dist[i] = INF;
	}
	dist[source] = 0;

	for (i = 0; i < n; i++)
	{
		int u = -1, min = INF;
		for (j = 0; j < n; j++)
		{
			if (dist[j] < min && visited[j] == false)
			{
				u = j;
				min = dist[j];
			}
		}
		if (u == -1)
			return;
		visited[u] = true;
		for (int v = 0; v < n; v++)
		{
			if (visited[v] == false && graph[u][v] != INF)
			{
				if (dist[u] + graph[u][v] < dist[v])
				{
					dist[v] = dist[u] + graph[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (dist[u] + graph[u][v] == dist[v])
				{
					pre[v].push_back(u);
				}
			}
		}
	}
}

int start = 0;
int best_bike_in = INF;
int best_bike_out = INF;
int capacity;
vector<int> path, temp_path;

void dfs(int v)
{
	int i;
	if (v == start)
	{
		temp_path.push_back(v);
		int value_in = 0;
		int value_out = 0;
		for (i = 0; i < temp_path.size(); i++)
		{
			if (bikes[temp_path[i]] > capacity / 2)
			{
				value_in -= bikes[temp_path[i]] - capacity / 2;
				if (value_in < 0)
				{
					value_out -= value_in;
					value_in = 0;
				}
			}
			else
			{
				value_in += capacity / 2 - bikes[temp_path[i]];
			}
		}
		if (value_in < best_bike_in || ((value_in == best_bike_in) && (value_out < best_bike_out)))
		{
			path = temp_path;
			best_bike_in = value_in;
			best_bike_out = value_out;
		}
		temp_path.pop_back();
		return;
	}

	temp_path.push_back(v);
	for (i = 0; i < pre[v].size(); i++)
	{
		dfs(pre[v][i]);
	}

	temp_path.pop_back();
}

int main()
{
	int i, j;
	int query, roads;

	cin >> capacity >> n >> query >> roads;
	bikes[0] = capacity / 2;
	n++;
	for (i = 1; i < n; i++)
	{
		cin >> bikes[i];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			graph[i][j] = INF;
			graph[j][i] = INF;
		}
	}

	int a, b, length;
	for (i = 0; i < roads; i++)
	{
		cin >> a >> b >> length;
		graph[a][b] = length;
		graph[b][a] = length;
	}

	dijkstra(0);
	dfs(query);
	cout << best_bike_in << " ";
	for (i = path.size() - 1; i > 0; i--)
	{
		cout << path[i] << "->";
	}
	cout << path[0] << " ";
	cout << best_bike_out << endl;
	return 0;
}
