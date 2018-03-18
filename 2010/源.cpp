#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
	int value;
	int left;
	int right;
};

int n;
vector<int> values;
vector<node> bst;

int index = 0;
void inorder(int now)
{
	if (bst[now].left != -1)
		inorder(bst[now].left);
	bst[now].value = values[index];
	index++;
	if (bst[now].right != -1)
		inorder(bst[now].right);
}

void bfs(int root)
{
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (bst[now].left != -1)
			q.push(bst[now].left);
		if (bst[now].right != -1)
			q.push(bst[now].right);
		cout << bst[now].value;
		if (!q.empty())
			cout << " ";
	}
	cout << endl;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		node temp;
		cin >> temp.left >> temp.right;
		bst.push_back(temp);
	}

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		values.push_back(temp);
	}

	sort(values.begin(), values.end());
	inorder(0);
	bfs(0);
	return 0;
}