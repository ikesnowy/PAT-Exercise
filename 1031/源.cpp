#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
	node * left;
	node * right;
	int value;
};

int post_order[32];
int in_order[32];
int level_order[32];
int node_sum;
node * root;

node * creat(int postL, int postR, int inL, int inR)
{
	if (postL > postR)
		return NULL;
	node * root = new node();
	root->value = post_order[postR];
	int root_in_order = 0;
	for (int i = inL; i <= inR; i++)
	{
		if (in_order[i] == root->value)
		{
			root_in_order = i;
			break;
		}
	}
	int left_sum = root_in_order - inL;
	root->left = creat(postL, postL + left_sum - 1, inL, root_in_order - 1);
	root->right = creat(postL + left_sum, postR - 1, root_in_order + 1, inR);
	return root;
}

int level_order_traversal(node * root)
{
	queue<node*> q;
	q.push(root);
	int index = 0;
	while (!q.empty())
	{
		if (q.front() == NULL)
		{
			q.pop();
			continue;
		}
		level_order[index] = q.front()->value;
		q.push(q.front()->left);
		q.push(q.front()->right);
		q.pop();
		index++;
	}
	return index;
}

int main()
{
	cin >> node_sum;
	int i = 0;
	for (i = 0; i < node_sum; i++)
	{
		cin >> post_order[i];
	}
	for (i = 0; i < node_sum; i++)
	{
		cin >> in_order[i];
	}

	root = creat(0, node_sum - 1, 0, node_sum - 1);
	level_order_traversal(root);
	for (i = 0; i < node_sum - 1; i++)
	{
		cout << level_order[i] << " ";
	}
	cout << level_order[node_sum - 1] << endl;
	return 0;
}
