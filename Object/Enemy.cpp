#include "Enemy.h"

#include "../Util/GameSystem.h"

#include <DxLib.h>

namespace
{
	// ���a
	constexpr float kRadius = 150.0f;
}

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
	// �摜�̓ǂݍ���
	m_hGraph = LoadGraph("Data/Enemy.png");

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
	//m_upDownCount++;
	//if (m_upDownCount > 60)
	//{
	//	m_upDownCount = 0;
	//	m_isUpDown = !m_isUpDown;
	//}

	//if (m_isUpDown)
	//{
	//	m_posY -= 15;
	//}
	//else
	//{
	//	m_posY += 15;
	//}

	//m_collPosUpX = m_posX;
	//m_collPosUpY = m_posY;

	//m_collPosDownX = m_collPosUpX + 320;
	//m_collPosDownY = m_collPosUpY + 320;
}

void Enemy::Draw()
{
	// �~��`��
	DrawCircle(m_posX + 320/2, m_posY + 320 / 2, kRadius, 0xff0000, false);
	// �����蔻��m�F�p
//	DrawBox(m_collPosUpX, m_collPosUpY, m_collPosDownX, m_collPosDownY, 0xff0000, false);
	// �`��
	DrawGraphF(m_posX, m_posY, m_hGraph, true);
}
