#include <iostream>
#include <iomanip>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

struct node
{
	int next;
	int value;
};

node lList[100005];
bool values[10005] = { false };

int main()
{
	int i;
	int head;
	int totalNode;
	cin >> head >> totalNode;
	for (i = 0; i < totalNode; i++)
	{
		int address;
		node readIn;
		cin >> address >> readIn.value >> readIn.next;
		lList[address] = readIn;
	}

	node removeList[100005];
	int removeHead = -1;
	int removeTail = -2;
	int addr = head;
	int before = head;
	while (addr != -1)
	{
		int absVal = lList[addr].value;
		if (absVal < 0)
			absVal = -absVal;
		if (!values[absVal])
		{
			values[absVal] = true;
			before = addr;
			addr = lList[addr].next;
		}
		else
		{
			removeList[addr] = lList[addr];
			removeList[addr].next = -1;
			if (removeTail == -2)
			{
				removeHead = addr;
				removeTail = addr;
			}
			else
			{
				removeList[removeTail].next = addr;
				removeTail = addr;
			}
			lList[before].next = lList[addr].next;
			addr = lList[before].next;
		}
	}

	addr = head;
	while (addr != -1)
	{
		cout << setw(5) << setfill('0') << addr << " ";
		cout << lList[addr].value << " ";
		addr = lList[addr].next;
		if (addr == -1)
			cout << addr << endl;
		else
			cout << setw(5) << setfill('0') << addr << endl;
	}

	addr = removeHead;
	while (addr != -1)
	{
		cout << setw(5) << setfill('0') << addr << " ";
		cout << removeList[addr].value << " ";
		addr = removeList[addr].next;
		if (addr == -1)
			cout << addr << endl;
		else
			cout << setw(5) << setfill('0') << addr << endl;
	}
	return 0;
}