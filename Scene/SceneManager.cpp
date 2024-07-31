#include "SceneManager.h"

#include "SceneMain.h"


SceneManager::SceneManager()
{
	m_pScene = new SceneMain();
}

SceneManager::~SceneManager()
{
}

void SceneManager::Init()
{
	m_pScene->Init();
}

void SceneManager::End()
{
	m_pScene->End();
}

void SceneManager::Update()
{
	m_pScene->Update();
}

void SceneManager::Draw()
{
	m_pScene->Draw();
}
