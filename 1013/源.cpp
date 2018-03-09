#include <iostream>
#include <string>
#include <stack>
using namespace std;

string itos(int n)
{
	string s;
	stack<int> stack;
	while (n != 0)
	{
		int i = n % 10;
		stack.push(i);
		n /= 10;
	}
	
	while (!stack.empty())
	{
		s.push_back(stack.top() + '0');
		stack.pop();
	}

	return s;
}

int main()
{
	int a, b;
	cin >> a >> b;
	int sum = a + b;
	if (sum < 0)
	{
		cout << "-";
		sum = -sum;
	}
	else if (sum == 0)
	{
		cout << "0" << endl;
		return 0;
	}
	string s = itos(sum);
	if (s.length() < 4)
	{
		cout << s << endl;
	}
	else
	{
		for (int i = s.length() - 3; i > 0; i -= 3)
		{
			s.insert(i, 1, ',');
		}
		cout << s << endl;
	}

	return 0;
}