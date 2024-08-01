#pragma once
#include <DxLib.h>

#include "../Util/GameSystem.h"

// �摜�Ǘ��N���X
class Player
{
private:
	// �A�j���[�V�����f�[�^
	// �񋓌^
	enum AnimData
	{
		WALKUP,
		WALKLEFTRIGHT,
		WALKDOWN,

		MAX,
	};
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
public:
	int GetCollUpX() { return m_collPosUpX; }
	int GetCollUpY() { return m_collPosUpY; }
	int GetCollDownX() { return m_collPosDownX; }
	int GetCollDownY() { return m_collPosDownY; }

	float GetPosX() { return m_posX; }
	float GetPosY() { return m_posY; }

private:
	// �A�j���[�V����
	void Anim();
	// �A�j���[�V������ύX����
	void AnimChange(AnimData animData, int animNo, int animNoEnd,int animIdle,int animIdleEnd);
	// �A�j���[�V�������Đ�����
	void AnimFrameControl(int animNo, int animNoEnd);

private:
	// �摜�ǂݍ��ݗp�ϐ���錾
	int m_hGraph[28];

	// �A�j���[�V�����ԍ�
	int m_animNo = -1;

	// �A�j���[�V�����̍Đ��t���[�����J�E���g����
	int m_animFrameCount;

	// ���W
	float m_posX = 0;
	float m_posY = 0;

	// �摜�T�C�Y�̎擾
	int m_graphSizeX = -1;
	int m_graphSizeY = -1;

	// ����
	bool m_dir = false;

	// �����Ă��邩�ǂ���
	bool m_isMove;

	// �A�j���[�V�����������Ȃ��Ă��邩�ǂ���
	bool m_isAnimData[AnimData::MAX];
	int m_animFirstFrameCount[AnimData::MAX];

	// �����蔻��p
	int m_collPosUpX;
	int m_collPosUpY;
	int m_collPosDownX;
	int m_collPosDownY;
};

