#pragma once

#include <Windows.h>
#include <TlHelp32.h>


class Memory
{
private:
	HANDLE m_hProcess;
	unsigned int m_iProcessID;

public:
	Memory();
	~Memory();

	void init();

	template <class Type>
	bool ReadMemory(DWORD dwAddress, Type* pBuffer)
	{
		return ReadProcessMemory(m_hProcess, (void*), pBuffer, sizeof(Type, NULL));
	}

	template <class Type>
	bool WriteMemory(DWORD dwAddress, Type  &pToWrite)
	{
		return WriteProcessMemory(m_hProcess, (void*)dwAddress, pToWrite, sizeof(Type), NULL);
	}
};

extern Memory mem;