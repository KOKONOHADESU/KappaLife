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
	// �V�[���̃|�C���^
	SceneBase* m_pScene;
};

