#pragma once
class Map
{
public:
	Map();
	virtual ~Map();

	void init();
	void update();
	void draw();

	//�u���b�N�����邩�ǂ���
	bool isBlock(int x, int y);
	void setBlock(int x,int y,int color);
	void erase();

	//���ɗ��Ƃ�
	void lower(int strageY);

	void testColor(int x, int y);

	void getColor(int color);
//	void setColor(int x, int y);

public:
	static const int kMapX = 10;		//��
	static const int kMapY = 20;		//�c
	static const int kMapSize = 40;		//1�̃}�b�v�`�b�v�̃T�C�Y

	//�ǂ�����\�������邩
	static const int kDisplayX = 400;
	static const int kDisplayY = 100;

private:
	int m_map[kMapX][kMapY];

	int m_count;				//1��Ƀ~�m�������邩
	int m_color;				//�~�m�̐F
	bool m_isLineUP = false;


};

