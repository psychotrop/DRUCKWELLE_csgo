#pragma once

#include "Include.h"

struct Vector
{
	float x, y, z;
};

struct Player_t
{
private:
	DWORD			m_dwBase;
	unsigned int	m_iHealth;
	unsigned int	m_iTeam;
	Vector			m_vPos;

	void			readBase(int iIndex);
	void			readHealth();
	void 			readTeam();
	void			readPosition();

public:
	unsigned int	getHealth();
	unsigned int	getTeam();
	Vector			getPos();

	void			readInfo();
};

struct GlowObject_t
{
	DWORD dwBase;
	float r;
	float g;
	float b;
	float a;
	uint8_t unk1[16];
	bool m_bRenderWhenOccluded;
	bool m_bRenderWhenUnoccluded;
	bool m_bFullBloom;
	uint8_t unk2[10];
};