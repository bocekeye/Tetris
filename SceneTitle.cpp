#include "DxLib.h"
#include "game.h"

#include "SceneTitle.h"	
#include "SceneDebug.h"
#include "SceneMain.h"
#include "SceneManager.h"
#include "Pad.h"

#include <cmath>

namespace
{
	//�t�F�[�h�J�n�܂ł̎���
	constexpr int kFadeInterval = 120;
}


SceneTitle::SceneTitle(SceneManager& manager) :
	SceneBase(manager),
	m_updateFunc(&SceneTitle::fadeInUpdate),
	m_fadeTimer(kFadeInterval),
	m_fadeValue(255),
	m_fadeX(100),
	m_fadeY(0),
	m_period(120),
	m_swingWidth(100)
{

}

void SceneTitle::init()
{


}

void SceneTitle::update()
{
#ifdef _DEBUG

	(this->*m_updateFunc)();

#else

#endif

}

void SceneTitle::draw()
{

	DrawFormatString(100, 100, 0xffffff, "�e�g���X");

	//�����珑���摜�ƁA���łɕ`�悳��Ă���X�N���[���Ƃ�
	//�u�����h�̎d�����w�肵�Ă���B
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);	//(255:MAX,0:MIN)
	//����̏ꏊ��^�����ɓh��Ԃ�
	//DrawCircle(m_fadeX, m_fadeY, 100, 0x000000);
	DrawBox(static_cast<float>(Game::kScreenWidth) / 2, static_cast<float>(Game::kScreenHeight) / 2, m_fadeX, m_fadeY, 0x000000, true);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void SceneTitle::fadeInUpdate()
{
	//�^�������珙�X�ɕ\������ꍇ
	m_fadeValue = 255 * (static_cast<float>(m_fadeTimer) / static_cast<float>(kFadeInterval));
	//�O���f�[�V�������g���ď��X�ɕ\������ꍇ
	/*fadeTimer_;*/
	if (m_radius <= 0.0f)
	{
		m_updateFunc = &SceneTitle::normalUpdate;
		m_radius = 0.0f;
	}

	m_radius -= 5.0f;
	//printfDx("%f\n", m_radius);

	m_testTimer += 10.0f;
	float rad = m_testTimer * DX_PI_F / 180.0f;

	m_fadeX = static_cast<float>(Game::kScreenWidth) / 2.0f + (m_radius * cos(rad));
	m_fadeY = static_cast<float>(Game::kScreenHeight) / 2.0f + (m_radius * sin(rad));

}

void SceneTitle::normalUpdate()
{
	if (Pad::isTrigger(PAD_INPUT_1))
	{
		//m_updateFunc = &SceneTitle::fadeOutUpdate;
		m_manager.changeScene(new SceneDebug(m_manager));
		return;
	}
}

void SceneTitle::fadeOutUpdate()
{

	m_fadeValue = 255 * (static_cast<float>(m_fadeTimer) / static_cast<float>(kFadeInterval));
	if (++m_fadeTimer == kFadeInterval)
	{
		m_manager.changeScene(new SceneDebug(m_manager));
		return;
	}
}
