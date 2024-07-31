#pragma once

// エネミー
class Enemy
{
public:
	Enemy();
	virtual ~Enemy();

	void Init();
	void End();
	void Update();
	void Draw();
private:
	// グラフィックハンドル
	int m_hGraph;

	// 座標
	int m_posX;
	int m_posY;

	// うえかしかた
	bool m_isUpDown;
	// 上下移動のカウント
	int m_upDownCount;
};

