#pragma once

#include <deque>

class SceneBase;

//�V�[���Ď��N���X
class SceneManager
{
public:

	/// <summary>
	/// �V�[���̐؂�ւ����s��
	/// </summary>
	/// <param name="scene">�؂�ւ��������̃V�[���̃A�h���X</param>
	void changeScene(SceneBase* scene);

	/// <summary>
	/// �V�[������ɐς�
	/// Update�Ŏ��s�����̂͏�ɂ܂ꂽ�V�[���̂�
	/// </summary>
	/// <param name="scene"></param>
	void pushScene(SceneBase* scene);

	/// <summary>
	/// ��ԏ�̃V�[�����폜����
	/// �������A���̌��ʃX�^�b�N����ɂȂ邱�Ƃ̂Ȃ��悤��
	/// </summary>
	void popScene();

	/// <summary>
	/// �e�V�[���̏��������s��
	/// </summary>
	void init();

	/// <summary>
	/// �e�V�[���̍X�V���s��
	/// </summary>
	/// <param name="input">���̓X�e�[�g</param>
	void update();
	/// <summary>
	/// �e�V�[���̕`����s��
	/// </summary>
	void draw();

private:
	//�����s���̃V�[����؂�ւ��Ă��������̂�	
	//�Q�Ƃł͂Ȃ��|�C���^�Ƃ��Đ錾
	std::deque<SceneBase*> m_scene;
};

