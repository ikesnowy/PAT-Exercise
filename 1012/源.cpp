#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<long> coupons_positive;
	vector<long> coupons_negative;
	vector<long> items_positive;
	vector<long> items_negative;
	int n;
	cin >> n;
	while (n--)
	{
		long temp;
		cin >> temp;
		if (temp > 0)
		{
			coupons_positive.push_back(temp);
		}
		else
		{
			coupons_negative.push_back(temp);
		}
	}

	cin >> n;
	while (n--)
	{
		long temp;
		cin >> temp;
		if (temp > 0)
		{
			items_positive.push_back(temp);
		}
		else
		{
			items_negative.push_back(temp);
		}
	}

	long sum = 0;

	// positive to positive
	sort(coupons_positive.begin(), coupons_positive.end());
	sort(items_positive.begin(), items_positive.end());

	vector<long>::reverse_iterator i = coupons_positive.rbegin();
	vector<long>::reverse_iterator j = items_positive.rbegin();

	while (i != coupons_positive.rend() && j != items_positive.rend())
	{
		sum += (*i) * (*j);
		i++;
		j++;
	}

	// negative to nagative
	sort(coupons_negative.begin(), coupons_negative.end());
	sort(items_negative.begin(), items_negative.end());

	vector<long>::iterator k = coupons_negative.begin();
	vector<long>::iterator l = items_negative.begin();

	while (k != coupons_negative.end() && l != items_negative.end())
	{
		sum += (*k) * (*l);
		k++;
		l++;
	}

	cout << sum << endl;

	return 0;
}