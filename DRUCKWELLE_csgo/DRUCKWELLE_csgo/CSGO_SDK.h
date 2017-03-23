#pragma once

#include <Windows.h>
#include <TlHelp32.h>

struct Vector
{
	float x, y, z;
};

struct Player_t
{
private:
	unsigned int	m_iHealth;
	unsigned int	m_iTeam;
	Vector			m_vPos;

	unsigned int	readHealth();
	unsigned int	readTeam();
	Vector			readPosition();

public:
	unsigned int	getHealth();

	unsigned int	getTeam();

	void			readInfo();
};

