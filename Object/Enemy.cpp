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
	// 画像の読み込み
	m_hGraph = LoadGraph("Enemy.png");

	// 初期座標を指定
	m_posX = GetRand(GameSystem::kScreenSizeX);
	m_posY = GetRand(GameSystem::kScreenSizeY);

	m_isUpDown = false;
	m_upDownCount = 0;
}

void Enemy::End()
{
	// メモリ解放
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
	// 描画
	DrawGraph(m_posX, m_posY, m_hGraph, true);
}
