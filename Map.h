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
	void setBlock(int x,int y);
	void erase();

	void testErase(int x, int y);

public:
	static const int kMapX = 10;		//横
	static const int kMapY = 20;		//縦
	static const int kMapSize = 30;		//1つのマップチップのサイズ

private:
	int m_map[kMapX][kMapY];

	int m_count;				//1列にミノが何個あるか
	bool m_isTest;

};

