#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> original;
vector<int> partial;

bool isMax(int lo, int hi)
{
	for (int i = lo; i < hi; i++)
	{
		if (partial[i] > partial[hi])
			return false;
	}
	return true;
}

int main()
{
	int i = 0, j = 0;
	int totalNum;
	cin >> totalNum;
	int temp;
	for (i = 0; i < totalNum; i++)
	{
		cin >> temp;
		original.push_back(temp);
	}
	for (i = 0; i < totalNum; i++)
	{
		cin >> temp;
		partial.push_back(temp);
	}

	int sorted_length = 0;
	i = 0;
	while (partial[i] < partial[i + 1])
	{
		i++;
		sorted_length++;
	}
	sorted_length++;

	for (i = sorted_length; i < totalNum; i++)
	{
		if (original[i] != partial[i])
		{
			cout << "Heap Sort" << endl;
			int sorted = 0;
			for (j = totalNum - 1; j > 0 ; j--)
			{
				if (isMax(0, j))
					sorted++;
				else
					break;
			}
			int temp = partial[0];
			partial[0] = partial[totalNum - sorted - 1];
			partial[totalNum - sorted - 1] = temp;
			// sink
			int now = 1;
			while (now * 2 < totalNum - sorted)
			{
				int max_child = now * 2;
				if (partial[now * 2 - 1] < partial[now * 2] && now * 2 + 1 < totalNum - sorted)
					max_child = now * 2 + 1;
				if (partial[max_child - 1] > partial[now - 1])
				{
					temp = partial[now - 1];
					partial[now - 1] = partial[max_child - 1];
					partial[max_child - 1] = temp;
					now = max_child;
				}
				else
				{
					break;
				}
			}
			cout << partial[0];
			for (j = 1; j < totalNum; j++)
			{
				cout << " " << partial[j];
			}
			cout << endl;
			return 0;
		}
	}

	cout << "Insertion Sort" << endl;
	j = sorted_length;
	while (j > 0 && partial[j] < partial[j - 1])
	{
		int temp = partial[j - 1];
		partial[j - 1] = partial[j];
		partial[j] = temp;
		j--;
	}
	cout << partial[0];
	for (j = 1; j < totalNum; j++)
	{
		cout << " " << partial[j];
	}
	cout << endl;

	return 0;
}