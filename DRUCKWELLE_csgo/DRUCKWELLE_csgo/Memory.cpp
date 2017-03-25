#include "Memory.h"


Memory::Memory()
{
}

Memory::~Memory()
{
}

void Memory::init()
{
	HWND hwndCSGO = FindWindow(0, "Counter-Strike: Global Offensive");

	GetWindowThreadProcessId(hwndCSGO, (LPDWORD)&m_iProcessID);

	m_hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, m_iProcessID);
}

DWORD Memory::getClientDLL()
{
	return dwClientDLL;
}

DWORD Memory::getEngineDLL()
{
	return dwEngineDLL;
}