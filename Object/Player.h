#pragma once
#include <DxLib.h>

#include "../Util/GameSystem.h"

// 画像管理クラス
class Player
{
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

private:
	// アニメーション管理
	void AnimControl(int animNo, int animNoEnd);

private:
	// 画像読み込み用変数を宣言
	int m_hGraph[28];

	// アニメーション番号
	int m_animNo = -1;

	// アニメーションの再生フレームをカウントする
	int m_animFrameCount;

	// 座標
	int m_posX = 0;
	int m_posY = 0;

	// 画像サイズの取得
	int m_graphSizeX = -1;
	int m_graphSizeY = -1;

	// 向き
	bool m_dir = false;

	float m_rota;

	// 角度
	float m_angle = 0.0f;

	// アニメーションデータ
	// 列挙型
	enum AnimData
	{
		IDLE,
		WALKUP,
		WALKLEFTRIGHT,
		WALKDOWN,

		MAX,
	};

	// アニメーションをおこなっているかどうか
	bool m_isAnimData[AnimData::MAX];
	int m_animFirstFrameCount[AnimData::MAX];

	bool m_isAnimTemp[AnimData::MAX];

};

