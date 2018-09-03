#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n, l, h;

struct node
{
	string ID;
	int telent;
	int virtue;
	int total;
	int level; //0-sage, 1-nobleman, 2-foolman, 3-smallman
};

bool cmp(node a, node b)
{
	if (a.level == b.level)
	{
		if (a.total == b.total)
			if (a.virtue == b.virtue)
				return a.ID < b.ID;
			else
				return a.virtue > b.virtue;
		else
			return a.total > b.total;
	}
	else
		return a.level < b.level;
}

vector<node> nodes;

int main()
{
	cin >> n >> l >> h;
	for (int i = 0; i < n; i++)
	{
		node temp;
		cin >> temp.ID;
		scanf("%d %d", &temp.virtue, &temp.telent);
		if (temp.virtue < l || temp.telent < l)
			continue;
		else if (temp.virtue >= h && temp.telent >= h)
			temp.level = 0;
		else if (temp.virtue >= h && temp.telent < h)
			temp.level = 1;
		else if (temp.virtue >= temp.telent)
			temp.level = 2;
		else
			temp.level = 3;

		temp.total = temp.telent + temp.virtue;
		nodes.push_back(temp);
	}

	sort(nodes.begin(), nodes.end(), cmp);

	cout << nodes.size() << endl;
	for (int i = 0; i < nodes.size(); i++)
	{
		cout << nodes[i].ID;
		printf(" %d %d\n", nodes[i].virtue, nodes[i].telent);
	}
	return 0;
}