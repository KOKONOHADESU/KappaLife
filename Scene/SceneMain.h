#pragma once

#include "SceneBase.h"

class Player;
class Enemy;

// メインシーンの管理
class SceneMain : public SceneBase
{
public:
	// コンストラクタ
	SceneMain();
	// デストラクタ
	virtual ~SceneMain();

	// 初期化
	void Init() override;
	// 解放処理
	void End()override;
	// 更新処理
	SceneMain* Update()override;
	// 描画
	void Draw()override;
private:
	Player* m_pPlayer;
	Enemy* m_pEnemy[50];
};