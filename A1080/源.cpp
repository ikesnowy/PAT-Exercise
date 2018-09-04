#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstdio>
using namespace std;

const int MAXN = 40005;
const int MAXM = 105;

struct Applicant
{
	int number;
	int GE;
	int GI;
	int GA;
	vector<int> preferredSchool;
} Applicants[MAXN];

struct School
{
	int quota;
	int smallestRank;
	vector<int> admits;
} Schools[MAXM];

int n, m, k;

int cmp(Applicant a, Applicant b)
{
	if (a.GA > b.GA)
		return -1;
	else if (a.GA < b.GA)
		return 1;
	else
	{
		if (a.GE > b.GE)
			return -1;
		else if (a.GE < b.GE)
			return 1;
		else
			return 0;
	}
}

bool sortCmp(Applicant a, Applicant b)
{
	return cmp(a, b) < 0;
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &Schools[i].quota);
	}
	for (int i = 0; i < n; i++)
	{
		Applicants[i].number = i;
		scanf("%d %d", &Applicants[i].GE, &Applicants[i].GI);
		Applicants[i].GA = Applicants[i].GE + Applicants[i].GI;
		for (int j = 0; j < k; j++)
		{
			int preferredSchool;
			scanf("%d", &preferredSchool);
			Applicants[i].preferredSchool.push_back(preferredSchool);
		}
	}

	sort(Applicants, Applicants + n, sortCmp);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int preferredSchool = Applicants[i].preferredSchool[j];
			if (Schools[preferredSchool].quota > 0)
			{
				Schools[preferredSchool].quota--;
				Schools[preferredSchool].admits.push_back(Applicants[i].number);
				Schools[preferredSchool].smallestRank = i;
				break;
			}
			else
			{
				if (Schools[preferredSchool].admits.size() == 0)
					continue;

				int smallestStudent = Schools[preferredSchool].smallestRank;
				if (cmp(Applicants[smallestStudent], Applicants[i]) == 0)
				{
					Schools[preferredSchool].quota--;
					Schools[preferredSchool].admits.push_back(Applicants[i].number);
					Schools[preferredSchool].smallestRank = i;
					break;
				}
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		sort(Schools[i].admits.begin(), Schools[i].admits.end());
		for (int j = 0; j < Schools[i].admits.size(); j++)
		{
			if (j != 0)
				printf(" ");
			printf("%d", Schools[i].admits[j]);
		}
		printf("\n");
	}
	return 0;
}