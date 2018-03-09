#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> graph[10003];
bool visited[10003] = { false };

set<int> temp;
int max_depth = 0;
int node_num;

void dfs(int v, int depth)
{
	int i = 0;
	visited[v] = true;

	if (depth > max_depth)
	{
		max_depth = depth;
		temp.clear();
		temp.insert(v);
	}
	else if (depth == max_depth)
	{
		temp.insert(v);
	}

	for (i = 0; i < (int)graph[v].size(); i++)
	{
		if (visited[graph[v][i]] != true)
		{
			dfs(graph[v][i], depth + 1);
		}
	}
}

int dfs_graph()
{
	int components = 0;
	for (int u = 0; u < node_num; u++)
	{
		if (visited[u] == false)
		{
			dfs(u, 0);
			components++;
		}
	}
	return components;
}

int main()
{
	set<int> total;
	cin >> node_num;
	int i = 0, j = 0;
	int A, B;

	for (i = 0; i < node_num - 1; i++)
	{
		cin >> A >> B;
		graph[A - 1].push_back(B - 1);
		graph[B - 1].push_back(A - 1);
	}

	int components_sum = dfs_graph();
	if (components_sum > 1)
		cout << "Error: " << components_sum << " components" << endl;
	else
	{
		for (i = 0; i < node_num; i++)
		{
			visited[i] = false;
		}

		total.insert(temp.begin(), temp.end());
		max_depth = 0;
		temp.clear();
		dfs(*total.begin(), 0);
		total.insert(temp.begin(), temp.end());

		set<int>::iterator it = total.begin();
		for (it = total.begin(); it != total.end(); it++)
		{
			cout << *(it) + 1 << endl;
		}
	}
	return 0;
}