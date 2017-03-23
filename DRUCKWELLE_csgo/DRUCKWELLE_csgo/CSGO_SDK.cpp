#include "CSGO_SDK.h"

void Player_t::readBase(int iIndex)
{
	mem.ReadMemory<DWORD>(mem.getClientDLL() + Offsets::Dynamics::dwEntityList, &m_dwBase);
}

void Player_t::readHealth()
{
	mem.ReadMemory<unsigned int>(m_dwBase + Offsets::Netvars::m_iHealth, &m_iHealth);
}

void Player_t::readPosition()
{
	mem.ReadMemory<Vector>(m_dwBase + Offsets::Netvars::m_vecOrigin, &m_vPos);
}