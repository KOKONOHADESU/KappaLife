#include "SceneMain.h"

#include "../Object/Player.h"
#include "../Object/Enemy.h"

#include <DxLib.h>

namespace
{
	// �G�̐�
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
	// �C���X�^���X����
	m_pPlayer = new Player();

	for (int i = 0; i < kEnemyNum; i++)
	{
		m_pEnemy[i] = new Enemy();
	}

	// ������
	m_pPlayer->Init();

	for (int i = 0; i < kEnemyNum; i++)
	{
		m_pEnemy[i]->Init();
	}
}

void SceneMain::End()
{
	// �������
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
	// �X�V����
	m_pPlayer->Update();

	for (int i = 0; i < kEnemyNum; i++)
	{
		m_pEnemy[i]->Update();
	}

	return this;
}

void SceneMain::Draw()
{
	// �`�揈��
	m_pPlayer->Draw();

	for (int i = 0; i < kEnemyNum; i++)
	{
		m_pEnemy[i]->Draw();
	}
}
