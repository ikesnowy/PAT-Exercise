#include <cstdio>
using namespace std;

int target, n;
int sum[100010];

int upper_bound(int left, int right, int x)
{
	int lo = left, hi = right;
	int mid;
	while (lo < hi)
	{
		mid = lo + (hi - lo) / 2;
		if (sum[mid] > x)
			hi = mid;
		else
			lo = mid + 1;
	}

	return lo;
}

int main()
{
	int nearestS = 100000010;
	scanf("%d %d", &n, &target);
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &sum[i]);
	for (int i = 2; i <= n; i++)
		sum[i] += sum[i - 1];

	for (int i = 1; i <= n; i++)
	{
		int j = upper_bound(i, n + 1, sum[i - 1] + target);
		if (sum[j - 1] - sum[i - 1] == target)
		{
			nearestS = target;
			break;
		}
		else if (j <= n && sum[j] - sum[i - 1] < nearestS)
			nearestS = sum[j] - sum[i - 1];
	}

	for (int i = 1; i <= n; i++)
	{
		int j = upper_bound(i, n + 1, sum[i - 1] + nearestS);
		if (sum[j - 1] - sum[i - 1] == nearestS)
			printf("%d-%d\n", i, j - 1);
	}

	return 0;
}