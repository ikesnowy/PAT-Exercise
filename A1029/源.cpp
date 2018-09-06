#include <cstdio>
#include <vector>
using namespace std;

int s[200005];
int n1, n2;

int main()
{
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++)
		scanf("%d", &s[i]);

	s[n1] = 0x7fffffff;
	scanf("%d", &n2);
	int right = (n1 + n2 + 1) / 2;
	int count = 0;
	int p = 0;
	for (int i = 0; i < n2; i++)
	{
		int temp;
		scanf("%d", &temp);

		while (s[p] < temp)
		{
			count++;
			if (count == right)
				printf("%d\n", s[p]);
			p++;
		}
		count++;
		if (count == right)
			printf("%d\n", temp);
	}

	while (p < n1)
	{
		count++;
		if (count == right)
			printf("%d\n", s[p]);
		p++;
	}
	return 0;
}