#include "../Util/GameSystem.h"
#include "SceneBattle.h"
#include "SceneResult.h"
#include "SceneMain.h"

#include <DxLib.h>

SceneBattle::SceneBattle()
{
	BatAreaPattern = 0;

	m_BatAreaUpX = 0;
	m_BatAreaDownX = 0;

	m_BatAreaUpY = 0;
	m_BatAreaDownY = 0;

	m_WinSizeX = GameSystem::kScreenSizeX;
	m_WinSizeY = GameSystem::kScreenSizeY;



}

SceneBattle::~SceneBattle()
{

}

void SceneBattle::Init()
{

}

void SceneBattle::End()
{

}

SceneBase* SceneBattle::Update()
{
	int Areaptn = BatAreaPattern;
	if (Areaptn == 0)
	{
		m_BatAreaUpX = m_WinSizeX / 2 - 350;
		m_BatAreaDownX = m_WinSizeX / 2 + 350;

		m_BatAreaUpY = m_WinSizeY / 2 + 50;
		m_BatAreaDownY = m_WinSizeY / 2 + 500;

	}
	else
	{
		m_BatAreaUpX = 0;
		m_BatAreaDownX = 0;

		m_BatAreaUpY = 0;
		m_BatAreaDownY = 0;
	}

	return this;
}

void SceneBattle::Draw()
{
	DrawLine(20, 0, 20, m_WinSizeY, 0xffffff,2);
	DrawLine(1900, 0, 1900, m_WinSizeY, 0xffffff,2);

	DrawBox(m_BatAreaUpX, m_BatAreaUpY, m_BatAreaDownX, m_BatAreaDownY, 0xffffff, false);
	DrawBox(m_BatAreaUpX - 2, m_BatAreaUpY - 2, m_BatAreaDownX + 2, m_BatAreaDownY + 2, 0xffffff, false);

	//“G‚Ì•\Ž¦ˆÊ’u(‰¼)
	DrawCircle(m_WinSizeX / 2, 300, 100, 0xff0000, true);

}
	