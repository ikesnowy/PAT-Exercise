#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

void toArray(int a, int p[])
{
	for (int i = 0; i < 4; i++)
	{
		p[i] = a % 10;
		a /= 10;
	}
}

int toNumber(int p[])
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
		sum = sum * 10 + p[i];
	return sum;
}

int main()
{
	int n;
	scanf("%d", &n);
	int p[4];
	int Min, Max;
	do
	{
		toArray(n, p);
		sort(p, p + 4, cmp);
		Max = toNumber(p);
		
		sort(p, p + 4);
		Min = toNumber(p);
		
		n = Max - Min;
		toArray(n, p);
		
		printf("%04d - %04d = %04d\n", Max, Min, n);
		
	} while (n != 6174 && n != 0);

	return 0;
}