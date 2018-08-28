#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

int np, ng;

struct programmer
{
	int weight;
	int rank;
} players[MAXN];

bool cmp(int a, int b)
{
	return players[a].weight > players[b].weight;
}

int main()
{
	cin >> np >> ng;
	for (int i = 0; i < np; i++)
	{
		cin >> players[i].weight;
	}
	queue<int> remain;
	for (int i = 0; i < np; i++)
	{
		int playerIndex;
		cin >> playerIndex;
		remain.push(playerIndex);
	}

	while (remain.size() > 1)
	{
		int rank = (remain.size() + ng - 1) / ng;
		int n = remain.size();

		for (int i = 0; i < rank; i++)
		{
			vector<int> group;
			for (int j = 0; j < ng && n != 0; j++)
			{
				group.push_back(remain.front());
				remain.pop();
				n--;
			}
			sort(group.begin(), group.end(), cmp);
			remain.push(group[0]);
			for (int j = 1; j < group.size(); j++)
			{
				players[group[j]].rank = rank + 1;
			}
		}
	}

	players[remain.front()].rank = 1;
	for (int i = 0; i < np; i++)
	{
		if (i != 0)
			cout << " ";
		cout << players[i].rank;
	}
	cout << endl;

	return 0;
}