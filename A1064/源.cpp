#include <cstdio>
#include <algorithm>
using namespace std;

int tree[1010];
int numbers[1010];

int index = 0, n;
void inOrder(int root)
{
	if (root > n)
		return;
	inOrder(root * 2);
	tree[root] = numbers[index++];
	inOrder(root * 2 + 1);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &numbers[i]);
	sort(numbers, numbers + n);
	inOrder(1);
	for (int i = 1; i <= n; i++)
	{
		if (i != 1)
			printf(" ");
		printf("%d", tree[i]);
	}
	printf("\n");
	return 0;
}