#pragma once
class Map
{
public:
	Map();
	virtual ~Map();

	void init();
	void update();
	void draw();

	//ブロックがあるかどうか
	bool isBlock(int x, int y);
	void setBlock(int x,int y,int color);
	void erase();

	//下に落とす
	void lower(int strageY);

	void testColor(int x, int y);

	void getColor(int color);
//	void setColor(int x, int y);

public:
	static const int kMapX = 10;		//横
	static const int kMapY = 20;		//縦
	static const int kMapSize = 40;		//1つのマップチップのサイズ

	//どこから表示させるか
	static const int kDisplayX = 400;
	static const int kDisplayY = 100;

private:
	int m_map[kMapX][kMapY];

	int m_count;				//1列にミノが何個あるか
	int m_color;				//ミノの色
	bool m_isLineUP = false;


};

