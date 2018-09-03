#include <cstdio>
using namespace std;

int n, sum = 0;
int distance[100005];

int main()
{
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
	{
		int temp;
		scanf("%d", &temp);
		sum += temp;
		distance[i] = sum;
	}

	int query;
	scanf("%d", &query);
	while (query--)
	{
		int left, right;
		scanf("%d %d", &left, &right);
		if (left > right)
		{
			int temp = left;
			left = right;
			right = temp;
		}

		int d1 = distance[right - 1] - distance[left - 1];
		int d2 = sum - d1;
		if (d2 > d1)
			printf("%d\n", d1);
		else
			printf("%d\n", d2);
	}
	return 0;
}