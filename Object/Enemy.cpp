#include "Enemy.h"

#include "../Util/GameSystem.h"

#include <DxLib.h>

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
	// ‰æ‘œ‚Ì“Ç‚Ýž‚Ý
	m_hGraph = LoadGraph("Enemy.png");

	// ‰ŠúÀ•W‚ðŽw’è
	m_posX = GetRand(GameSystem::kScreenSizeX);
	m_posY = GetRand(GameSystem::kScreenSizeY);

	m_isUpDown = false;
	m_upDownCount = 0;
}

void Enemy::End()
{
	// ƒƒ‚ƒŠ‰ð•ú
	DeleteGraph(m_hGraph);
}

void Enemy::Update()
{
	m_upDownCount++;
	if (m_upDownCount > 60)
	{
		m_upDownCount = 0;
		m_isUpDown = !m_isUpDown;
	}

	if (m_isUpDown)
	{
		m_posY -= 15;
	}
	else
	{
		m_posY += 15;
	}
}

void Enemy::Draw()
{
	// •`‰æ
	DrawGraph(m_posX, m_posY, m_hGraph, true);
}
