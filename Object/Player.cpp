#include "Player.h"

#include "../Util/GameSystem.h"

namespace
{
	// アニメーション速度を決める
	constexpr int kMoveingAnimFrame = 12;

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

	// アイドル状態
	// 上移動
	constexpr int kAnimIdleUp = 4;
	constexpr int kAnimIdleEndUp = 5;
	// 下移動
	constexpr int kAnimIdleDown = 0;
	constexpr int kAnimIdleEndDown = 1;
	// 左右移動
	constexpr int kAnimIdleLeftRight = 8;
	constexpr int kAnimIdleEndLeftRight = 9;

	// 半径
	constexpr float kRadius = 150.0f;
}

void Player::Init()
{
	// 画像の読み込み
	// メモリへの分割読み込み
	LoadDivGraph("Data/Texture.png", 28, 4, 7, 320, 320, m_hGraph);

	// 再生アニメーションの初期化
	m_animNo = kAnimWalkDown;

	// アニメーションフレームの初期化
	m_animFrameCount = -1;

	// 移動の初期化
	m_isMove = false;

	// アニメーション関連の初期化
	for (int i = 0; i < AnimData::MAX; i++)
	{
		m_isAnimData[i]  = false;
		m_animFirstFrameCount[i] = 0;
	}
	m_isAnimData[AnimData::WALKDOWN] = true;

	// 座標の初期化
	m_posX = GameSystem::kScreenSizeX / 2;
	m_posY = GameSystem::kScreenSizeY / 2;
}

void Player::Update()
{
	// 移動処理
	MovingProcess();

	// アニメーション
	Anim();

	// 画面範囲外処理
	OutSize();

	m_collPosUpX = m_posX - 320 / 2;
	m_collPosUpY = m_posY - 320 / 2;

	m_collPosDownX = m_collPosUpX + 320;
	m_collPosDownY = m_collPosUpY + 320;
}

void Player::Draw()
{
	// 円を描画
	DrawCircle(m_posX, m_posY, kRadius, 0xff0000, false);

	// 当たり判定確認用
//	DrawBox(m_collPosUpX, m_collPosUpY, m_collPosDownX, m_collPosDownY, 0xff0000, false);

	// プレイヤー描画
	DrawRotaGraphF(m_posX, m_posY, 1, 0.0f, m_hGraph[m_animNo], true, m_dir);

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

void Player::Anim()
{
	// 下歩き
	AnimChange(AnimData::WALKDOWN,
		kAnimWalkDown, kAnimWalkEndDown,
		kAnimIdleDown, kAnimIdleEndDown);
	// 上歩き
	AnimChange(AnimData::WALKUP, 
		kAnimWalkUp, kAnimWalkEndUp,
		kAnimIdleUp, kAnimIdleEndUp);
	// 左右歩き
	AnimChange(AnimData::WALKLEFTRIGHT, 
		kAnimWalkLeftRight, kAnimWalkLeftRightDown, 
		kAnimIdleLeftRight, kAnimIdleEndLeftRight);
}

void Player::AnimChange(AnimData animData, int animNo, int animNoEnd, int animIdle, int animIdleEnd)
{
	// 動いていいない場合アイドル状態にする
	if (!m_isMove)
	{
		if (animData == WALKDOWN && m_isAnimData[animData])
		{
			// アニメーションを管理する
			AnimFrameControl(animIdle, animIdleEnd);
		}
		if (animData == WALKUP && m_isAnimData[animData])
		{
			// アニメーションを管理する
			AnimFrameControl(animIdle, animIdleEnd);
		}
		if (animData == WALKLEFTRIGHT && m_isAnimData[animData])
		{
			// アニメーションを管理する
			AnimFrameControl(animIdle, animIdleEnd);
		}
		m_animFirstFrameCount[animData] = 0;
		return;
	}
	// 下歩きフラグが立っていた場合
	if (m_isAnimData[animData])
	{
		// 処理が実行されている間にフレームをカウントする
		m_animFirstFrameCount[animData]++;
		// 処理が初めの一回だった場合
		if (m_animFirstFrameCount[animData] == 1)
		{
			// アニメーション開始位置を指定する
			m_animNo = animNoEnd;
		}
		// アニメーションを管理する
		AnimFrameControl(animNo, animNoEnd);
	}
	else
	{
		m_animFirstFrameCount[animData] = 0;
	}
}

void Player::AnimFrameControl(int animNo,int animNoEnd)
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
