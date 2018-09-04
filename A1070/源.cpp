#include <cstdio>
#include <algorithm>
using namespace std;
 
struct moonCake
{
	double inventory;
	double price;
	double all;
}moonCakes[1005];

bool cmp(moonCake a, moonCake b)
{
	return a.price > b.price;
}

int main()
{
	int kind;
	double demand;
	scanf("%d %lf", &kind, &demand);
	for (int i = 0; i < kind; i++)
		scanf("%lf", &moonCakes[i].inventory);
	for (int i = 0; i < kind; i++)
	{
		scanf("%lf", &moonCakes[i].all);
		moonCakes[i].price = moonCakes[i].all / moonCakes[i].inventory;
	}


	sort(moonCakes, moonCakes + kind, cmp);

	double profit = 0;
	for (int i = 0; i < kind; i++)
	{
		if (moonCakes[i].inventory < demand)
		{
			profit += moonCakes[i].all;
			demand -= moonCakes[i].inventory;
		}
		else
		{
			profit += demand * moonCakes[i].price;
			break;
		}
	}

	printf("%.2f\n", profit);
	return 0;
}