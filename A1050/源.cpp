#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	string s1, s2;
	bool table[128];
	for (int i = 0; i < 128; i++)
		table[i] = false;
	
	getline(cin, s1);
	getline(cin, s2);

	for (int i = 0; i < s2.length(); i++)
		table[s2[i]] = true;
	for (int i = 0; i < s1.length(); i++)
		if (!table[s1[i]])
			printf("%c", s1[i]);
	printf("\n");
	return 0;
}