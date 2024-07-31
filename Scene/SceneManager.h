#pragma once

class SceneBase;
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Init();
	void End();
	void Update();
	void Draw();
private:
	// シーンのポインタ
	SceneBase* m_pScene;
};

