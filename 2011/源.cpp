#include <iostream>
#include <queue>
using namespace std;

struct node
{
	int index;
	int level;
};

int graph[1005][1005];
int n;

int bfs(int root, int max_level)
{
	int count = 0;
	bool visited[1002] = { false };
	queue<node> q;
	node temp;
	temp.index = root;
	temp.level = 0;
	q.push(temp);
	visited[root] = true;
	while (!q.empty())
	{
		node now = q.front();
		q.pop();
		if (now.level == max_level)
			break;
		for (int i = 1; i <= n; i++)
		{
			if (graph[now.index][i] == 1 && visited[i] == false)
			{
				node child;
				child.index = i;
				child.level = now.level + 1;
				q.push(child);
				count++;
				visited[i] = true;
			}
		}

	}
	return count;
}

int main()
{
	int l;
	cin >> n >> l;
	for (int i = 1; i <= n; i++)
	{
		int followers;
		cin >> followers;
		while (followers--)
		{
			int f;
			cin >> f;
			graph[f][i] = 1;
		}
	}

	int querys;
	cin >> querys;
	while (querys--)
	{
		int q;
		cin >> q;
		cout << bfs(q, l) << endl;
	}
	return 0;
}
