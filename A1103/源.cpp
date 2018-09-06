#include <cstdio>
#include <vector>
using namespace std;

vector<int> fac, ans, temp;
int k, p, key, maxFacSum = -1;

int power(int n, int po)
{
	int result = 1;
	while (po--)
		result *= n;
	return result;
}

void dfs(int index, int nowK, int sum, int facSum)
{
	if (sum == key && nowK == k)
	{
		if (facSum > maxFacSum)
		{
			ans = temp;
			maxFacSum = facSum;
		}
		return;
	}
	if (sum > key || nowK > k)
		return;
	if (index - 1 >= 0)
	{
		temp.push_back(index);
		dfs(index, nowK + 1, sum + fac[index], facSum + index);
		temp.pop_back();
		dfs(index - 1, nowK, sum, facSum);
	}
}

int main()
{
	scanf("%d %d %d", &key, &k, &p);
	int i = 0, temp = 0;
	while (temp <= key)
	{
		fac.push_back(temp);
		temp = power(++i, p);
	}

	dfs(fac.size() - 1, 0, 0, 0);
	if (maxFacSum == -1)
		printf("Impossible\n");
	else
	{
		printf("%d = %d^%d", key, ans[0], p);
		for (int i = 1; i < ans.size(); i++)
			printf(" + %d^%d", ans[i], p);
	}
	return 0;
}