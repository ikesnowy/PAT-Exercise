#include <iostream>
#include <string>
using namespace std;

int bead[128];

int main()
{
	string shop, eva;
	cin >> shop >> eva;
	for (int i = 0; i < 128; i++)
		bead[i] = 0;
	for (int i = 0; i < shop.length(); i++)
		bead[shop[i]]++;

	bool isYes = true;
	int missing = 0;
	for (int i = 0; i < eva.length(); i++)
	{
		if (bead[eva[i]] == 0)
		{
			isYes = false;
			missing++;
		}
		else
		{
			bead[eva[i]]--;
		}
	}

	int count = 0;
	if (isYes)
	{
		cout << "Yes ";
		for (int i = 0; i < 128; i++)
			if (bead[i] != 0)
				count += bead[i];
		cout << count << endl;
	}
	else 
	{
		cout << "No " << missing << endl;
	}

	return 0;
}