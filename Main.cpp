#include <DxLib.h>

#include "Util/GameSystem.h"

#include "Scene/SceneManager.h"

// プログラムはWinMainから始まります
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
    // windowモード設定
    ChangeWindowMode(GameSystem::kIsWindowMode);

    // 画面サイズの設定
    SetGraphMode(GameSystem::kScreenSizeX, GameSystem::kScreenSizeY, GameSystem::kColorBitDepths);

    // ダブルバッファモード
    SetDrawScreen(DX_SCREEN_BACK);

    // ＤＸライブラリ初期化処理
    if (DxLib_Init() == -1)
    {
        // エラーが起きたら直ちに終了
        return -1;
    }

    // シーンマネージャーのインスタンス生成
    SceneManager* pSceneManager = new SceneManager();

    // 初期化
    pSceneManager->Init();

    while (ProcessMessage() == 0)
    {
        LONGLONG  time = GetNowHiPerformanceCount();

        // 画面のクリア
        ClearDrawScreen();

        // 更新処理
        pSceneManager->Update();
        // 描画処理
        pSceneManager->Draw();

        // 裏画面を表画面を入れ替える
        ScreenFlip();

        // escキーを押したら終了する
        if (CheckHitKey(KEY_INPUT_ESCAPE))
        {
            break;
        }

        // fpsを60に固定
        while (GetNowHiPerformanceCount() - time < 16667)
        {
        }
    }

    pSceneManager->End();

    delete pSceneManager;
    pSceneManager = nullptr;

    // ＤＸライブラリ使用の終了処理
    DxLib_End();

    // ソフトの終了 
    return 0;
}