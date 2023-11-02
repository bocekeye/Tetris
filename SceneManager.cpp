#include "SceneManager.h"
#include "SceneBase.h"
#include "SceneTitle.h"
#include "SceneDebug.h"
#include "Pad.h"
#include <cassert>

void SceneManager::changeScene(SceneBase* scene)
{
	//�V�[���X�^�b�N����ł͂Ȃ�������
	if (!m_scene.empty())
	{
		delete m_scene.front();			//top�͂Ă��؂�̗v�f��Ԃ��Ă�
		m_scene.pop_front();			//1���� -> �ӂ���0�ɂȂ�
	}
	m_scene.push_front(scene);			//1������
}

void SceneManager::pushScene(SceneBase* scene)
{
	m_scene.push_front(scene);			//1������
}

void SceneManager::popScene()
{
	//�|�b�v�̌��ʁA�V�[����0�ɂȂ�Ȃ��悤�ɂ���
	if (m_scene.size() > 1)
	{
		delete m_scene.front();
		m_scene.pop_front();
	}
}

void SceneManager::init()
{
	m_scene.front()->init();
}

void SceneManager::update()
{
	m_scene.front()->update();
}

void SceneManager::draw()
{
	for (int i = m_scene.size() - 1; i >= 0; i--)
	{
		m_scene[i]->draw();
	}
}
