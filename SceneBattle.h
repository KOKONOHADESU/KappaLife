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

	//�o�g�����v���C���[��������͈�
	int m_BatAreaUpX, m_BatAreaUpY, m_BatAreaDownX, m_BatAreaDownY;

	//�o�g���G���A�ő�l
	int m_BatAreaMaxUpX, m_BatAreaMaxUpY, m_BatAreaDownMaxX, m_BatAreaDownMaxY;

	//�o�g���G���A�����̃p�^�[��
	int BatAreaPattern;

};
