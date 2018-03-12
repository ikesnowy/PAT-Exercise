#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int n;
int pre[100005];
bool visited[100005] = { false };
double rootPrice;
double rate;
double max_price = rootPrice;
int max_level = 0;
int sum = 0;

void dfs_it(int now, int level)
{
	if (now == -1)
	{
		if (level > max_level)
		{
			max_level = level;
			sum = 1;
		}
		else if (level == max_level)
			sum++;

		return;
	}
	visited[now] = true;
	dfs_it(pre[now], level + 1);
}

void dfs()
{
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false)
			dfs_it(i, 0);
	}
}

int main()
{
	cin >> n >> rootPrice >> rate;
	rate /= 100.0;
	for (int i = 0; i < n; i++)
	{
		cin >> pre[i];
	}
	dfs();
	max_price = rootPrice * pow((1 + rate), max_level - 1);
	cout << fixed << setprecision(2) << max_price << " " << sum << endl;
	return 0;
}