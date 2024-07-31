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
	// �摜�̓ǂݍ���
	m_hGraph = LoadGraph("Enemy.png");

	// �������W���w��
	m_posX = GetRand(GameSystem::kScreenSizeX);
	m_posY = GetRand(GameSystem::kScreenSizeY);

	m_isUpDown = false;
	m_upDownCount = 0;
}

void Enemy::End()
{
	// ���������
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
	// �`��
	DrawGraph(m_posX, m_posY, m_hGraph, true);
}
