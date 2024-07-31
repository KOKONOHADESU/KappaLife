#pragma once

// �Q�[���V�[���̊��N���X
class SceneBase
{
public:
	// �R���X�g���N�^
	SceneBase() {}
	// �f�X�g���N�^
	virtual ~SceneBase() {}

	// ������
	virtual void Init() {}
	// �������
	virtual void End() {}
	// �X�V����
	virtual SceneBase* Update() { return this; }
	// �`��
	virtual void Draw() {}
};

