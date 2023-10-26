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

	//新しいミノを生成する
	void create();

	//1個下にブロックがあるかどうか
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
	/// ミノの種類
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



	//int m_minoNum;				//ミノの生成のナンバー

	MinoData m_minoData[MinoMax];

private:


	Map* m_pMap;				//マップを使うためのポインタ
	
	int m_indexX;				//移動X座標
	int m_indexY;				//移動Y座標

	int m_fallInterval;			//ミノが落ちる時間間隔
	bool m_isFallTheBottom;		//一番下に落ちたかどうか

	bool m_isMoveRight;			//右に移動できるか
	bool m_isMoveLeft;			//左に移動できるか

	int m_count;				//1列にミノが何個あるかの数
	int m_random;				//生成されたランダムの数

	int m_rotateNum;			//回転状態用の数

	int m_color;				//色

	bool m_isTest = false;
	bool m_isFallContinue = false;

	int testPosX = 0;
};
