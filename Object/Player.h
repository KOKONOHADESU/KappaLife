#pragma once
#include <DxLib.h>

#include "../Util/GameSystem.h"

// 画像管理クラス
class Player
{
private:
	// アニメーションデータ
	// 列挙型
	enum AnimData
	{
		WALKUP,
		WALKLEFTRIGHT,
		WALKDOWN,

		MAX,
	};
public:
	// 初期化
	void Init();

	// 更新処理
	// 操作
	void Update();

	// 描画
	void Draw();

	// メモリ解放
	void End();

	// 移動操作
	void MovingProcess();

	// 画面範囲外処理
	void OutSize();
public:
	int GetCollUpX() { return m_collPosUpX; }
	int GetCollUpY() { return m_collPosUpY; }
	int GetCollDownX() { return m_collPosDownX; }
	int GetCollDownY() { return m_collPosDownY; }

	float GetPosX() { return m_posX; }
	float GetPosY() { return m_posY; }

private:
	// アニメーション
	void Anim();
	// アニメーションを変更する
	void AnimChange(AnimData animData, int animNo, int animNoEnd,int animIdle,int animIdleEnd);
	// アニメーションを再生する
	void AnimFrameControl(int animNo, int animNoEnd);

private:
	// 画像読み込み用変数を宣言
	int m_hGraph[28];

	// アニメーション番号
	int m_animNo = -1;

	// アニメーションの再生フレームをカウントする
	int m_animFrameCount;

	// 座標
	float m_posX = 0;
	float m_posY = 0;

	// 画像サイズの取得
	int m_graphSizeX = -1;
	int m_graphSizeY = -1;

	// 向き
	bool m_dir = false;

	// 動いているかどうか
	bool m_isMove;

	// アニメーションをおこなっているかどうか
	bool m_isAnimData[AnimData::MAX];
	int m_animFirstFrameCount[AnimData::MAX];

	// 当たり判定用
	int m_collPosUpX;
	int m_collPosUpY;
	int m_collPosDownX;
	int m_collPosDownY;
};

