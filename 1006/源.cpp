#include <iostream>
#include <string>
using namespace std;

char radix13[13] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C' };

string DecTo13(int n)
{
	string result = "";
	while (n != 0)
	{
		int r = n % 13;
		n /= 13;
		result = radix13[r] + result;
	}
	if (result.length() == 1)
	{
		result = "0" + result;
	}
	return result;
}

int main()
{
	int R, G, B;
	cin >> R >> G >> B;
	cout << "#" << DecTo13(R) << DecTo13(G) << DecTo13(B);
	return 0;
}
