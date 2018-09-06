#include <iostream>
#include <queue>
using namespace std;

struct node
{
	int lchild;
	int rchild;
} tree[11];

int n, root;
bool notRoot[11] = { false };

int charToNumber(char c)
{
	if (c == '-')
		return -1;
	else
		return c - '0';
}

void invertTree(int root)
{
	if (root == -1)
		return;
	int temp = tree[root].lchild;
	tree[root].lchild = tree[root].rchild;
	tree[root].rchild = temp;
	invertTree(tree[root].lchild);
	invertTree(tree[root].rchild);
}

void leverOrder(int root)
{
	queue<int> q;
	q.push(root);
	int now, num = 0;
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		if (num != 0)
			cout << " ";
		cout << now;
		num++;

		if (tree[now].lchild != -1)
			q.push(tree[now].lchild);
		if (tree[now].rchild != -1)
			q.push(tree[now].rchild);
	}
}

int printed = 0;
void inOrder(int root)
{
	if (root == -1)
		return;

	inOrder(tree[root].lchild);
	if (printed != 0)
		cout << " ";
	cout << root;
	printed++;
	inOrder(tree[root].rchild);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char l, r;
		cin >> l >> r;
		tree[i].lchild = charToNumber(l);
		tree[i].rchild = charToNumber(r);

		if (tree[i].lchild != -1)
			notRoot[tree[i].lchild] = true;
		if (tree[i].rchild != -1)
			notRoot[tree[i].rchild] = true;
	}

	for (int i = 0; i < n; i++)
	{
		if (notRoot[i] == false)
		{
			root = i;
			break;
		}
	}

	invertTree(root);
	leverOrder(root);
	cout << endl;
	inOrder(root);
	cout << endl;

	return 0;
}