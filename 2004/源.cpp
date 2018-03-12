#include <iostream>
#include <queue>
using namespace std;

int height, width, slides, threshold;
int MRI[1288][130][62];
bool visited[1288][130][62];
int X[6] = { 1, -1, 0, 0, 0, 0 };
int Y[6] = { 0, 0, 1, -1, 0, 0 };
int Z[6] = { 0, 0, 0, 0, 1, -1 };

struct node
{
	int x;
	int y;
	int z;
}Node;

bool edge_check(int x, int y, int z)
{
	if (x >= width || x < 0 || y >= height || y < 0 || z >= slides || z < 0)
		return false;
	if (MRI[x][y][z] == 0 || visited[x][y][z] == true)
		return false;
	return true;
}

int bfs(int x, int y, int z)
{
	queue<node> q;
	int i = 0;
	Node.x = x;
	Node.y = y;
	Node.z = z;

	int sum = 0;
	q.push(Node);
	visited[x][y][z] = true;
	while (!q.empty())
	{
		node top = q.front();
		q.pop();
		sum++;
		for (i = 0; i < 6; i++)
		{
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			int newZ = top.z + Z[i];
			if (edge_check(newX, newY, newZ))
			{
				Node.x = newX;
				Node.y = newY;
				Node.z = newZ;
				q.push(Node);
				visited[newX][newY][newZ] = true;
			}
		}
	}
	if (sum >= threshold)
		return sum;
	else
		return 0;
}

int main()
{
	cin >> height >> width >> slides >> threshold;
	int i, j, k;
	for (i = 0; i < slides; i++)
	{
		for (j = 0; j < height; j++)
		{
			for (k = 0; k < width; k++)
			{
				cin >> MRI[k][j][i];
			}
		}
	}
	int blocks = 0;
	for (i = 0; i < width; i++)
	{
		for (j = 0; j < height; j++)
		{
			for (k = 0; k < slides; k++)
			{
				if (MRI[i][j][k] == 1 && visited[i][j][k] == false)
				{
					blocks += bfs(i, j, k);
				}
			}
		}
	}

	cout << blocks << endl;
	return 0;
}