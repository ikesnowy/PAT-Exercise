#include <cstdio>
#include <algorithm>
using namespace std;

int a[100010];
int n, p;


int main()
{
	scanf("%d %d", &n, &p);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int result = 1;
	for (int i = 0; i < n; i++)
	{
		int j = upper_bound(a + i + 1, a + n, (long long)a[i] * p) - a;
		result = max(result, j - i);
	}

	printf("%d\n", result);
	return 0;
}