#include <cstdio>
using namespace std;

int main()
{
	int bets[10005];
	int input[100005];
	int n, t;

	scanf("%d", &n);
	for (int i = 0; i < 10005; i++)
		bets[i] = 0;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		bets[t]++;
		input[i] = t;
	}

	bool isPrinted = false;
	for (int i = 0; i < n; i++)
		if (bets[input[i]] == 1)
		{
			printf("%d\n", input[i]);
			isPrinted = true;
			break;
		}

	if (!isPrinted)
		printf("None\n");

	return 0;
}