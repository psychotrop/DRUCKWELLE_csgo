#pragma once

#include "Include.h"

class Memory
{
private:
	HANDLE m_hProcess;
	unsigned int m_iProcessID;

	DWORD dwClientDLL;
	DWORD dwEngineDLL;

public:
	Memory();
	~Memory();

	void init();

	template <class Type>
	bool ReadMemory(DWORD dwAddress, Type* pBuffer)
	{
		return ReadProcessMemory(m_hProcess, (void*)dwAddress, pBuffer, sizeof(Type, NULL));
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