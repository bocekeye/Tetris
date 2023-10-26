#pragma once

class Map;

class MinoManager
{

public:
	MinoManager();
	virtual ~MinoManager(){}


	void init();
	void update();
	void draw();

	//void create();

	void setMap(Map* map) { m_pMap = map; }

	//�V�����~�m�𐶐�����
	void create();

	//1���Ƀu���b�N�����邩�ǂ���
	bool isMoveBelow();
	bool isMoveRight();
	bool isMoveLeft();


	bool testTypeAndIsThere(int x, int y);

	int getRotateMinoData(int x, int y, int rotateNum);

	bool isRotate();

	bool isHit(int minoX, int minoY, int minoAngle);

	void createColor(int randomNum);


public:

	enum
	{
		None,
		Red,
		White
	};

	/// <summary>
	/// �~�m�̎��
	/// </summary>
	enum MinoType : int
	{
		T,
		L,
		J,
		I,
		square,
		S,
		Z,

		MinoMax
	};

	struct MinoData
	{
		int shape[4][4];
		int shape90[4][4];
		int shape180[4][4];
		int shape270[4][4];
	};



	//int m_minoNum;				//�~�m�̐����̃i���o�[

	MinoData m_minoData[MinoMax];

private:


	Map* m_pMap;				//�}�b�v���g�����߂̃|�C���^
	
	int m_indexX;				//�ړ�X���W
	int m_indexY;				//�ړ�Y���W

	int m_fallInterval;			//�~�m�������鎞�ԊԊu
	bool m_isFallTheBottom;		//��ԉ��ɗ��������ǂ���

	bool m_isMoveRight;			//�E�Ɉړ��ł��邩
	bool m_isMoveLeft;			//���Ɉړ��ł��邩

	int m_count;				//1��Ƀ~�m�������邩�̐�
	int m_random;				//�������ꂽ�����_���̐�

	int m_rotateNum;			//��]��ԗp�̐�

	int m_color;				//�F

	bool m_isTest = false;
	bool m_isFallContinue = false;

	int testPosX = 0;
};
