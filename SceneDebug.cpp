#include "SceneDebug.h"
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneResult.h"
#include "SceneManager.h"

#include "Pad.h"

#include <DxLib.h>

SceneDebug::SceneDebug(SceneManager& manager) :
	SceneBase(manager),
	m_currentSceneSelect(0),
	m_display(0)
{

}

void SceneDebug::init()
{
}


void SceneDebug::update()
{
	//�X�y�[�X�L�[
	if (Pad::isTrigger(PAD_INPUT_10))
	{
		if (m_currentSceneSelect == static_cast<int>(SceneNo::SceneTitle))
		{
			m_manager.changeScene(new SceneTitle(m_manager));
		}
		else if (m_currentSceneSelect == static_cast<int>(SceneNo::SceneMain))
		{
			m_manager.changeScene(new SceneMain(m_manager));
		}
		else if (m_currentSceneSelect == static_cast<int>(SceneNo::SceneResult))
		{
			m_manager.changeScene(new SceneResult(m_manager));
		}
	}

	if (Pad::isTrigger(PAD_INPUT_DOWN))
	{
		m_currentSceneSelect += 1;
	}
	else if (Pad::isTrigger(PAD_INPUT_UP))
	{
		m_currentSceneSelect -= 1;
	}

	//���ꏊ����

	if (m_currentSceneSelect >= static_cast<int>(SceneNo::NotMatterLastNum))
	{
		m_currentSceneSelect = 0;
	}
	if (m_currentSceneSelect < 0)
	{
		m_currentSceneSelect = static_cast<int>(SceneNo::NotMatterLastNum) - 1;	//�Ō�̐�-1�ɂ���
	}


	//return new  SceneTitle;
	//return new  SceneMain;

}

void SceneDebug::draw()
{
	int selectPosX = 100;
	int selectPosY = 100;

	DrawString(selectPosX, selectPosY + 50 * static_cast<int>(SceneNo::SceneTitle), "SceneTitle", 0xffffff);
	DrawString(selectPosX, selectPosY + 50 * static_cast<int>(SceneNo::SceneMain), "SceneMain", 0xffffff);
	DrawString(selectPosX, selectPosY + 50 * static_cast<int>(SceneNo::SceneResult), "SceneResult", 0xffffff);


	DrawString(selectPosX - 20, selectPosY + 50 * m_currentSceneSelect, "��", 0x0000ff);


}
