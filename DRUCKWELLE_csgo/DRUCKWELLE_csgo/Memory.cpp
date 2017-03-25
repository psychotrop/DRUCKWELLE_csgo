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

	getModules();
	findOffsets();
}

DWORD Memory::getClientDLL()
{
	return m_dwClientDLL;
}

DWORD Memory::getEngineDLL()
{
	return m_dwEngineDLL;
}

bool Memory::DataCompare(const BYTE* pData, const BYTE* pMask, const char* pszMask)
{
	for (; *pszMask; ++pszMask, ++pData, ++pMask) 
	{
		if (*pszMask == 'x' && *pData != *pMask) 
		{
			return false;
		}
	}
	return (*pszMask == NULL);
}

DWORD Memory::FindPattern(DWORD start, DWORD size, const char* sig, const char* mask)
{
	BYTE* data = new BYTE[size];

	unsigned long bytesRead;

	if (!ReadProcessMemory(m_hProcess, (LPVOID)start, data, size, &bytesRead))
	{
		return NULL;
	}

	for (DWORD i = 0; i < size; i++)
	{
		if (DataCompare((const BYTE*)(data + i), (const BYTE*)sig, mask))
		{
			return start + i;
		}
	}
	return NULL;
}

DWORD Memory::FindPatternArray(DWORD start, DWORD size, const char* mask, int count, ...)
{
	char* sig = new char[count + 1];
	va_list ap;
	va_start(ap, count);

	for (int i = 0; i < count; i++)
	{
		char read = va_arg(ap, char);
		sig[i] = read;
	}

	va_end(ap);
	sig[count] = '\0';

	return FindPattern(start, size, sig, mask);
}

DWORD Memory::GetModule(char* moduleName)
{
	HANDLE module = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, m_iProcessID);
	MODULEENTRY32 mEntry;

	do
	{
		if (!strcmp(mEntry.szModule, (LPSTR)moduleName))
		{
			CloseHandle(module);

			return (DWORD)mEntry.hModule;
		}
	} while (Module32Next(module, &mEntry));

	return NULL;
}

void Memory::getModules()
{
	m_dwClientDLL = GetModule("client.dll");
	m_dwEngineDLL = GetModule("engine.dll");
}

void Memory::findOffsets()
{
	// search for offset patterns
}