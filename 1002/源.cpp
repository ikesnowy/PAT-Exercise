#include <iostream>
#include <string>
using namespace std;

string sayNumberChinese(char number)
{
	switch (number)
	{
	case '0':
		return "ling";
		break;
	case '1':
		return "yi";
		break;
	case '2':
		return "er";
		break;
	case '3':
		return "san";
		break;
	case '4':
		return "si";
		break;
	case '5':
		return "wu";
		break;
	case '6':
		return "liu";
		break;
	case '7':
		return "qi";
		break;
	case '8':
		return "ba";
		break;
	case '9':
		return "jiu";
		break;
	}
	return "error";
}

string sayDigitChinese(char digit)
{
	switch (digit)
	{
	case '0':
		return "";
		break;
	case '1':
		return "Shi";
		break;
	case '2':
		return "Bai";
		break;
	case '3':
		return "Qian";
		break;
	case '4':
		return "Wan";
		break;
	case '5':
		return "Shi";
		break;
	case '6':
		return "Bai";
		break;
	case '7':
		return "Qian";
		break;
	case '8':
		return "Yi";
		break;
	case '9':
		return "";
		break;
	}
	return "error";
}

string sayFourDigitNumber(string number, bool isMiddle, bool isFirst)
{
	if (number.length() > 4)
	{
		return "Overflow!";
	}
	string result = "";
	int i = 0;

	if (number[i] == '0')
	{
		while (number[i] == '0' && i < 4)
			i++;

		if (i == 4 && isMiddle)
		{
			result += sayNumberChinese('0');
			return result;
		}
		else if (i == 4 && !isMiddle)
		{
			return result;
		}

		if (!isFirst)
		{
			result += sayNumberChinese('0') + " ";
		}
	}

	for (; i < 4; i++)
	{
		if (number[i] == '0')
		{
			while (number[i] == '0')
				i++;
			i--;
			if (i != 3)
			{
				result += sayNumberChinese(number[i]) + " ";
			}
			continue;
		}
		result += sayNumberChinese(number[i]) + " ";
		result += sayDigitChinese(3 - i + '0') + " ";
	}

	int space = result.find_last_not_of(' ');
	return result.substr(0, space + 1);
}

int main()
{
	string n = "";
	cin >> n;
	
	if (n[0] == '-')
	{
		cout << "Fu ";
		n.erase(0, 1);
	}

	if (n == "0")
	{
		cout << "ling";
		return 0;
	}

	for (int i = 1; i < (int)n.length(); i++)
	{
		if (n[i] != '0')
		{
			break;
		}
		if (i == n.length() - 1)
		{
			while (n.length() % 4 != 0)
			{
				n = "0" + n;
			}
			cout << sayFourDigitNumber(n.substr(0, 4), false, true);
			if (n.length() > 4)
			{
				cout << " ";
				cout << sayDigitChinese((char)n.length() - 4 + '0');
			}
			
			return 0;
		}
	}

	while (n.length() % 4 != 0)
	{
		n = "0" + n;
	}

	bool isMiddle = false;
	for (int i = 0; i < (int)n.length(); i += 4)
	{
		if (i + 5 < (int)n.length())
		{
			string numberInt = n.substr(i, 5);
			if (numberInt == "00000")
			{
				continue;
			}
		}

		string number = sayFourDigitNumber(n.substr(i, 4), isMiddle, i == 0);
		if (i != 0 && number.empty() == false)
		{
			cout << " " << number;
		}
		else
		{
			cout << number;
		}
			
		if (i + 8 < n.length())
		{
			isMiddle = true;
		}
		else
		{
			isMiddle = false;
		}
		if (i + 4 < (int)n.length() && number != "ling")
			cout << " " << sayDigitChinese((char)n.length() - 4 - i + '0');
	}
	return 0;
}

