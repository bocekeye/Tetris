#include "SceneManager.h"
#include "SceneDebug.h"
#include "Pad.h"
#include "game.h"

#include "MinoManager.h"

#include "Map.h"
#include <DxLib.h>

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�w�i�F
	SetBackgroundColor(128, 128, 128, 1);

	//�E�B���h�E���[�h�ݒ�
	ChangeWindowMode(Game::kWindowMode);
	//�E�B���h�E���[�h���ݒ�
	SetMainWindowText(Game::kTitleText);
	//��ʂ̃T�C�Y
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			    // �G���[���N�����璼���ɏI��
	}
	
	//�_�u���o�b�t�@���[�h
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

		//��ʂ̕\��
		ClearDrawScreen();
		
		Pad::update();

		sceneManager.update();
		sceneManager.draw();

		/*mino->update();
		mino->draw();

		map->draw();*/

		//����ʂ�\��ʂ����ւ���
		ScreenFlip();

		//esc�L�[����������I��
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		while (GetNowHiPerformanceCount() - time < 1667)
		{

		}

	}


	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				    // �\�t�g�̏I�� 
}
