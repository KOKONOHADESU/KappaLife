#include "SceneMain.h"

#include "../Object/Player.h"
#include "../Object/Enemy.h"

#include <DxLib.h>

namespace
{
	// 敵の数
	constexpr int kEnemyNum = 50;
}

SceneMain::SceneMain()
{
}

SceneMain::~SceneMain()
{
}

void SceneMain::Init()
{
	// インスタンス生成
	m_pPlayer = new Player();

	for (int i = 0; i < kEnemyNum; i++)
	{
		m_pEnemy[i] = new Enemy();
	}

	// 初期化
	m_pPlayer->Init();

	for (int i = 0; i < kEnemyNum; i++)
	{
		m_pEnemy[i]->Init();
	}
}

void SceneMain::End()
{
	// 解放処理
	m_pPlayer->End();
	for (int i = 0; i < kEnemyNum; i++)
	{
		m_pEnemy[i]->End();
	}

	delete m_pPlayer;
	for (int i = 0; i < kEnemyNum; i++)
	{
		delete m_pEnemy[i];
	}

	m_pPlayer = nullptr;
	for (int i = 0; i < kEnemyNum; i++)
	{
		m_pEnemy[i] = nullptr;
	}
}

SceneMain* SceneMain::Update()
{
	// 更新処理
	m_pPlayer->Update();

	for (int i = 0; i < kEnemyNum; i++)
	{
		m_pEnemy[i]->Update();
	}

	return this;
}

void SceneMain::Draw()
{
	// 描画処理
	m_pPlayer->Draw();

	for (int i = 0; i < kEnemyNum; i++)
	{
		m_pEnemy[i]->Draw();
	}
}
