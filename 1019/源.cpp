#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> seq;
	int n;
	bool hasPositive = false;
	cin >> n;
	while (n--)
	{
		int temp = 0;
		cin >> temp;
		if (temp > 0)
			hasPositive = true;
		seq.push_back(temp);
	}

	if (!hasPositive)
	{
		cout << 0 << " " << seq[0] << " " << seq[seq.size() - 1] << endl;
		return 0;
	}

	int subSequenceSize = 0;
	int maxSum = -99999;
	int maxLo = 0;
	int maxHi = 0;
	while (subSequenceSize < seq.size())
	{
		int lo = 0;
		int hi = subSequenceSize;

		int sum = 0;
		for (int i = lo; i <= subSequenceSize; i++)
		{
			sum += seq[lo + i];
		}
		if (sum > maxSum)
		{
			maxLo = lo;
			maxHi = hi;
			maxSum = sum;
		}
		else if (sum == maxSum)
		{
			if (lo < maxLo || hi < maxHi)
			{
				maxLo = lo;
				maxHi = hi;
			}
		}
		while (hi < seq.size() - 1)
		{
			sum -= seq[lo];
			lo++;
			hi++;
			sum += seq[hi];
			if (sum > maxSum)
			{
				maxLo = lo;
				maxHi = hi;
				maxSum = sum;
			}
			else if (sum == maxSum)
			{
				if (lo < maxLo || hi < maxHi)
				{
					maxLo = lo;
					maxHi = hi;
				}
			}
		}
		subSequenceSize++;
	}
	cout << maxSum << " " << seq[maxLo] << " " << seq[maxHi] << endl;
	return 0;
}