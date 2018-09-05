#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, lUnsorted = 100005;
	int a[100005];
	scanf("%d", &n);
	int remain = n - 1;
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		a[num] = i;
		if (num == i && num != 0)
			remain--;
	}

	int k = 1, totalSwap = 0;
	while (remain > 0)
	{
		if (a[0] == 0)
		{
			while (k < n)
			{
				if (a[k] != k)
				{
					swap(a[0], a[k]);
					totalSwap++;
					break;
				}
				k++;
			}
		}

		while (a[0] != 0)
		{
			swap(a[0], a[a[0]]);
			totalSwap++;
			remain--;
		}
	}

	printf("%d\n", totalSwap);
	return 0;
}