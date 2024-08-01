#include "SceneManager.h"

#include "SceneMain.h"


SceneManager::SceneManager()
{
	// 初めのシーン
	m_pScene = new SceneMain();
}

SceneManager::~SceneManager()
{
}

void SceneManager::Init()
{
	// シーンの初期化処理
	m_pScene->Init();
}

void SceneManager::End()
{
	// シーンの解放処理
	m_pScene->End();

	delete m_pScene;
	m_pScene = nullptr;
}

void SceneManager::Update()
{
	// 現在のシーンを記録する
	SceneBase* pScene = m_pScene->Update();

	// シーンが違ったらシーンを変更する
	if (pScene != m_pScene)
	{
		// 次のシーンを代入する
		m_pScene = pScene;
		// シーンの初期化処理をする
		m_pScene->Init();
	}
}

void SceneManager::Draw()
{
	// シーンの描画
	m_pScene->Draw();
}
