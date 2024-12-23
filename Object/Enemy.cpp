#include "Enemy.h"

#include "../Util/GameSystem.h"

#include <DxLib.h>

namespace
{
	// 半径
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
	// 画像の読み込み
	m_hGraph = LoadGraph("Data/Enemy.png");

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
	// 円を描画
	DrawCircle(m_posX + 320/2, m_posY + 320 / 2, kRadius, 0xff0000, false);
	// 当たり判定確認用
//	DrawBox(m_collPosUpX, m_collPosUpY, m_collPosDownX, m_collPosDownY, 0xff0000, false);
	// 描画
	DrawGraphF(m_posX, m_posY, m_hGraph, true);
}
