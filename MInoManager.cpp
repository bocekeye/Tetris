#include "MinoManager.h"
#include "Map.h"
#include <random>
#include <DxLib.h>
#include "Pad.h"

//m_indexXとm_indexYが１つずつずれている

MinoManager::MinoManager():
	m_indexX(0),
	m_indexY(0),
	m_fallInterval(0),
	m_count(0),
	m_isMoveRight(false),
	m_isMoveLeft(false),
	m_isFallTheBottom(false),
	m_rotateNum(0),
	m_color(0)
{	
}

void MinoManager::init()
{
	//if (m_minoNum == MinoType::T)
	
		m_minoData[MinoType::T] =
		{
			{
				{0,1,0,0},
				{1,1,1,0},
				{0,0,0,0},
				{0,0,0,0},
			},
			{
				{0,1,0,0},
				{0,1,1,0},
				{0,1,0,0},
				{0,0,0,0},
			},
			{
				{0,0,0,0},
				{1,1,1,0},
				{0,1,0,0},
				{0,0,0,0},
			},
			{
				{0,1,0,0},
				{1,1,0,0},
				{0,1,0,0},
				{0,0,0,0},
			},
		};
	
//	else if (m_minoNum == MinoType::L)
	
		m_minoData[MinoType::L] =
		{
			{
				{0,0,1,0},
				{1,1,1,0},
				{0,0,0,0},
				{0,0,0,0},
			},
			{
				{0,1,0,0},
				{0,1,0,0},
				{0,1,1,0},
				{0,0,0,0},
			},
			{
				{0,0,0,0},
				{1,1,1,0},
				{1,0,0,0},
				{0,0,0,0},
			},
			{
				{1,1,0,0},
				{0,1,0,0},
				{0,1,0,0},
				{0,0,0,0},
			},
		};
	
//	else if (m_minoNum == MinoType::J)
	
		m_minoData[MinoType::J] =
		{
			{
				{1,0,0,0},
				{1,1,1,0},
				{0,0,0,0},
				{0,0,0,0},
			},
			{
				{0,1,1,0},
				{0,1,0,0},
				{0,1,0,0},
				{0,0,0,0},
			},
			{
				{0,0,0,0},
				{1,1,1,0},
				{0,0,1,0},
				{0,0,0,0},
			},
			{
				{0,1,0,0},
				{0,1,0,0},
				{1,1,0,0},
				{0,0,0,0},
			},
		};

		m_minoData[MinoType::I] =
		{
			{
				{1,0,0,0},
				{1,0,0,0},
				{1,0,0,0},
				{1,0,0,0},
			},
			{
				{0,0,0,0},
				{1,1,1,1},
				{0,0,0,0},
				{0,0,0,0},
			},
			{
				{1,0,0,0},
				{1,0,0,0},
				{1,0,0,0},
				{1,0,0,0},
			},
			{
				{1,1,1,1},
				{0,0,0,0},
				{0,0,0,0},
				{0,0,0,0},
			},
		};
//	else if (m_minoNum == MinoType::square)
	
		m_minoData[MinoType::square] =
		{
			{
				{1,1,0,0},
				{1,1,0,0},
				{0,0,0,0},
				{0,0,0,0},
			},
			{
				{1,1,0,0},
				{1,1,0,0},
				{0,0,0,0},
				{0,0,0,0},
			},
		{
				{1,1,0,0},
				{1,1,0,0},
				{0,0,0,0},
				{0,0,0,0},
			},
			{
				{1,1,0,0},
				{1,1,0,0},
				{0,0,0,0},
				{0,0,0,0},
			},
		};
	
//	else if (m_minoNum == MinoType::hen1)
	
		m_minoData[MinoType::hen1] =
		{
			{
				{0,1,1,0},
				{1,1,0,0},
				{0,0,0,0},
				{0,0,0,0},
			},
			{
				{0,1,0,0},
				{0,1,1,0},
				{0,0,1,0},
				{0,0,0,0},
			},
			{
				{0,0,0,0},
				{0,1,1,0},
				{1,1,0,0},
				{0,0,0,0},
			},
			{
				{1,0,0,0},
				{1,1,0,0},
				{0,1,0,0},
				{0,0,0,0},
			},
		};
	
//	else if (m_minoNum == MinoType::hen2)
	
		m_minoData[MinoType::hen2] =
		{
			{
				{1,1,0,0},
				{0,1,1,0},
				{0,0,0,0},
				{0,0,0,0},
			},
			{
				{0,0,1,0},
				{0,1,1,0},
				{0,1,0,0},
				{0,0,0,0},
			},
			{
				{0,0,0,0},
				{1,1,0,0},
				{0,1,1,0},
				{0,0,0,0},
			},
			{
				{0,1,0,0},
				{1,1,0,0},
				{1,0,0,0},
				{0,0,0,0},
			},
		};
	create();
}

void MinoManager::update()
{
	if (m_fallInterval++ >= 60)
	{
		if (isMoveBelow())
		{
			m_indexY++;
		}
		else
		{
			for(int y = 3; y >= 0; y--)
			{
				for (int x = 0; x < 4; x++)
				{
					if (testTypeAndIsThere(x, y))
					{
						int posX = x + m_indexX;
						int posY = y + m_indexY;
						m_pMap->setBlock(posX, posY);
					}
				}
			}
			create();
		}
		m_fallInterval = 0;
	}

	if (Pad::isTrigger(PAD_INPUT_DOWN))
	{	
		if (isMoveBelow())
		{
			m_indexY++;
		}
		else
		{
			for (int y = 3; y >= 0; y--)
			{
				for (int x = 0; x < 4; x++)
				{
					if (testTypeAndIsThere(x, y))
					{
						int posX = x + m_indexX;
						int posY = y + m_indexY;
						m_pMap->setBlock(posX, posY);
					}
				}
			}
			create();
		}
	}
	
	if (Pad::isTrigger(PAD_INPUT_RIGHT))
	{
		if (isMoveRight())
		{
			m_indexX += 1;
		}
	}
	if (Pad::isTrigger(PAD_INPUT_LEFT))
	{
		if (isMoveLeft())
		{
			m_indexX -= 1;
		}	
	}
	//回転
	if (Pad::isTrigger(PAD_INPUT_UP))
	{
		if (isRotate())
		{
			
		}

		m_rotateNum += 1;

		if (m_rotateNum > 3)
		{
			m_rotateNum = 0;
		}
	}

	m_pMap->erase();


	
}

void MinoManager::draw()
{
	for(int y = 3; y >= 0; y--)
	{
		for (int x = 0; x < 4; x++)
		{
			//本体
			if (testTypeAndIsThere(x,y))
			{
				int posX = (m_indexX + x) * Map::kMapSize;
				int posY = (m_indexY + y) * Map::kMapSize;
				DrawBox(posX + 100, posY + 100, posX + Map::kMapSize + 100, posY + 100 + Map::kMapSize, m_color, true);
			}
			//本体ではない初期化で定義した二次元配列の"0"の部分
			else
			{
				int posX = (m_indexX + x) * Map::kMapSize;
				int posY = (m_indexY + y) * Map::kMapSize;
				DrawBox(posX + 100, posY + 100, posX + Map::kMapSize + 100, posY + 100 + Map::kMapSize, 0x0000ff, true);
			}
		}
	}

#ifdef _DEBUG

	DrawFormatString(500, 60, 0xffffff, "m_indexX = %d", m_indexX);
	DrawFormatString(500, 80, 0xffffff, "m_indexY = %d", m_indexY);


	if (isMoveBelow())
	{
		DrawString(500, 120, "TRUE", 0xffffff);
	}
	DrawFormatString(500, 140, 0xffffff, "m_random = %d", m_random);

#endif
}

void MinoManager::create()
{	
	//ランダム計算
	std::random_device rd;
	std::mt19937 mt(rd());
	//0～6までの数字をランダム生成
	std::uniform_int_distribution<int> rdt(MinoType::T, MinoType::hen2);

	m_indexX = 4;
	m_indexY = 0;	
	m_rotateNum = 0;
	//m_random = MinoType::square;
	//m_random = MinoType::I;
	m_random = rdt(mt);
	createColor(m_random);
}

/// <summary>
/// 一番下に落ちたかどうか
/// </summary>
/// <returns></returns>
bool MinoManager::isFallTheBottom()
{
	if (m_indexY == Map::kMapY - 1)
	{		
		return true;
	}
	return false;
}

/// <summary>
/// 1個下にブロックを移動できるかどうか
/// </summary>
/// <returns></returns>
bool MinoManager::isMoveBelow()
{
	//いずれかがの条件(？)
	for(int y = 3; y >= 0; y--)
	{
		for (int x = 0; x < 4; x++)
		{
			if (testTypeAndIsThere(x, y))
			{
				int posX = (m_indexX + x);
				int posY = (m_indexY + y);

				//移動制限
				if (posY >= Map::kMapY - 1)
				{
					return false;
				}
				//1つ下にブロックがあった場合
				if (m_pMap->isBlock(posX, posY + 1))
				{
					return false;
				}
			}
		}
	}	
	return true;
}

/// <summary>
/// 右に移動できるかどうか
/// </summary>
/// <returns></returns>
bool MinoManager::isMoveRight()
{
	for(int y = 3; y >= 0; y--)
	{
		for (int x = 0; x < 4; x++)
		{
			if (testTypeAndIsThere(x, y))
			{
				int posX = (m_indexX + x);
				int posY = (m_indexY + y);

				//移動制限
				if (posX >= Map::kMapX - 1)
				{
					return false;
				}
				if (m_pMap->isBlock(posX + 1, posY))
				{
					return false;
				}
			}
		}
	}
	return true;
}

/// <summary>
/// 左に移動できるかどうか
/// </summary>
/// <returns></returns>
bool MinoManager::isMoveLeft()
{
	for(int y = 3; y >= 0; y--)
	{
		for (int x = 0; x < 4; x++)
		{
			if (testTypeAndIsThere(x, y))
			{
				int posX = (m_indexX + x);
				int posY = (m_indexY + y);

				//移動制限
				if (posX <= 0)
				{
					return false;
				}
				if (m_pMap->isBlock(posX - 1, posY))
				{
					return false;
				}
			}
		}
	}
	return true;
}

/// <summary>
/// 回転できるかどうか
/// </summary>
/// <returns></returns>
bool MinoManager::isRotate()
{

	return false;
}

void MinoManager::createColor(int randomNum)
{
	if (randomNum == MinoType::T)
	{
		m_color = 0xa260bf;
	}
	else if (randomNum == MinoType::T)
	{
		m_color = 0xa260bf;
	}
	else if (randomNum == MinoType::T)
	{
		m_color = 0xa260bf;
	}
	else if (randomNum == MinoType::T)
	{
		m_color = 0xa260bf;
	}
	else if (randomNum == MinoType::T)
	{
		m_color = 0xa260bf;
	}
	else if (randomNum == MinoType::T)
	{
		m_color = 0xa260bf;
	}
}

bool MinoManager::testTypeAndIsThere(int x, int y)
{
	int posX = x + m_indexX;
	int posY = y + m_indexY;

	if (m_rotateNum == 0)
	{
		if (m_minoData[m_random].shape[x][y] == 1)
		{
			return true;
		}
	}
	else if (m_rotateNum == 1)
	{
		if (m_minoData[m_random].shape90[x][y] == 1)
		{
			return true;
		}
	}
	else if (m_rotateNum == 2)
	{
		if (m_minoData[m_random].shape180[x][y] == 1)
		{
			return true;
		}
	}
	else if (m_rotateNum == 3)
	{
		if (m_minoData[m_random].shape270[x][y] == 1)
		{
			return true;
		}
	}

	return false;
}