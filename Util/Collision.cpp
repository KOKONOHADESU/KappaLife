#include "Collision.h"
#include <cmath>

bool Collision::IsCheckSquare(int UpX, int UpY, int DownX, int DownY, 
    int UpX2, int UpY2, int DownX2, int DownY2)
{
    if (DownX < UpX2) return false;
    if (UpX > DownX2) return false;
    if (DownY < UpY2) return false;
    if (UpY > DownY2) return false;

    return true;
}

bool Collision::IsCheckCircle(float posX, float posY, float radius,
    float posX2, float posY2, float radius2)
{
    // 2�̉~�̒��S�Ԃ̃x�N�g���̍����v�Z���܂�
    // ����́A2�̉~�̒��S�Ԃ̋����x�N�g�������߂邱�Ƃ��Ӗ����܂�
    float vecX = posX - posX2; // x���W�̍�
    float vecY = posY - posY2; // y���W�̍�

    // 2�̉~�̒��S�Ԃ̋����̓����v�Z���܂�
    // ���[�N���b�h�����̕��������v�Z�������ɁA�v�Z�R�X�g���팸���邽�߂ɓ����g�p���܂�
    // �����̓�� (vecX^2 + vecY^2) ���v�Z���܂�
    float distSquared = vecX * vecX + vecY * vecY;

    // 2�̉~�̔��a�̘a�̓����v�Z���܂�
    // ����́A2�̉~���ڐG���邽�߂̍ő勗����\���܂�
    // (radius1 + radius2)^2 ���v�Z���܂�
    float radiusSumSquared = (radius + radius2) * (radius + radius2);

    // �����̓�悪�A���a�̘a�̓���菬�����ꍇ�A�~�͏Փ˂��Ă���Ɣ��肵�܂�
    // �����̓�� < ���a�̘a�̓�� �ł���΁A2�̉~�͏d�Ȃ��Ă��܂�
    if (distSquared < radiusSumSquared)
    {
        return true; // �Փ˂��Ă���
    }

    return false; // �Փ˂��Ă��Ȃ�
}