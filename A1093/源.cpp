#include <iostream>
#include <string>
using namespace std;

string s;
int mod = 1000000007;
int leftP[100005];

int main()
{
	getline(cin, s);
	leftP[0] = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (i > 0)
			leftP[i] = leftP[i - 1];
		if (s[i] == 'P')
			leftP[i]++;
	}
	int ans = 0, rightT = 0;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] == 'T')
			rightT++;
		else if (s[i] == 'A')
			ans = (ans + leftP[i] * rightT) % mod;
	}

	printf("%d\n", ans);
	return 0;
}