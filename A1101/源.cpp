#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int leftMax[100010];
int rightMin[100010];
int a[100010];
vector<int> pivots;
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	leftMax[0] = 0;
	for (int i = 1; i < n; i++)
		leftMax[i] = max(leftMax[i - 1], a[i - 1]);

	rightMin[n - 1] = 0x7fffffff;
	for (int i = n - 2; i >= 0; i--)
		rightMin[i] = min(rightMin[i + 1], a[i + 1]);

	for (int i = 0; i < n; i++)
		if (leftMax[i] < a[i] && a[i] < rightMin[i])
			pivots.push_back(a[i]);

	printf("%d\n", pivots.size());
	for (int i = 0; i < pivots.size(); i++)
	{
		if (i != 0)
			printf(" ");
		printf("%d", pivots[i]);
	}
	printf("\n");
	return 0;
}
