#include "Player.h"

#include "../Util/GameSystem.h"

namespace
{
	// �A�j���[�V�������x�����߂�
	constexpr int kMoveingAnimFrame = 12;

	// �A�j���[�V����
	// ��ړ�
	constexpr int kAnimWalkUp = 16;
	constexpr int kAnimWalkEndUp = 19;
	// ���ړ�
	constexpr int kAnimWalkDown = 12;
	constexpr int kAnimWalkEndDown = 15;
	// ���E�ړ�
	constexpr int kAnimWalkLeftRight = 20;
	constexpr int kAnimWalkLeftRightDown = 23;

	// �A�C�h�����
	// ��ړ�
	constexpr int kAnimIdleUp = 4;
	constexpr int kAnimIdleEndUp = 5;
	// ���ړ�
	constexpr int kAnimIdleDown = 0;
	constexpr int kAnimIdleEndDown = 1;
	// ���E�ړ�
	constexpr int kAnimIdleLeftRight = 8;
	constexpr int kAnimIdleEndLeftRight = 9;

	// ���a
	constexpr float kRadius = 150.0f;
}

void Player::Init()
{
	// �摜�̓ǂݍ���
	// �������ւ̕����ǂݍ���
	LoadDivGraph("Data/Texture.png", 28, 4, 7, 320, 320, m_hGraph);

	// �Đ��A�j���[�V�����̏�����
	m_animNo = kAnimWalkDown;

	// �A�j���[�V�����t���[���̏�����
	m_animFrameCount = -1;

	// �ړ��̏�����
	m_isMove = false;

	// �A�j���[�V�����֘A�̏�����
	for (int i = 0; i < AnimData::MAX; i++)
	{
		m_isAnimData[i]  = false;
		m_animFirstFrameCount[i] = 0;
	}
	m_isAnimData[AnimData::WALKDOWN] = true;

	// ���W�̏�����
	m_posX = GameSystem::kScreenSizeX / 2;
	m_posY = GameSystem::kScreenSizeY / 2;
}

void Player::Update()
{
	// �ړ�����
	MovingProcess();

	// �A�j���[�V����
	Anim();

	// ��ʔ͈͊O����
	OutSize();

	m_collPosUpX = m_posX - 320 / 2;
	m_collPosUpY = m_posY - 320 / 2;

	m_collPosDownX = m_collPosUpX + 320;
	m_collPosDownY = m_collPosUpY + 320;
}

void Player::Draw()
{
	// �~��`��
	DrawCircle(m_posX, m_posY, kRadius, 0xff0000, false);

	// �����蔻��m�F�p
//	DrawBox(m_collPosUpX, m_collPosUpY, m_collPosDownX, m_collPosDownY, 0xff0000, false);

	// �v���C���[�`��
	DrawRotaGraphF(m_posX, m_posY, 1, 0.0f, m_hGraph[m_animNo], true, m_dir);

}

void Player::End()
{
	// ���������
	for (int i = 0; i < 18; i++)
	{
		DeleteGraph(m_hGraph[i]);
	}
}

void Player::MovingProcess()
{
	m_isMove = false;
	if (CheckHitKey(KEY_INPUT_A))
	{
		m_isMove = true;
		m_posX -= 10.0f;
		m_dir = true;
		m_isAnimData[AnimData::WALKLEFTRIGHT] = true;
		m_isAnimData[AnimData::WALKDOWN] = false;
		m_isAnimData[AnimData::WALKUP] = false;
	}
	else if (CheckHitKey(KEY_INPUT_D))
	{
		m_isMove = true;
		m_posX += 10.0f;
		m_dir = false;
		m_isAnimData[AnimData::WALKLEFTRIGHT] = true;
		m_isAnimData[AnimData::WALKDOWN] = false;
		m_isAnimData[AnimData::WALKUP] = false;
	}
	else if (CheckHitKey(KEY_INPUT_W))
	{
		m_isMove = true;
		m_posY -= 10.0f;
		m_isAnimData[AnimData::WALKUP] = true;
		m_isAnimData[AnimData::WALKLEFTRIGHT] = false;
		m_isAnimData[AnimData::WALKDOWN] = false;
	}
	else if (CheckHitKey(KEY_INPUT_S))
	{
		m_isMove = true;
		m_posY += 10.0f;
		m_isAnimData[AnimData::WALKDOWN] = true;
		m_isAnimData[AnimData::WALKLEFTRIGHT] = false;
		m_isAnimData[AnimData::WALKUP] = false;
	}
}

void Player::OutSize()
{
	// �ړ��͈͂����߂�
// �E
	if (GameSystem::kScreenSizeX - m_graphSizeX / 2 < m_posX)
	{
		m_posX = GameSystem::kScreenSizeX - m_graphSizeX / 2;
	}
	// ��
	if (0 + m_graphSizeX / 2 > m_posX)
	{
		m_posX = 0 + m_graphSizeX / 2;
	}
	// ��
	if (0 + m_graphSizeX / 2 > m_posY)
	{
		m_posY = 0 + m_graphSizeX / 2;
	}
	// ��
	if (GameSystem::kScreenSizeY - m_graphSizeY / 2 < m_posY)
	{
		m_posY = GameSystem::kScreenSizeY - m_graphSizeY / 2;
	}
}

void Player::Anim()
{
	// ������
	AnimChange(AnimData::WALKDOWN,
		kAnimWalkDown, kAnimWalkEndDown,
		kAnimIdleDown, kAnimIdleEndDown);
	// �����
	AnimChange(AnimData::WALKUP, 
		kAnimWalkUp, kAnimWalkEndUp,
		kAnimIdleUp, kAnimIdleEndUp);
	// ���E����
	AnimChange(AnimData::WALKLEFTRIGHT, 
		kAnimWalkLeftRight, kAnimWalkLeftRightDown, 
		kAnimIdleLeftRight, kAnimIdleEndLeftRight);
}

void Player::AnimChange(AnimData animData, int animNo, int animNoEnd, int animIdle, int animIdleEnd)
{
	// �����Ă����Ȃ��ꍇ�A�C�h����Ԃɂ���
	if (!m_isMove)
	{
		if (animData == WALKDOWN && m_isAnimData[animData])
		{
			// �A�j���[�V�������Ǘ�����
			AnimFrameControl(animIdle, animIdleEnd);
		}
		if (animData == WALKUP && m_isAnimData[animData])
		{
			// �A�j���[�V�������Ǘ�����
			AnimFrameControl(animIdle, animIdleEnd);
		}
		if (animData == WALKLEFTRIGHT && m_isAnimData[animData])
		{
			// �A�j���[�V�������Ǘ�����
			AnimFrameControl(animIdle, animIdleEnd);
		}
		m_animFirstFrameCount[animData] = 0;
		return;
	}
	// �������t���O�������Ă����ꍇ
	if (m_isAnimData[animData])
	{
		// ���������s����Ă���ԂɃt���[�����J�E���g����
		m_animFirstFrameCount[animData]++;
		// ���������߂̈�񂾂����ꍇ
		if (m_animFirstFrameCount[animData] == 1)
		{
			// �A�j���[�V�����J�n�ʒu���w�肷��
			m_animNo = animNoEnd;
		}
		// �A�j���[�V�������Ǘ�����
		AnimFrameControl(animNo, animNoEnd);
	}
	else
	{
		m_animFirstFrameCount[animData] = 0;
	}
}

void Player::AnimFrameControl(int animNo,int animNoEnd)
{
	// �A�j���[�V�����̃t���[�����J�E���g����
	m_animFrameCount++;

	// �A�j���[�V�������x�𐧌�
	if (m_animFrameCount > kMoveingAnimFrame)
	{
		m_animFrameCount = 0;
		m_animNo++;
	}

	// �A�j���[�V�������I������ƈʒu����Đ�����
	if (m_animNo > animNoEnd)
	{
		m_animNo = animNo;
	}
}
