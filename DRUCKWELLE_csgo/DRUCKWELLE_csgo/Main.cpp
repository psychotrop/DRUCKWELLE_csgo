#include <iostream>

#include "Memory.h"

// external
Memory mem;
Glow glow;

bool g_bRun = true;

using namespace std;


DWORD git_gud;


int main()
{	
	mem.init();
	
	while (g_bRun)
	{
		glow.run();
	}

	return 0;
}