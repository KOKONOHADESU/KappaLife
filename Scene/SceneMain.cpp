#include "SceneMain.h"
#include "SceneResult.h"

#include "../Object/Player.h"
#include "../Object/Enemy.h"

#include "../Util/Collision.h"

#include <DxLib.h>

namespace
{
	// 敵の数
	constexpr int kEnemyNum = 5;
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

	m_pColl = new Collision();

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

SceneBase* SceneMain::Update()
{
	// 更新処理
	m_pPlayer->Update();

	for (int i = 0; i < kEnemyNum; i++)
	{
		m_pEnemy[i]->Update();

		bool hit = m_pColl->IsCheckSquare(
			m_pPlayer->GetCollUpX(), m_pPlayer->GetCollUpY(),
			m_pPlayer->GetCollDownX(), m_pPlayer->GetCollDownY(),
			m_pEnemy[i]->GetCollUpX(), m_pEnemy[i]->GetCollUpY(),
			m_pEnemy[i]->GetCollDownX(), m_pEnemy[i]->GetCollDownY());

		bool hit2 = m_pColl->IsCheckCircle(
			m_pPlayer->GetPosX(), m_pPlayer->GetPosY(), 150.0f,
			m_pEnemy[i]->GetPosX(), m_pEnemy[i]->GetPosY(), 150.0f);

		//if (hit)
		//{
		//	return new SceneResult();
		//}

		if (hit2)
		{
			return new SceneResult();
		}
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
