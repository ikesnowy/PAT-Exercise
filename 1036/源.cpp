#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class testee
{
public:
	int location;
	string id;
	int score;
	int rank_all;
	int rank_local;

	bool operator < (testee other)
	{
		if (score == other.score)
			return id < other.id;
		return score > other.score;
	}
};

bool local_compare(testee a, testee b)
{
	if (a.location == b.location)
	{
		return a < b;
	}
	return a.location < b.location;
}

vector<testee> all_testee;

int main()
{
	int i = 0;
	int location_sum;
	int testee_sum;
	cin >> location_sum;
	for (i = 0; i < location_sum; i++)
	{
		cin >> testee_sum;
		while (testee_sum--)
		{
			testee input;
			input.location = i;
			cin >> input.id >> input.score;
			all_testee.push_back(input);
		}
	}

	sort(all_testee.begin(), all_testee.end(), local_compare);

	int rank = 1;
	all_testee[0].rank_local = 1;
	int local_it = 1;
	for (i = 1; i < (int)all_testee.size(); i++)
	{
		if (all_testee[i].location != all_testee[i - 1].location)
		{
			rank = 1;
			local_it = 0;
		}
		else if (all_testee[i].score != all_testee[i - 1].score)
			rank = local_it + 1;

		all_testee[i].rank_local = rank;
		local_it++;
	}

	sort(all_testee.begin(), all_testee.end());

	// rank all
	rank = 1;
	all_testee[0].rank_all = 1;
	for (i = 1; i < (int)all_testee.size(); i++)
	{
		if (all_testee[i].score != all_testee[i - 1].score)
			rank = i + 1;

		all_testee[i].rank_all = rank;
	}

	cout << all_testee.size() << endl;
	for (i = 0; i < (int)all_testee.size(); i++)
	{
		cout << all_testee[i].id << " " << all_testee[i].rank_all << " " << all_testee[i].location + 1 << " " << all_testee[i].rank_local << endl;
	}

	return 0;
}