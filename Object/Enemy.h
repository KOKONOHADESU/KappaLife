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
public:
	int GetCollUpX() { return m_collPosUpX; }
	int GetCollUpY() { return m_collPosUpY; }
	int GetCollDownX() { return m_collPosDownX; }
	int GetCollDownY() { return m_collPosDownY; }

	float GetPosX() { return m_posX + 320 / 2; }
	float GetPosY() { return m_posY + 320 / 2; }

private:
	// �O���t�B�b�N�n���h��
	int m_hGraph;

	// ���W
	float m_posX;
	float m_posY;

	// ������������
	bool m_isUpDown;
	// �㉺�ړ��̃J�E���g
	int m_upDownCount;

	// �����蔻��p
	int m_collPosUpX;
	int m_collPosUpY;
	int m_collPosDownX;
	int m_collPosDownY;
};

