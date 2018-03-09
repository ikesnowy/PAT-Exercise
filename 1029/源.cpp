#include <iostream>
#include <deque>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <algorithm>
using namespace std;

class customer
{
public:
	int arrive;
	int duration;
	int start;

	bool operator < (customer other)
	{
		return arrive < other.arrive;
	}
};

customer customers[10003];

int N, K;
int close_time = 17 * 3600;
int open_time = 8 * 3600;
int global_time = 8 * 3600;
int window[103];
int window_free = 0;

vector<int> serve;

int main()
{
	int i, j;
	cin >> N >> K;
	int hour, minute, second;
	for (i = 0; i < N; i++)
	{
		scanf("%d:%d:%d", &hour, &minute, &second);
		customers[i].arrive = hour * 3600 + minute * 60 + second;
		cin >> customers[i].duration;
		if (customers[i].duration > 60)
			customers[i].duration = 3600;
		else
			customers[i].duration *= 60;
	}

	sort(customers, customers + N);

	int id = 0;
	int window_free = K;
	while (id < N)
	{
		// serve
		while (window_free != 0 && id < N)
		{
			serve.push_back(id);
			if (customers[id].arrive < global_time)
				customers[id].start = global_time;
			else
				customers[id].start = customers[id].arrive;
			id++;
			window_free--;
		}

		// find the first done customer
		int min_duration = customers[serve.front()].duration;
		for (i = 0; i < (int)serve.size(); i++)
		{
			if (min_duration > customers[serve[i]].duration)
			{
				min_duration = customers[serve[i]].duration;
			}
		}

		// clear them out
		for (i = 0; i < (int)serve.size(); i++)
		{
			if (min_duration == customers[serve[i]].duration)
			{
				serve.erase(serve.begin() + i);
				i--;
				window_free++;
			}
			else
			{
				customers[serve[i]].duration -= min_duration;
			}
		}

		global_time += min_duration;
	}

	double average_waiting = 0;
	double actual_serve = N;
	for (i = 0; i < N; i++)
	{
		if (customers[i].arrive > close_time)
		{
			actual_serve--;
			continue;
		}
		average_waiting += customers[i].start - customers[i].arrive;
	}

	if (actual_serve == 0)
	{
		cout << "0.0" << endl;
		return 0;
	}
	cout << fixed << setprecision(1) << average_waiting / actual_serve / 60.0 << endl;
	return 0;
}