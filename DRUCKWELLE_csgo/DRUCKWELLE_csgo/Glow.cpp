#include "Glow.h"

static GlowObject_t glowObjects[128];

void Glow::run()
{
	DWORD pGlowArray;/* = mem.ReadMemory<DWORD>(mem.getClientDLL() + Offsets::Dynamics::dwGlowObject);*/
	ReadProcessMemory(mem.m_hProcess, (void*)(mem.getClientDLL() + Offsets::Dynamics::dwGlowObject), &pGlowArray, sizeof(DWORD), NULL);

	uint32_t iObjcount;
	ReadProcessMemory(mem.m_hProcess, (void*)((mem.getClientDLL() + Offsets::Dynamics::dwGlowObject) + 4), &iObjcount, sizeof(uint32_t), NULL);
	cout << iObjcount << endl;
	for (auto i = 0; i < iObjcount; i++)
	{
		DWORD pObj = pGlowArray + i * sizeof(GlowObject_t);
		GlowObject_t objGlow;/* = mem.ReadMemory<GlowObject_t>(pObj);*/
		if (ReadProcessMemory(mem.m_hProcess, (void*)(pObj), &objGlow, sizeof(GlowObject_t), NULL))
		{
			DWORD player;
			ReadProcessMemory(mem.m_hProcess, (void*)(objGlow.dwBase), &player, sizeof(DWORD), NULL);

			if (objGlow.dwBase == NULL || player == NULL)
				continue;

			objGlow.a = 1.0f;
			objGlow.r = 0.5f;
			objGlow.g = 0.f;
			objGlow.b = 0.f;

			//mem.WriteMemory<GlowObject_t>(pObj, objGlow);
			WriteProcessMemory(mem.m_hProcess, (void*)pGlowArray, &objGlow, sizeof(GlowObject_t), NULL); // gamecrash
		}
	}
}