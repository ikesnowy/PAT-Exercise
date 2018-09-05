#include <cstdio>
#include <algorithm>
using namespace std;

int products[100010];
int coupons[100010];
int n, m;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &coupons[i]);

	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &products[i]);

	sort(coupons, coupons + n);
	sort(products, products + m);

	int totalMoney = 0;
	int p = 0, q = 0;
	while (coupons[p] < 0 && products[q] < 0 && p < n && q < m)
		totalMoney += coupons[p++] * products[q++];
	
	p = n - 1;
	q = m - 1;
	while (coupons[p] > 0 && products[q] > 0 && p >= 0 && q >= 0)
		totalMoney += coupons[p--] * products[q--];

	printf("%d\n", totalMoney);

	return 0;
}