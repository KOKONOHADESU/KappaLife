#pragma once

#include "SceneBase.h"

// ���U���g�V�[���̊Ǘ�
class SceneResult : public SceneBase
{
public:
	// �R���X�g���N�^
	SceneResult();
	// �f�X�g���N�^
	virtual ~SceneResult();

	// ������
	void Init() override;
	// �������
	void End()override;
	// �X�V����
	SceneBase* Update()override;
	// �`��
	void Draw()override;
};