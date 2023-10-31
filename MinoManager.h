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

	void setMap(Map* map) { m_pMap = map; }

	//�V�����~�m�𐶐�����
	void create();

	//1���Ƀu���b�N�����邩�ǂ���
	bool isMoveBelow(int indexY);
	bool isMoveRight();
	bool isMoveLeft();

	bool testTypeAndIsThere(int x, int y);

	//�w�肵���ꏊ�̉�]���������擾����
	int getRotateMinoData(int x, int y, int rotateNum);


	//�F�̐���
	int createColor(int randomNum);

	bool isRotate(int indexX,int indexY);

	bool test3(int indexX, int indexY,int rotateNum);

	//���ɗ��Ƃ��Ƃ��̕\��
	void putDisplayLower();
	bool isDisplay(int display);

	void isGameOver(int x, int y);

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

	enum RotateAngle : int 
	{
		shape0,
		shape90,
		shape180,
		shape270
	};


	//int m_minoNum;				//�~�m�̐����̃i���o�[

	MinoData m_minoData[MinoMax];
//	MinoData m_strageData[MinoMax];

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
	int m_nextRandom;			//���̃~�m�̃����_���̐�

	int m_rotateNum;			//��]��ԗp�̐�

	int m_color;				//�F
	int m_nextColor;

	bool m_isTest = false;
	bool m_isFallContinue = false;

	int m_testPosX = 0;

	bool m_next = false;

	int m_display = 1;

	bool m_isFallDisplay = false;


	int m_holdColor = 0;
	int m_holdMap[4][4];
	bool m_isHoldEnable;		//�z�[���h�ł��邩�ǂ���
	bool m_isHoldFirst;			//��ԍŏ��̃z�[���h���������ǂ���
	int m_holdType;				//�z�[���h�����`��ۑ�

	bool m_isGameOver;			//�Q�[���I�����ǂ���

	bool m_isHold = false;
	bool m_isOnce = false;

	int m_testY = 0;
};
