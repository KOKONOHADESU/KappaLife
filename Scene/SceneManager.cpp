#include "SceneManager.h"

#include "SceneMain.h"


SceneManager::SceneManager()
{
	// ���߂̃V�[��
	m_pScene = new SceneMain();
}

SceneManager::~SceneManager()
{
}

void SceneManager::Init()
{
	// �V�[���̏���������
	m_pScene->Init();
}

void SceneManager::End()
{
	// �V�[���̉������
	m_pScene->End();

	delete m_pScene;
	m_pScene = nullptr;
}

void SceneManager::Update()
{
	// ���݂̃V�[�����L�^����
	SceneBase* pScene = m_pScene->Update();

	// �V�[�����������V�[����ύX����
	if (pScene != m_pScene)
	{
		// ���̃V�[����������
		m_pScene = pScene;
		// �V�[���̏���������������
		m_pScene->Init();
	}
}

void SceneManager::Draw()
{
	// �V�[���̕`��
	m_pScene->Draw();
}
