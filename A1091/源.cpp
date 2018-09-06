#include <cstdio>
#include <queue>
using namespace std;

struct node
{
	int x, y, z;
} Node;

int X[6] = { 0, 0, 0, 0, 1, -1 };
int Y[6] = { 0, 0, 1, -1, 0, 0 };
int Z[6] = { 1, -1, 0, 0, 0, 0 };

int slides[1290][130][61];
bool visited[1290][130][61] = { false };
int m, n, l, t;

bool needVisit(int x, int y, int z)
{
	if (x >= n || x < 0 || y >= m || y < 0 || z >= l || z < 0)
		return false;
	if (visited[x][y][z] == true || slides[x][y][z] == 0)
		return false;
	return true;
}

int bfs(int x, int y, int z)
{
	int total = 0;
	queue<node> q;
	Node.x = x;
	Node.y = y;
	Node.z = z;
	q.push(Node);
	visited[x][y][z] = true;
	while (!q.empty())
	{
		node top = q.front();
		q.pop();
		total++;
		for (int i = 0; i < 6; i++)
		{
			int nX = top.x + X[i];
			int nY = top.y + Y[i];
			int nZ = top.z + Z[i];
			if (needVisit(nX, nY, nZ))
			{
				Node.x = nX;
				Node.y = nY;
				Node.z = nZ;
				q.push(Node);
				visited[nX][nY][nZ] = true;
			}
		}
	}

	if (total >= t)
		return total;
	else
		return 0;
}

int main()
{
	scanf("%d %d %d %d", &n, &m, &l, &t);
	for (int z = 0; z < l; z++)
		for (int x = 0; x < n; x++)
			for (int y = 0; y < m; y++)
				scanf("%d", &slides[x][y][z]);

	int ans = 0;
	for (int z = 0; z < l; z++)
		for (int x = 0; x < n; x++)
			for (int y = 0; y < m; y++)
			{
				if (slides[x][y][z] == 1 && !visited[x][y][z])
					ans += bfs(x, y, z);
			}

	printf("%d\n", ans);
	return 0;
}