#include "Player.h"

namespace
{
	// アニメーション速度を決める
	constexpr int kMoveingAnimFrame = 1;

#if true	
	// アニメーション
	// 上移動
	constexpr int kAnimWalkUp = 16;
	constexpr int kAnimWalkEndUp = 19;
	// 下移動
	constexpr int kAnimWalkDown = 12;
	constexpr int kAnimWalkEndDown = 15;
	// 左右移動
	constexpr int kAnimWalkLeftRight = 20;
	constexpr int kAnimWalkLeftRightDown = 23;
#else
	// 上移動
	constexpr int kAnimWalkUp = 4;
	constexpr int kAnimWalkEndUp = 5;
	// 下移動
	constexpr int kAnimWalkDown = 0;
	constexpr int kAnimWalkEndDown = 1;
	// 左右移動
	constexpr int kAnimWalkLeftRight = 8;
	constexpr int kAnimWalkLeftRightDown = 9;
#endif
}

void Player::Init()
{
	// 画像の読み込み
	// メモリへの分割読み込み
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
	// 移動処理
	MovingProcess();

	// 上フラグが立っていた場合
	if (m_isAnimData[AnimData::WALKUP])
	{
		// 処理が実行されている間にフレームをカウントする
		m_animFirstFrameCount[AnimData::WALKUP]++;
		// 処理が初めの一回だった場合
		if (m_animFirstFrameCount[AnimData::WALKUP] == 1)
		{
			// アニメーション開始位置を指定する
			m_animNo = kAnimWalkUp;
		}
		// アニメーションを管理する
		AnimControl(kAnimWalkUp, kAnimWalkEndUp);
	}
	else
	{
		m_animFirstFrameCount[AnimData::WALKUP] = 0;
	}

	// 左右歩きフラグが立っていた場合
	if (m_isAnimData[AnimData::WALKLEFTRIGHT])
	{
		// 処理が実行されている間にフレームをカウントする
		m_animFirstFrameCount[AnimData::WALKLEFTRIGHT]++;
		// 処理が初めの一回だった場合
		if (m_animFirstFrameCount[AnimData::WALKLEFTRIGHT] == 1)
		{
			// アニメーション開始位置を指定する
			m_animNo = kAnimWalkLeftRight;
		}
		// アニメーションを管理する
		AnimControl(kAnimWalkLeftRight, kAnimWalkLeftRightDown);
	}
	else
	{
		m_animFirstFrameCount[AnimData::WALKLEFTRIGHT] = 0;
	}

	// 下歩きフラグが立っていた場合
	if (m_isAnimData[AnimData::WALKDOWN])
	{		
		// 処理が実行されている間にフレームをカウントする
		m_animFirstFrameCount[AnimData::WALKDOWN]++;
		// 処理が初めの一回だった場合
		if (m_animFirstFrameCount[AnimData::WALKDOWN] == 1)
		{
			// アニメーション開始位置を指定する
			m_animNo = kAnimWalkDown;
		}
		// アニメーションを管理する
		AnimControl(kAnimWalkDown, kAnimWalkEndDown);
	}
	else
	{
		m_animFirstFrameCount[AnimData::WALKDOWN] = 0;
	}

	// 画面範囲外処理
	OutSize();
}

void Player::Draw()
{
	// プレイヤー描画
	DrawRotaGraph(m_posX, m_posY, 1, m_rota, m_hGraph[m_animNo], true, m_dir);
}

void Player::End()
{
	// メモリ解放
	for (int i = 0; i < 18; i++)
	{
		DeleteGraph(m_hGraph[i]);
	}
}

void Player::MovingProcess()
{
	// 初期化
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
	// 移動範囲を決める
// 右
	if (GameSystem::kScreenSizeX - m_graphSizeX / 2 < m_posX)
	{
		m_posX = GameSystem::kScreenSizeX - m_graphSizeX / 2;
	}
	// 左
	if (0 + m_graphSizeX / 2 > m_posX)
	{
		m_posX = 0 + m_graphSizeX / 2;
	}
	// 上
	if (0 + m_graphSizeX / 2 > m_posY)
	{
		m_posY = 0 + m_graphSizeX / 2;
	}
	// 下
	if (GameSystem::kScreenSizeY - m_graphSizeY / 2 < m_posY)
	{
		m_posY = GameSystem::kScreenSizeY - m_graphSizeY / 2;
	}
}

void Player::AnimControl(int animNo,int animNoEnd)
{
	// アニメーションのフレームをカウントする
	m_animFrameCount++;

	// アニメーション速度を制限
	if (m_animFrameCount > kMoveingAnimFrame)
	{
		m_animFrameCount = 0;
		m_animNo++;
	}

	// アニメーションが終了すると位置から再生する
	if (m_animNo > animNoEnd)
	{
		m_animNo = animNo;
	}
}
