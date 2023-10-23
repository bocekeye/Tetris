
#include "Pad.h"
#include "game.h"

#include "MinoManager.h"
#include "Map.h"
#include <DxLib.h>

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウモード設定
	ChangeWindowMode(Game::kWindowMode);
	//ウィンドウモード名設定
	SetMainWindowText(Game::kTitleText);
	//画面のサイズ
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			    // エラーが起きたら直ちに終了
	}
	
	//ダブルバッファモード
	SetDrawScreen(DX_SCREEN_BACK);

	MinoManager* mino;
	mino = new MinoManager;
	mino->init();
	Map* map;
	map = new Map;
	map->init();

	while (ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();

		//画面の表示
		ClearDrawScreen();
		
		Pad::update();

		mino->setMap(map);

		mino->update();
		mino->draw();

		map->draw();

		//裏画面を表画面を入れ替える
		ScreenFlip();

		//escキーを押したら終了
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		while (GetNowHiPerformanceCount() - time < 1667)
		{

		}

	}


	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				    // ソフトの終了 
}
