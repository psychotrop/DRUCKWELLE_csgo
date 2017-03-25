#pragma once

#include "Include.h"

class Memory
{
private:
	HANDLE m_hProcess;
	unsigned int m_iProcessID;

	DWORD m_dwClientDLL;
	DWORD m_dwEngineDLL;

	bool DataCompare(const BYTE* pData, const BYTE* pMask, const char* pszMask);

	DWORD FindPattern(DWORD start, DWORD size, const char* sig, const char* mask);
	
	DWORD FindPatternArray(DWORD start, DWORD size, const char* mask, int count, ...);
	
	DWORD GetModule(char* moduleName);

public:
	Memory();
	~Memory();

	void init();

	void getModules();
	void findOffsets();

	template <class Type>
	bool ReadMemory(DWORD dwAddress, Type* pBuffer)
	{
		return ReadProcessMemory(m_hProcess, (void*)dwAddress, pBuffer, sizeof(Type), NULL);
	}

	template <class Type>
	bool WriteMemory(DWORD dwAddress, Type  &pToWrite)
	{
		return WriteProcessMemory(m_hProcess, (void*)dwAddress, pToWrite, sizeof(Type), NULL);
	}

	DWORD getClientDLL();
	DWORD getEngineDLL();
};
extern Memory mem;

