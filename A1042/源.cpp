#include <iostream>
#include <string>
using namespace std;

string getCardName(int n)
{
	if (n == 52 || n == 53)
		return "J";

	if (n < 13)
		return "S";
	else if (n < 26)
		return "H";
	else if (n < 39)
		return "C";
	else if (n < 52)
		return "D";
}

int getCardNumber(int n)
{
	if (n == 52)
		return 1;
	else if (n == 53)
		return 2;

	return n % 13 + 1;
}

int main()
{
	int deck[54];

	for (int i = 0; i < 54; i++)
		deck[i] = i;

	int repeatTime;
	cin >> repeatTime;

	int shufflingOrder[54];
	for (int i = 0; i < 54; i++)
		cin >> shufflingOrder[i];

	int deckAux[54];
	while (repeatTime--)
	{
		for (int i = 0; i < 54; i++)
			deckAux[i] = deck[i];

		for (int i = 0; i < 54; i++)
			deck[shufflingOrder[i] - 1] = deckAux[i];
	}

	for (int i = 0; i < 54; i++)
	{
		if (i != 0)
			cout << " ";
		cout << getCardName(deck[i]) << getCardNumber(deck[i]);
	}
	cout << endl;
	return 0;
}