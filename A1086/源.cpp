#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

struct node
{
	int data;
	node * left;
	node * right;
} * root;

vector<int> preOrder;
vector<int> inOrder;
vector<int> postOrder;

node * buildTree(int preL, int preR, int inL, int inR)
{
	if (preL > preR)
		return nullptr;
	node * root = new node();
	root->data = preOrder[preL];
	int k = -1;
	for (k = inL; k <= inR; k++)
		if (inOrder[k] == preOrder[preL])
			break;
	int numberLeft = k - inL;
	root->left = buildTree(preL + 1, preL + numberLeft, inL, k - 1);
	root->right = buildTree(preL + numberLeft + 1, preR, k + 1, inR);
	return root;
}

void postOrderTraversal(node * root)
{
	if (root == nullptr)
		return;
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	postOrder.push_back(root->data);
}

int main()
{
	stack<int> s;
	int n;
	char order[5];
	int data;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++)
	{
		scanf("%s", order);
		if (strcmp(order, "Push") == 0)
		{
			scanf("%d", &data);
			preOrder.push_back(data);
			s.push(data);
		}
		else
		{
			inOrder.push_back(s.top());
			s.pop();
		}
	}

	root = buildTree(0, n - 1, 0, n - 1);
	postOrderTraversal(root);

	printf("%d", postOrder[0]);
	for (int i = 1; i < n; i++)
		printf(" %d", postOrder[i]);
	printf("\n");
	return 0;
}