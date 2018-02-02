#include <iostream>
using namespace std;

int totalTime = 0;
int nowLevel = 0;

void moveTo(int levelTo)
{
	if (levelTo > nowLevel)
	{
		totalTime += (levelTo - nowLevel) * 6;
		totalTime += 5;
		nowLevel = levelTo;
	}
	else if (levelTo < nowLevel)
	{
		totalTime += (nowLevel - levelTo) * 4;
		totalTime += 5;
		nowLevel = levelTo;
	}
	else
	{
		totalTime += 5;
	}
}

int main()
{
	int operationNum = 0;
	cin >> operationNum;
	while (operationNum--)
	{
		int floorNum;
		cin >> floorNum;
		moveTo(floorNum);
	}

	cout << totalTime << endl;
	return 0;
}