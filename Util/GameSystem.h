#pragma once

namespace GameSystem
{
#if _DEBUG
	// ウィンドウ画面かどうか
	constexpr bool kIsWindowMode = true;
#else
	// ウィンドウ画面かどうか
	constexpr bool kIsWindowMode = false;
#endif
	// 画面サイズ
	constexpr int kScreenSizeX = 1920;
	constexpr int kScreenSizeY = 1080;

	// 画面カラーの深さ
	constexpr int kColorBitDepths = 32;
}
