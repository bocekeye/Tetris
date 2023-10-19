#include "MinoManager.h"
#include "Map.h"
#include <random>
#include <DxLib.h>
#include "Pad.h"

MinoManager::MinoManager():
	m_indexX(4),
	m_indexY(0),
	m_fallInterval(0),
	m_count(0),
	m_isMoveRight(false),
	m_isMoveLeft(false),
	m_isFallTheBottom(false),
	m_random(MinoType::square)
{	
	for (int y = 0; y < Map::kMapY; y++)
	{
		for (int x = 0; x < Map::kMapX; x++)
		{
			test[x][y] = None;
		}
	}

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
				{0,1,0,0},
				{0,1,0,0},
				{0,1,0,0},
				{0,1,0,0},
			},
			{
				{0,0,0,0},
				{1,1,1,1},
				{0,0,0,0},
				{0,0,0,0},
			},
			{
				{0,1,0,0},
				{0,1,0,0},
				{0,1,0,0},
				{0,1,0,0},
			},
			{
				{0,0,0,0},
				{1,1,1,1},
				{0,0,0,0},
				{0,0,0,0},
			},
		};
//	else if (m_minoNum == MinoType::square)
	
		m_minoData[MinoType::square] =
		{
			{
				{0,0,0,0},
				{0,1,1,0},
				{0,1,1,0},
				{0,0,0,0},
			},
			{
				{0,0,0,0},
				{0,1,1,0},
				{0,1,1,0},
				{0,0,0,0},
			},
			{
				{0,0,0,0},
				{0,1,1,0},
				{0,1,1,0},
				{0,0,0,0},
			},
			{
				{0,0,0,0},
				{0,1,1,0},
				{0,1,1,0},
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
	
}

void MinoManager::update()
{

	if (Pad::isTrigger(PAD_INPUT_DOWN))
	{	
		if (isMoveBelow())
		{
			m_indexY++;
		}
		else
		{
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					if (m_minoData[m_random].shape[x][y] == 1)
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
	
#if false
	if (m_fallInterval++ >= 60)
	{
		//	m_indexY += 1;
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				m_minoData[m_random].shape[x][y] = 1;
			}
		}

		m_fallInterval = 0;
	}
	if (Pad::isTrigger(PAD_INPUT_RIGHT))
	{
		if (isMoveRight())
		{
			m_pMap->testErase(m_indexX, m_indexY);
			m_indexX += 1;
		}
		
	}
	else if (Pad::isTrigger(PAD_INPUT_LEFT))
	{
		if (isMoveLeft())
		{
			m_pMap->testErase(m_indexX, m_indexY);
			m_indexX -= 1;
		}
	}
	else if (Pad::isTrigger(PAD_INPUT_DOWN))
	{
		if (isMoveBelow())
		{
			m_pMap->testErase(m_indexX, m_indexY);
			m_indexY += 1;
		}
	}
#endif
//	m_pMap->setBlock(m_indexX, m_indexY);
	//m_pMap->erase();

	
//	erase();

	

}

void MinoManager::draw()
{
#if false
	for (int y = 0; y < Map::kMapY; y++)
	{
		for (int x = 0; x < Map::kMapX; x++)
		{
			if (m_pMap->isBlock(x,y))
			{
				int posX = x * Map::kMapSize;
				int posY = y * Map::kMapSize;
				DrawBox(posX, posY + 100, posX + Map::kMapSize, y * Map::kMapSize + 100 + Map::kMapSize, 0xff0000, true);
			}
		}
	}
#else
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (testTypeAndIsThere(x,y))
			{
				int posX = (m_indexX + x) * Map::kMapSize;
				int posY = (m_indexY + y) * Map::kMapSize;
				DrawBox(posX, posY + 100, posX + Map::kMapSize, posY + 100 + Map::kMapSize, 0xff0000, true);
			}
		}
	}
#endif

#ifdef _DEBUG

	DrawFormatString(500, 60, 0xffffff, "m_indexX = %d", m_indexX);
	DrawFormatString(500, 80, 0xffffff, "m_indexY = %d", m_indexY);
	DrawFormatString(500, 100, 0xffffff, "m_count = %d", m_count);

	if (isMoveBelow())
	{
		DrawString(500, 120, "TRUE", 0xffffff);
	}
	DrawFormatString(500, 140, 0xffffff, "m_random = %d", m_random);

#endif
}

void MinoManager::create()
{
	if (!isMoveBelow())
	{
		//ランダム計算
		std::random_device rd;
		std::mt19937 mt(rd());
		//0～6までの数字をランダム生成
		std::uniform_int_distribution<int> rdt(MinoType::T, MinoType::hen2);
	//	m_random = rdt(mt);

		m_indexX = 4;
		m_indexY = 0;
	}
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
#if true
	//いずれかがの条件(？)
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (testTypeAndIsThere(x, y))
			{
				int posX = (m_indexX + x);
				int posY = (m_indexY + y);

				//移動制限
				if (posY >= Map::kMapY - 2)
				{
					return false;
				}
				//1つ下にブロックがあった場合
				if (m_pMap->isBlock(posX, posY + 1))
				{
					return false;
				}

				return true;
			}
		}
	}	
#else
	if (m_indexY >= Map::kMapY - 1)
	{
		return false;
	}
	//1つ下にブロックがあった場合
	if (m_pMap->isBlock(m_indexX, m_indexY + 1))
	{
		return false;
	}
	return true;
#endif
	

}


bool MinoManager::testTypeAndIsThere(int x, int y)
{
	int posX = x + m_indexX;
	int posY = y + m_indexY;

	if (m_minoData[m_random].shape[x][y] == 1)
	{
		return true;
	}

	return false;
}


void MinoManager::erase()
{
	/*int strageY = 0;
	for (int y = 0; y < Map::kMapY; y++)
	{
		m_count = 0;
		for (int x = 0; x < Map::kMapX; x++)
		{
			if (test[x][y] == White)
			{
				m_count += 1;
				strageY = y;
			}
		}
	}

	if (m_count == 10)
	{
		for (int x = 0; x < Map::kMapX; x++)
		{
			test[x][strageY] = None;
		}
		lower();
	}
	*/
}

bool MinoManager::isMoveRight()
{
	if (m_indexX >= Map::kMapX - 1)
	{
		return false;
	}
	if (m_pMap->isBlock(m_indexX + 1, m_indexY))
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool MinoManager::isMoveLeft()
{
	//範囲外
	if (m_indexX <= 0)
	{
		return false;
	}
	if (m_pMap->isBlock(m_indexX - 1, m_indexY))
	{
		return false;
	}
	else
	{
		return true;
	}
}

void MinoManager::lower()
{
	for (int y = Map::kMapY - 2 ; y > 0 ; y--)
	{
		for (int x = 0; x < Map::kMapX; x++)
		{
			if (test[x][y] == 2)
			{
				if (test[x][y + 1] == 0)
				{
					test[x][y] = 0;
					test[x][y + 1] = 2;
				}
			}
		}
	}
}
