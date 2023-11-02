#include "SceneManager.h"
#include "SceneDebug.h"
#include "Pad.h"
#include "game.h"

#include "MinoManager.h"

#include "Map.h"
#include <DxLib.h>

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//背景色
	SetBackgroundColor(128, 128, 128, 1);

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

	SceneManager sceneManager;
#ifdef _DEBUG
	sceneManager.changeScene(new SceneDebug(sceneManager));
#else
	sceneManager.changeScene(new SceneTitle(sceneManager));
#endif

	/*MinoManager* mino;
	mino = new MinoManager;

	Map* map;
	map = new Map;

	mino->setMap(map);
	mino->init();
	map->init();*/

	while (ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();

		//画面の表示
		ClearDrawScreen();
		
		Pad::update();

		sceneManager.update();
		sceneManager.draw();

		/*mino->update();
		mino->draw();

		map->draw();*/

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
