#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct node
{
	string ID;
	int score;
	int location;
	int locationRank;
	int totalRank;
};

int n; // number of locations
vector<node*> totalNodes;
vector<node*> localNodes[105];

bool cmp(node * a, node * b)
{
	if (a->score == b->score)
		return a->ID < b->ID;
	else
		return a->score > b->score;
}

int main()
{
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		sum += k;
		for (int j = 0; j < k; j++)
		{
			node * temp = new node();
			cin >> temp->ID;
			scanf("%d", &(temp->score));
			temp->location = i + 1;
			totalNodes.push_back(temp);
			localNodes[i].push_back(temp);
		}
	}

	sort(totalNodes.begin(), totalNodes.end(), cmp);
	totalNodes[0]->totalRank = 1;
	for (int i = 1; i < totalNodes.size(); i++)
	{
		if (totalNodes[i]->score == totalNodes[i - 1]->score)
			totalNodes[i]->totalRank = totalNodes[i - 1]->totalRank;
		else
			totalNodes[i]->totalRank = i + 1;
	}

	for (int i = 0; i < n; i++)
	{
		sort(localNodes[i].begin(), localNodes[i].end(), cmp);
		localNodes[i][0]->locationRank = 1;
		for (int j = 1; j < localNodes[i].size(); j++)
		{
			if (localNodes[i][j]->score == localNodes[i][j - 1]->score)
				localNodes[i][j]->locationRank = localNodes[i][j - 1]->locationRank;
			else
				localNodes[i][j]->locationRank = j + 1;
		}
	}

	cout << totalNodes.size() << endl;
	for (int i = 0; i < totalNodes.size(); i++)
	{
		cout << totalNodes[i]->ID << " ";
		printf("%d %d %d\n", 
			totalNodes[i]->totalRank, 
			totalNodes[i]->location, 
			totalNodes[i]->locationRank);
	}

	return 0;
}