#include <iostream>
#include <string>
#include <map>
using namespace std;

map<int, string> intToString;
map<string, int> stringToInt;
map<string, int> gangs;
int G[2010][2010] = { 0 };
int weight[2010] = { 0 };
int n, k, numPerson = 0;
bool isVisited[2010] = { false };

void dfs(int nowVisit, int & head, int & member, int & totalValue)
{
	member++;
	isVisited[nowVisit] = true;
	if (weight[nowVisit] > weight[head])
		head = nowVisit;
	for (int i = 0; i < numPerson; i++)
	{
		if (G[nowVisit][i] > 0)
		{
			totalValue += G[nowVisit][i];
			G[nowVisit][i] = G[i][nowVisit] = 0;
			if (isVisited[i] == false)
				dfs(i, head, member, totalValue);
		}
	}
}

void dfsTravel()
{
	for (int i = 0; i < numPerson; i++)
	{
		if (isVisited[i] == false)
		{
			int head = i, numMember = 0, totalValue = 0;
			dfs(i, head, numMember, totalValue);
			if (numMember > 2 && totalValue > k)
				gangs[intToString[head]] = numMember;
		}
	}
}

int change(string s)
{
	if (stringToInt.find(s) != stringToInt.end())
		return stringToInt[s];
	
	stringToInt[s] = numPerson;
	intToString[numPerson] = s;
	return numPerson++;
}

int main()
{
	int w;
	string s1, s2;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> s1 >> s2 >> w;
		int id1 = change(s1);
		int id2 = change(s2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}

	dfsTravel();
	cout << gangs.size() << endl;
	map<string, int>::iterator it;
	for (it = gangs.begin(); it != gangs.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}