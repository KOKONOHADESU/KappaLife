#pragma once

#include "SceneBase.h"

class Player;
class Enemy;

// ���C���V�[���̊Ǘ�
class SceneMain : public SceneBase
{
public:
	// �R���X�g���N�^
	SceneMain();
	// �f�X�g���N�^
	virtual ~SceneMain();

	// ������
	void Init() override;
	// �������
	void End()override;
	// �X�V����
	SceneMain* Update()override;
	// �`��
	void Draw()override;
private:
	Player* m_pPlayer;
	Enemy* m_pEnemy[50];
};