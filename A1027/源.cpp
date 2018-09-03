#include <iostream>
#include <string>
using namespace std;

char radix13(int number)
{
	if (number < 10)
		return '0' + number;
	switch (number)
	{
	case 10:
		return 'A';
	case 11:
		return 'B';
	case 12:
		return 'C';
	default:
		break;
	}
}

string dectoAny(int dec, int radix)
{
	string result;
	do 
	{
		int y = dec % radix;
		dec /= radix;
		result = radix13(y) + result;
	} while (dec != 0);
	if (result.length() < 2)
		result = "0" + result;
	return result;
}

int main()
{
	int r, g, b;
	cin >> r >> g >> b;
	cout << "#" << dectoAny(r, 13) << dectoAny(g, 13) << dectoAny(b, 13) << endl;
	return 0;
}