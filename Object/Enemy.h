#pragma once

// �G�l�~�[
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
	// �O���t�B�b�N�n���h��
	int m_hGraph;

	// ���W
	int m_posX;
	int m_posY;

	// ������������
	bool m_isUpDown;
	// �㉺�ړ��̃J�E���g
	int m_upDownCount;
};

