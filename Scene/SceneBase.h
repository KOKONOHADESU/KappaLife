#pragma once

// ゲームシーンの基底クラス
class SceneBase
{
public:
	// コンストラクタ
	SceneBase() {}
	// デストラクタ
	virtual ~SceneBase() {}

	// 初期化
	virtual void Init() {}
	// 解放処理
	virtual void End() {}
	// 更新処理
	virtual SceneBase* Update() { return this; }
	// 描画
	virtual void Draw() {}
};

