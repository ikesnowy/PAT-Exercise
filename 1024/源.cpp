#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	int grades[2002][4];
	int grade_count[102];
	map<string, int> ids;
	string subjects = "ACME";

	int n, m;
	cin >> n >> m;
	// input
	for (int i = 0; i < n; i++)
	{
		string name;
		int c, m, e, a;
		cin >> name >> c >> m >> e;
		a = (c + m + e) / 3;
		ids[name] = i;
		grades[i][0] = a;
		grades[i][1] = c;
		grades[i][2] = m;
		grades[i][3] = e;
	}
	// count
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 102; j++)
		{
			grade_count[j] = 0;
		}
		for (int j = 0; j < n; j++)
		{
			grade_count[grades[j][i]]++;
		}
		for (int j = 100; j >= 0; j--)
		{
			grade_count[j] += grade_count[j + 1];
		}
		for (int j = 0; j < n; j++)
		{
			grades[j][i] = grade_count[grades[j][i] + 1] + 1;
		}
	}
	// query
	while (m--)
	{
		string ID;
		cin >> ID;
		map<string, int>::iterator query_id = ids.find(ID);
		if (query_id == ids.end())
		{
			cout << "N/A" << endl;
		}
		else
		{
			int max_rank = grades[query_id->second][0];
			int max_subject = 0;
			for (int i = 1; i < 4; i++)
			{
				if (grades[query_id->second][i] < max_rank)
				{
					max_rank = grades[query_id->second][i];
					max_subject = i;
				}
			}
			cout << max_rank << " " << subjects[max_subject] << endl;
		}
	}
	return 0;
}