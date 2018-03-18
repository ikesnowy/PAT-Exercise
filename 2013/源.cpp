#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n)
{
	if (n == 1)
		return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int max_size, size;
	cin >> max_size >> size;
	while (!isPrime(max_size))
		max_size++;
	vector<bool> hash;
	for (int i = 0; i < max_size; i++)
		hash.push_back(false);

	for (int i = 0; i < size; i++)
	{
		int key;
		cin >> key;
		int step = 1;
		for (step = 0; step < max_size; step++)
		{
			if (hash[(key + step * step) % max_size] == false)
			{
				if (i != 0)
					cout << " ";
				cout << (key + step * step) % max_size;
				hash[(key + step * step) % max_size] = true;
				break;
			}
		}
		if (step == max_size)
		{
			if (i != 0)
				cout << " ";
			cout << '-';
		}
	}
	return 0;
}