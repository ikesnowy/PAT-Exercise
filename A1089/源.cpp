#include <cstdio>
#include <algorithm>
using namespace std;

int origin[105];
int middle[105];
int changed[105];
int n;

bool isSame()
{
	for (int i = 0; i < n; i++)
		if (middle[i] != changed[i])
			return false;
	return true;
}

bool insertionSort()
{
	bool flag = false;
	for (int i = 1; i < n; i++)
	{
		if (isSame() && i != 1)
		{
			flag = true;
		}
		for (int j = i; j > 0 && changed[j] < changed[j - 1]; j--)
			swap(changed[j], changed[j - 1]);
		
		if (flag)
			break;
	}

	return flag;
}

bool mergeSort()
{
	bool flag = false;
	for (int step = 2; step / 2 <= n; step *= 2)
	{
		if (isSame() && step != 2)
		{
			flag = true;
		}
		for (int i = 0; i < n; i += step)
			sort(changed + i, changed + min(n, i + step));
		if (flag)
			break;
	}
	return flag;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &origin[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &middle[i]);

	// insertionSort
	for (int i = 0; i < n; i++)
		changed[i] = origin[i];
	if (insertionSort())
	{
		printf("Insertion Sort\n");
		for (int i = 0; i < n; i++)
		{
			if (i != 0)
				printf(" ");
			printf("%d", changed[i]);
		}
		printf("\n");
		return 0;
	}

	// merge sort
	for (int i = 0; i < n; i++)
		changed[i] = origin[i];
	if (mergeSort())
	{
		printf("Merge Sort\n");
		for (int i = 0; i < n; i++)
		{
			if (i != 0)
				printf(" ");
			printf("%d", changed[i]);
		}
		printf("\n");
	}

	return 0;

}