#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct node
{
	int layer;
	vector<int> child;
}family[105];

void bfs(int root)
{
	queue<int> q;
	q.push(root);
	family[root].layer = 1;
	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		for (int i = 0; i < family[top].child.size(); i++)
		{
			int child = family[top].child[i];
			family[child].layer = family[top].layer + 1;
			q.push(child);
		}
	}
}

int main()
{
	int i = 0, j = 0;
	int people_sum, people_has_child;
	cin >> people_sum >> people_has_child;
	int index, child_num;
	for (i = 0; i < people_has_child; i++)
	{
		cin >> index >> child_num;
		int child_index;
		while (child_num--)
		{
			cin >> child_index;
			family[index].child.push_back(child_index);
		}
	}

	bfs(1);
	int max_layer_sum = 1;
	int max_layer = 1;
	for (i = 1; i < 102; i++)
	{
		int temp_layer_sum = 0;
		for (j = 1; j <= people_sum; j++)
		{
			if (family[j].layer == i)
				temp_layer_sum++;
		}
		if (temp_layer_sum == 0)
			break;
		if (temp_layer_sum > max_layer_sum)
		{
			max_layer_sum = temp_layer_sum;
			max_layer = i;
		}
	}
	cout << max_layer_sum << " " << max_layer << endl;
	return 0;
}

