#include <cstdio>
#include <vector>
using namespace std;

struct node
{
	int data;
	node * left;
	node * right;
} * root = nullptr, * rootMirror = nullptr;

vector<int> original;
vector<int> preOrder;
vector<int> preOrderMirror;
vector<int> postOrder;

void insert(int t, node * &root)
{
	if (root == nullptr)
	{
		root = new node();
		root->data = t;
		root->left = nullptr;
		root->right = nullptr;
		return;
	}
	
	if (root->data > t)
		insert(t, root->left);
	else
		insert(t, root->right);
}

void preOrderTraversal(node * root)
{
	if (root == nullptr)
		return;
	preOrder.push_back(root->data);
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void preOrderTraversalMirror(node * root)
{
	if (root == nullptr)
		return;
	preOrderMirror.push_back(root->data);
	preOrderTraversalMirror(root->right);
	preOrderTraversalMirror(root->left);
}

void postOrderTraversal(node * root)
{
	if (root == nullptr)
		return;
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	postOrder.push_back(root->data);
}

void postOrderTraversalMirror(node * root)
{
	if (root == nullptr)
		return;
	postOrderTraversalMirror(root->right);
	postOrderTraversalMirror(root->left);
	postOrder.push_back(root->data);
}

int main()
{
	int n, t;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		original.push_back(t);
		insert(t, root);
	}

	preOrderTraversal(root);
	preOrderTraversalMirror(root);
	if (preOrder == original)
	{
		printf("YES\n");
		postOrderTraversal(root);
		for (int i = 0; i < n; i++)
		{
			if (i != 0)
				printf(" ");
			printf("%d", postOrder[i]);
		}
	}
	else if (preOrderMirror == original)
	{
		printf("YES\n");
		postOrderTraversalMirror(root);
		for (int i = 0; i < n; i++)
		{
			if (i != 0)
				printf(" ");
			printf("%d", postOrder[i]);
		}
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}