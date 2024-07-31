#include "Player.h"

namespace
{
	// �A�j���[�V�������x�����߂�
	constexpr int kMoveingAnimFrame = 1;

#if true	
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
#else
	// ��ړ�
	constexpr int kAnimWalkUp = 4;
	constexpr int kAnimWalkEndUp = 5;
	// ���ړ�
	constexpr int kAnimWalkDown = 0;
	constexpr int kAnimWalkEndDown = 1;
	// ���E�ړ�
	constexpr int kAnimWalkLeftRight = 8;
	constexpr int kAnimWalkLeftRightDown = 9;
#endif
}

void Player::Init()
{
	// �摜�̓ǂݍ���
	// �������ւ̕����ǂݍ���
	LoadDivGraph("Data/Texture.png", 28, 4, 7, 320, 320, m_hGraph);

	m_animNo = kAnimWalkLeftRight;

	m_animFrameCount = -1;

	m_rota = 0.0f;

	for (int i = 0; i < AnimData::MAX; i++)
	{
		m_isAnimData[i]  = false;
		m_isAnimTemp[i]  = false;
		m_animFirstFrameCount[i] = 0;
	}
}

void Player::Update()
{
	// �ړ�����
	MovingProcess();

	// ��t���O�������Ă����ꍇ
	if (m_isAnimData[AnimData::WALKUP])
	{
		// ���������s����Ă���ԂɃt���[�����J�E���g����
		m_animFirstFrameCount[AnimData::WALKUP]++;
		// ���������߂̈�񂾂����ꍇ
		if (m_animFirstFrameCount[AnimData::WALKUP] == 1)
		{
			// �A�j���[�V�����J�n�ʒu���w�肷��
			m_animNo = kAnimWalkUp;
		}
		// �A�j���[�V�������Ǘ�����
		AnimControl(kAnimWalkUp, kAnimWalkEndUp);
	}
	else
	{
		m_animFirstFrameCount[AnimData::WALKUP] = 0;
	}

	// ���E�����t���O�������Ă����ꍇ
	if (m_isAnimData[AnimData::WALKLEFTRIGHT])
	{
		// ���������s����Ă���ԂɃt���[�����J�E���g����
		m_animFirstFrameCount[AnimData::WALKLEFTRIGHT]++;
		// ���������߂̈�񂾂����ꍇ
		if (m_animFirstFrameCount[AnimData::WALKLEFTRIGHT] == 1)
		{
			// �A�j���[�V�����J�n�ʒu���w�肷��
			m_animNo = kAnimWalkLeftRight;
		}
		// �A�j���[�V�������Ǘ�����
		AnimControl(kAnimWalkLeftRight, kAnimWalkLeftRightDown);
	}
	else
	{
		m_animFirstFrameCount[AnimData::WALKLEFTRIGHT] = 0;
	}

	// �������t���O�������Ă����ꍇ
	if (m_isAnimData[AnimData::WALKDOWN])
	{		
		// ���������s����Ă���ԂɃt���[�����J�E���g����
		m_animFirstFrameCount[AnimData::WALKDOWN]++;
		// ���������߂̈�񂾂����ꍇ
		if (m_animFirstFrameCount[AnimData::WALKDOWN] == 1)
		{
			// �A�j���[�V�����J�n�ʒu���w�肷��
			m_animNo = kAnimWalkDown;
		}
		// �A�j���[�V�������Ǘ�����
		AnimControl(kAnimWalkDown, kAnimWalkEndDown);
	}
	else
	{
		m_animFirstFrameCount[AnimData::WALKDOWN] = 0;
	}

	// ��ʔ͈͊O����
	OutSize();
}

void Player::Draw()
{
	// �v���C���[�`��
	DrawRotaGraph(m_posX, m_posY, 1, m_rota, m_hGraph[m_animNo], true, m_dir);
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
	// ������
	m_isAnimData[AnimData::WALKDOWN] = false;
	m_isAnimData[AnimData::WALKLEFTRIGHT] = false;
	m_isAnimData[AnimData::WALKUP] = false;

	if (CheckHitKey(KEY_INPUT_A))
	{
		m_posX -= 10;
		m_dir = true;
		m_isAnimData[AnimData::WALKLEFTRIGHT] = true;
	}
	else if (CheckHitKey(KEY_INPUT_D))
	{
		m_posX += 10;
		m_dir = false;
		m_isAnimData[AnimData::WALKLEFTRIGHT] = true;
	}
	else if (CheckHitKey(KEY_INPUT_W))
	{
		m_posY -= 10;
		m_isAnimData[AnimData::WALKUP] = true;
	}
	else if (CheckHitKey(KEY_INPUT_S))
	{
		m_posY += 10;
		m_isAnimData[AnimData::WALKDOWN] = true;
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

void Player::AnimControl(int animNo,int animNoEnd)
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
