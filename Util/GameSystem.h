#pragma once

namespace GameSystem
{
#if _DEBUG
	// �E�B���h�E��ʂ��ǂ���
	constexpr bool kIsWindowMode = true;
#else
	// �E�B���h�E��ʂ��ǂ���
	constexpr bool kIsWindowMode = false;
#endif
	// ��ʃT�C�Y
	constexpr int kScreenSizeX = 1920;
	constexpr int kScreenSizeY = 1080;

	// ��ʃJ���[�̐[��
	constexpr int kColorBitDepths = 32;
}
