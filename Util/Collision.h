#pragma once
class Collision
{
public:
	Collision() {};
	~Collision() {};

	// ŽlŠp“¯Žm‚Ì“–‚½‚è”»’è
	bool IsCheckSquare(int UpX,int UpY,int DownX,int DownY,
		int UpX2, int UpY2, int DownX2, int DownY2);

	bool IsCheckCircle(float posX, float posY, float radius,
		float posX2, float posY2, float radius2);
};

