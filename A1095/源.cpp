#include <cstdio>
#include <cstring>

#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

map<string, int> parkTime;

struct car
{
	char plate[8];
	int time;
	bool isIn;
} all[10005];

bool cmp(car a, car b)
{
	if (strcmp(a.plate, b.plate))
		return strcmp(a.plate, b.plate) < 0;
	else
		return a.time < b.time;
}

bool cmpByTime(car a, car b)
{
	return a.time < b.time;
}

int timeToInt(int h, int m, int s)
{
	int result = s;
	result += m * 60;
	result += h * 3600;
	return result;
}

vector<car> valid;
int n, k;
int maxTime = 0;

int main()
{
	scanf("%d %d", &n, &k);
	int h, m, s;
	char state[5];
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d:%d:%d %s", &(all[i].plate), &h, &m, &s, &state);
		all[i].time = timeToInt(h, m, s);
		all[i].isIn = strcmp(state, "in") == 0;
	}

	sort(all, all + n, cmp);

	for (int i = 0; i < n - 1; i++)
	{
		if (strcmp(all[i].plate, all[i + 1].plate) == 0)
			if (all[i].isIn && !all[i + 1].isIn)
			{
				valid.push_back(all[i]);
				valid.push_back(all[i + 1]);

				int duration = all[i + 1].time - all[i].time;
				if (parkTime.count(all[i].plate) == 0)
					parkTime[all[i].plate] = 0;

				parkTime[all[i].plate] += duration;
				if (parkTime[all[i].plate] > maxTime)
					maxTime = parkTime[all[i].plate];

				i++;
			}
	}

	sort(valid.begin(), valid.end(), cmpByTime);

	int numberOfCar = 0;
	int now = 0;
	for (int i = 0; i < k; i++)
	{
		scanf("%d:%d:%d", &h, &m, &s);
		int time = timeToInt(h, m, s);
		while (now < valid.size() && valid[now].time <= time)
		{
			if (valid[now].isIn)
				numberOfCar++;
			else
				numberOfCar--;
			now++;
		}

		printf("%d\n", numberOfCar);
	}

	map<string, int>::iterator it;
	for (it = parkTime.begin(); it != parkTime.end(); it++)
	{
		if ((*it).second == maxTime)
			printf("%s ", it->first.c_str());
	}
	printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);

	return 0;
}