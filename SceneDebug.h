#pragma once
#include "SceneBase.h"
#include <vector>
#include <memory>

class SceneDebug : public SceneBase
{
public:
	SceneDebug(SceneManager& manager);
	virtual ~SceneDebug() {}

	void init();

	void update();
	void draw();

private:

	/// <summary>
	/// �l��ύX�ł��Ȃ��悤�� enum class ���g�p����(??)
	/// �V�[���J�ڔԍ�
	/// </summary>
	enum class SceneNo
	{
		SceneTitle,		// 0
		SceneMain,		// 1
		SceneResult,	// 2
		NotMatterLastNum     //�Ō�̐�(�֌W�͂Ȃ�)
	};


	int m_currentSceneSelect;	//���݂̃V�[���I��
	char m_display;

};

