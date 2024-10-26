#pragma once
#include "../Util/GameSystem.h"
#include"SceneBase.h"

class SceneBattle:public SceneBase
{
public:
	SceneBattle();

	virtual ~SceneBattle();

	void Init()override;

	void End()override;

	SceneBase* Update()override;

	void Draw()override;

	void BattleArea( int upx,int upy,int drawx,int downy ,int ptn);

private:
	
	int m_WinSizeX;
	int m_WinSizeY;

	//バトル時プレイヤーが動ける範囲
	int m_BatAreaUpX, m_BatAreaUpY, m_BatAreaDownX, m_BatAreaDownY;

	//バトルエリア最大値
	int m_BatAreaMaxUpX, m_BatAreaMaxUpY, m_BatAreaDownMaxX, m_BatAreaDownMaxY;

	//バトルエリア挙動のパターン
	int BatAreaPattern;

};
