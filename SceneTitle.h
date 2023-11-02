#pragma once

#include "SceneBase.h"
#include "SceneManager.h"

class SceneTitle : public SceneBase
{
public:
	SceneTitle(SceneManager& manager);

	virtual ~SceneTitle() {}

	void init();

	void update();
	void draw();

private:

	//update�p�����o�֐��|�C���^
	void (SceneTitle::* m_updateFunc)();

	//�t�F�[�h�C���̎���Update�֐�
	void fadeInUpdate();
	//�ʏ��Ԃ�Update�֐�
	void normalUpdate();
	//�t�F�[�h�A�E�g�̎���Update�֐�
	void fadeOutUpdate();


	int m_fadeTimer;	//�t�F�[�h�^�C�}�[
	int m_fadeValue;				//����`�Ƃ̃u�����h�


	//�e�X�g
	int m_fadeX;
	int m_fadeY;
	int m_period;			//�U�ꕝ
	int m_swingWidth;		//����
	float m_testTimer = 0.0f;
	float m_radius = 1000.0f;			//���a


};
