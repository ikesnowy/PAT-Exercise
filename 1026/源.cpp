#include <iostream>
#include <queue>
#include <deque>
#include <iomanip>
using namespace std;

deque<int> windows[22];
int start_time[1002];
int duration[1002];
int leave_time[1002];
int global_clock = 8 * 60;
int close_time = 17 * 60;

int N, M, K, Q;

int check_window()
{
	int min_window = 0;
	for (int i = 0; i < N; i++)
	{
		if (windows[i].size() < windows[min_window].size())
		{
			min_window = i;
		}
	}
	if (windows[min_window].size() >= M)
		return -1;
	else
		return min_window;
}

int main()
{
	int i, j, k;
	cin >> N >> M >> K >> Q;

	for (i = 0; i < K; i++)
	{
		cin >> duration[i];
	}

	k = 0;
	while (k < K)
	{
		int window_free = check_window();
		while (window_free != -1)
		{
			if (windows[window_free].empty())
				start_time[k] = global_clock;
			else
				start_time[k] = leave_time[windows[window_free].back()];

			leave_time[k] = start_time[k] + duration[k];
			windows[window_free].push_back(k);
			k++;
			window_free = check_window();
		}

		int min_leave_time = leave_time[windows[0].front()];
		for (i = 0; i < N; i++)
		{
			if (leave_time[windows[i].front()] < min_leave_time)
			{
				min_leave_time = leave_time[windows[i].front()];
			}
		}
		for (i = 0; i < N; i++)
		{
			if (leave_time[windows[i].front()] == min_leave_time)
			{
				windows[i].pop_front();
			}
		}
		global_clock = min_leave_time;
	}

	while (Q--)
	{
		int query;
		cin >> query;
		query--;
		if (start_time[query] >= close_time)
			cout << "Sorry" << endl;
		else
			cout << setw(2) << setfill('0') << leave_time[query] / 60 << ":" << setw(2) << setfill('0') << leave_time[query] % 60 << endl;
	}

	return 0;
}