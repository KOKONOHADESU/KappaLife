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
public:
	int GetCollUpX() { return m_collPosUpX; }
	int GetCollUpY() { return m_collPosUpY; }
	int GetCollDownX() { return m_collPosDownX; }
	int GetCollDownY() { return m_collPosDownY; }

	float GetPosX() { return m_posX + 320 / 2; }
	float GetPosY() { return m_posY + 320 / 2; }

private:
	// グラフィックハンドル
	int m_hGraph;

	// 座標
	float m_posX;
	float m_posY;

	// うえかしかた
	bool m_isUpDown;
	// 上下移動のカウント
	int m_upDownCount;

	// 当たり判定用
	int m_collPosUpX;
	int m_collPosUpY;
	int m_collPosDownX;
	int m_collPosDownY;
};

