#pragma once

#include "SceneBase.h"

// リザルトシーンの管理
class SceneResult : public SceneBase
{
public:
	// コンストラクタ
	SceneResult();
	// デストラクタ
	virtual ~SceneResult();

	// 初期化
	void Init() override;
	// 解放処理
	void End()override;
	// 更新処理
	SceneBase* Update()override;
	// 描画
	void Draw()override;
};