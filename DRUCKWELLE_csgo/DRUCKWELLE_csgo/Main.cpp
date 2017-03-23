#include <iostream>

#include "Memory.h"

using namespace std;

Memory mem;

int main()
{	
	int i = 0;

	cout << i << endl;

	mem.WriteMemory<int>(0, i);

	cout << i << endl;

	system("pause");

	return 0;
}