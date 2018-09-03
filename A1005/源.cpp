#include <iostream>
#include <string>
using namespace std;

string numberInEnglish[10] =
{ "zero", "one", "two", "three", "four", "five",
"six", "seven", "eight", "nine" };

void dfs(int n)
{
	if (n / 10 == 0)
	{
		cout << numberInEnglish[n % 10];
		return;
	}
	dfs(n / 10);
	cout << " " << numberInEnglish[n % 10];
}

int main()
{
	string number;
	cin >> number;
	int sum = 0;
	for (int i = 0; i < number.length(); i++)
	{
		sum += number[i] - '0';
	}

	// int to string
	if (sum == 0)
	{
		cout << numberInEnglish[0] << endl;
		return 0;
	}

	dfs(sum);
	cout << endl;
	return 0;
}