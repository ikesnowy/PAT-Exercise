#include <iostream>
#include <string>
using namespace std;

int main()
{
	int query;
	cin >> query;
	for (int i = 0; i < query; i++)
	{
		bool flag = true;
		long long a, b, result, c;
		cin >> a >> b >> c;
		result = a + b;
		if (a > 0 && b > 0 && result < 0)
			flag = true;
		else if (a < 0 && b < 0 && result >= 0)
			flag = false;
		else
			flag = result > c;
		
		cout << "Case #" << i + 1 << ": ";
		if (flag)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}