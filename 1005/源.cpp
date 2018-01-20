#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<long> picture;
	int max = 0;
	long dominant = 0;

	int m, n, t;
	long temp;
	scanf("%d %d", &m, &n);
	while (n--)
	{
		t = m;
		while (t--)
		{
			scanf("%ld", &temp);
			picture.push_back(temp);
		}
	}

	sort(picture.begin(), picture.end());

	for (vector<long>::iterator i = picture.begin() + 1; i < picture.end(); i++)
	{
		if (*i == *(i - 1))
		{
			int counter = 2;
			i++;
			while (*i == *(i - 1))
			{
				counter++;
				i++;
			}

			if (counter > max)
			{
				max = counter;
				dominant = *(i - 1);
			}
		}
	}

	printf("%ld", dominant);
	return 0;
}