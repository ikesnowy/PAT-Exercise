#include <cstdio>
using namespace std;

struct currency
{
	int Galleon;
	int Sickle;
	int Knut;
};

int main()
{
	currency a, b, result;
	scanf("%d.%d.%d", &a.Galleon, &a.Sickle, &a.Knut);
	scanf("%d.%d.%d", &b.Galleon, &b.Sickle, &b.Knut);
	result.Knut = a.Knut + b.Knut;
	result.Sickle = a.Sickle + b.Sickle;
	result.Galleon = a.Galleon + b.Galleon;

	while (result.Knut >= 29)
	{
		result.Knut -= 29;
		result.Sickle++;
	}

	while (result.Sickle >= 17)
	{
		result.Sickle -= 17;
		result.Galleon++;
	}

	printf("%d.%d.%d\n", result.Galleon, result.Sickle, result.Knut);
	return 0;
}