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
	//1�ԉ��ɗ��������ǂ���
	bool isFallTheBottom();

	//1���Ƀu���b�N�����邩�ǂ���
	bool isMoveBelow();

	bool testTypeAndIsThere();

	//1�񑵂��������
	void erase();

	bool isMoveRight();
	bool isMoveLeft();

	void lower();


private:


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
		hen1,
		hen2,

		MinoMax
	};

	struct MinoData
	{
		int shape[4][4];

		int shape_90[4][4];
		int shape_180[4][4];
		int shape_270[4][4];
	};


	int m_minoNum;				//�~�m�̐����̃i���o�[

	MinoData m_minoData[MinoMax];

	int test[10][20];

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
};
