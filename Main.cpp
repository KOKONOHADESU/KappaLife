#include <DxLib.h>

#include "Util/GameSystem.h"

#include "Scene/SceneManager.h"

// �v���O������WinMain����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
    // window���[�h�ݒ�
    ChangeWindowMode(GameSystem::kIsWindowMode);

    // ��ʃT�C�Y�̐ݒ�
    SetGraphMode(GameSystem::kScreenSizeX, GameSystem::kScreenSizeY, GameSystem::kColorBitDepths);

    // �_�u���o�b�t�@���[�h
    SetDrawScreen(DX_SCREEN_BACK);

    // �c�w���C�u��������������
    if (DxLib_Init() == -1)
    {
        // �G���[���N�����璼���ɏI��
        return -1;
    }

    // �V�[���}�l�[�W���[�̃C���X�^���X����
    SceneManager* pSceneManager = new SceneManager();

    // ������
    pSceneManager->Init();

    while (ProcessMessage() == 0)
    {
        LONGLONG  time = GetNowHiPerformanceCount();

        // ��ʂ̃N���A
        ClearDrawScreen();

        // �X�V����
        pSceneManager->Update();
        // �`�揈��
        pSceneManager->Draw();

        // ����ʂ�\��ʂ����ւ���
        ScreenFlip();

        // esc�L�[����������I������
        if (CheckHitKey(KEY_INPUT_ESCAPE))
        {
            break;
        }

        // fps��60�ɌŒ�
        while (GetNowHiPerformanceCount() - time < 16667)
        {
        }
    }

    pSceneManager->End();

    delete pSceneManager;
    pSceneManager = nullptr;

    // �c�w���C�u�����g�p�̏I������
    DxLib_End();

    // �\�t�g�̏I�� 
    return 0;
}