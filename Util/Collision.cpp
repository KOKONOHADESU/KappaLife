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
    // 2つの円の中心間のベクトルの差を計算します
    // これは、2つの円の中心間の距離ベクトルを求めることを意味します
    float vecX = posX - posX2; // x座標の差
    float vecY = posY - posY2; // y座標の差

    // 2つの円の中心間の距離の二乗を計算します
    // ユークリッド距離の平方根を計算する代わりに、計算コストを削減するために二乗を使用します
    // 距離の二乗 (vecX^2 + vecY^2) を計算します
    float distSquared = vecX * vecX + vecY * vecY;

    // 2つの円の半径の和の二乗を計算します
    // これは、2つの円が接触するための最大距離を表します
    // (radius1 + radius2)^2 を計算します
    float radiusSumSquared = (radius + radius2) * (radius + radius2);

    // 距離の二乗が、半径の和の二乗より小さい場合、円は衝突していると判定します
    // 距離の二乗 < 半径の和の二乗 であれば、2つの円は重なっています
    if (distSquared < radiusSumSquared)
    {
        return true; // 衝突している
    }

    return false; // 衝突していない
}