#pragma once
class SceneManager;

// �Q�[���V�[�����N���X
class SceneBase
{
public:
	SceneBase(SceneManager& manager);

	virtual ~SceneBase() {}

	virtual void init() = 0;

	virtual void update() = 0;
	virtual void draw() = 0;

protected:
	SceneManager& m_manager;		//�V�[���}�l�[�W���[�ւ̎Q��

};
