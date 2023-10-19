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
	//1番下に落ちたかどうか
	bool isFallTheBottom();

	//1個下にブロックがあるかどうか
	bool isMoveBelow();

	bool testTypeAndIsThere();

	//1列揃ったら消す
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
	/// ミノの種類
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


	int m_minoNum;				//ミノの生成のナンバー

	MinoData m_minoData[MinoMax];

	int test[10][20];

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
};
