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

	//新しいミノを生成する
	void create();

	//1個下にブロックがあるかどうか
	bool isMoveBelow(int indexY);
	bool isMoveRight();
	bool isMoveLeft();

	bool testTypeAndIsThere(int x, int y);

	//指定した場所の回転した情報を取得する
	int getRotateMinoData(int x, int y, int rotateNum);


	//色の生成
	int createColor(int randomNum);

	bool isRotate(int indexX,int indexY);

	bool test3(int indexX, int indexY,int rotateNum);

	//下に落とすときの表示
	void putDisplayLower(int indexY);
	bool isDisplay(int display, int indexY);

	void isGameOver(int x, int y);

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

	enum RotateAngle : int 
	{
		shape0,
		shape90,
		shape180,
		shape270
	};


	//int m_minoNum;				//ミノの生成のナンバー

	MinoData m_minoData[MinoMax];
//	MinoData m_strageData[MinoMax];

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
	int m_nextRandom;			//次のミノのランダムの数

	int m_rotateNum;			//回転状態用の数

	int m_color;				//色
	int m_nextColor;

	bool m_isTest = false;
	bool m_isFallContinue = false;

	int m_testPosX = 0;

	bool m_next = false;

	int m_display = 0;

	bool m_isFallDisplay = false;


	int m_holdColor = 0;
	int m_holdMap[4][4];
	bool m_isHoldEnable;		//ホールドできるかどうか
	bool m_isHoldFirst;			//一番最小のホールドをしたかどうか
	int m_holdType;				//ホールドした形を保存

	bool m_isGameOver;			//ゲーム終了かどうか

	bool m_isHold = false;
	bool m_isOnce = false;

	int m_testY = 0;

	int m_temp = 0;
	bool m_isDisplay;

	int m_testPosY = 0;

	int m_blendTimer= 0;
};
