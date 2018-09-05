#include <cstdio>
#include <algorithm>
using namespace std;

struct gasStation
{
	double distance;
	double price;
} stations[502];

bool cmp(gasStation a, gasStation b)
{
	return a.distance < b.distance;
}

double tankCapacity = 0;
double totalLength = 0;
double distancePerUnit = 0;
int stationNumber = 0;

int main()
{
	scanf("%lf %lf %lf %d", &tankCapacity, &totalLength, &distancePerUnit, &stationNumber);
	for (int i = 0; i < stationNumber; i++)
	{
		scanf("%lf %lf", &stations[i].price, &stations[i].distance);
	}

	stations[stationNumber].price = 0;
	stations[stationNumber].distance = totalLength;

	sort(stations, stations + stationNumber, cmp);

	if (stations[0].distance != 0)
	{
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}

	int now = 0;
	double totalCost = 0, gasRemain = 0, maxDistance = tankCapacity * distancePerUnit;
	while (now < stationNumber)
	{
		int k = -1;
		double priceMin = 1000000000;
		for (int i = now + 1; i <= stationNumber && stations[i].distance - stations[now].distance <= maxDistance; i++)
		{
			if (stations[i].price < priceMin)
			{
				priceMin = stations[i].price;
				k = i;
				if (priceMin < stations[now].price)
					break;
			}
		}

		if (k == -1)
			break;
		double gasNeed = (stations[k].distance - stations[now].distance) / distancePerUnit;
		if (priceMin < stations[now].price)
		{
			if (gasRemain < gasNeed)
			{
				totalCost += (gasNeed - gasRemain) * stations[now].price;
				gasRemain = 0;
			}
			else
			{
				gasRemain -= gasNeed;
			}
		}
		else
		{
			totalCost += (tankCapacity - gasRemain) * stations[now].price;
			gasRemain = tankCapacity - gasNeed;
		}

		now = k;
	}

	if (now == stationNumber)
		printf("%.2f", totalCost);
	else
		printf("The maximum travel distance = %.2f\n", stations[now].distance + maxDistance);

	return 0;
}