#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<long> a;

	int size;
	long temp;
	scanf("%d", &size);
	while (size--)
	{
		scanf("%ld", &temp);
		a.push_back(temp);
	}
	scanf("%d", &size);
	while (size--)
	{
		scanf("%ld", &temp);
		a.push_back(temp);
	}

	sort(a.begin(), a.end());

	printf("%ld", a[(a.size() - 1) / 2]);
	
	return 0;
}