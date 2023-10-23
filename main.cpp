
#include "Pad.h"
#include "game.h"

#include "MinoManager.h"
#include "Map.h"
#include <DxLib.h>

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
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

	MinoManager* mino;
	mino = new MinoManager;
	mino->init();
	Map* map;
	map = new Map;
	map->init();

	while (ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();

		//��ʂ̕\��
		ClearDrawScreen();
		
		Pad::update();

		mino->setMap(map);

		mino->update();
		mino->draw();

		map->draw();

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
