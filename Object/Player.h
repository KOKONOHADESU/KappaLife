#pragma once
#include <DxLib.h>

#include "../Util/GameSystem.h"

// �摜�Ǘ��N���X
class Player
{
public:
	// ������
	void Init();

	// �X�V����
	// ����
	void Update();

	// �`��
	void Draw();

	// ���������
	void End();

	// �ړ�����
	void MovingProcess();

	// ��ʔ͈͊O����
	void OutSize();

private:
	// �A�j���[�V�����Ǘ�
	void AnimControl(int animNo, int animNoEnd);

private:
	// �摜�ǂݍ��ݗp�ϐ���錾
	int m_hGraph[28];

	// �A�j���[�V�����ԍ�
	int m_animNo = -1;

	// �A�j���[�V�����̍Đ��t���[�����J�E���g����
	int m_animFrameCount;

	// ���W
	int m_posX = 0;
	int m_posY = 0;

	// �摜�T�C�Y�̎擾
	int m_graphSizeX = -1;
	int m_graphSizeY = -1;

	// ����
	bool m_dir = false;

	float m_rota;

	// �p�x
	float m_angle = 0.0f;

	// �A�j���[�V�����f�[�^
	// �񋓌^
	enum AnimData
	{
		IDLE,
		WALKUP,
		WALKLEFTRIGHT,
		WALKDOWN,

		MAX,
	};

	// �A�j���[�V�����������Ȃ��Ă��邩�ǂ���
	bool m_isAnimData[AnimData::MAX];
	int m_animFirstFrameCount[AnimData::MAX];

	bool m_isAnimTemp[AnimData::MAX];

};

