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