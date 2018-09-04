#include <cstdio>
#include <algorithm>
using namespace std;

int coins[100005];
int n;

int bSearch(int key)
{
	int lo = 0, hi = n - 1;
	while (lo <= hi)
	{
		int mid = lo + (hi - lo) / 2;
		if (coins[mid] == key)
			return mid;
		else if (coins[mid] > key)
			hi = mid - 1;
		else if (coins[mid] < key)
			lo = mid + 1;
	}

	return -1;
}

int main()
{
	int m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%d", &(coins[i]));

	sort(coins, coins + n);

	int index = -1;
	for (int i = 0; i < n; i++)
	{
		index = bSearch(m - coins[i]);
		if (index != -1 && index != i)
		{
			printf("%d %d\n", coins[i], coins[index]);
			break;
		}
	}

	if (index == -1)
		printf("No Solution\n");

	return 0;
}