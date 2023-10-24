#include "MinoManager.h"
#include "Map.h"
#include <random>
#include <DxLib.h>
#include "Pad.h"

MinoManager::MinoManager() :
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
			{1,1,1,1},
			{0,0,0,0},
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
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
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

	m_minoData[MinoType::S] =
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

	m_minoData[MinoType::Z] =
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
	/*if (m_fallInterval++ >= 60)
	{
		if (isMoveBelow())
		{
			m_indexY++;
		}
		else
		{
			for (int x = 0; x < 4; x++)
			{
				for (int y = 0; y < 4; y++)
				{
					if (testTypeAndIsThere(x, y))
					{
						int posX = x + m_indexX;
						int posY = y + m_indexY;
						m_pMap->setBlock(posX, posY, m_random);
					}
				}
			}
			create();
		}
		m_fallInterval = 0;
	}*/


	if (Pad::isTrigger(PAD_INPUT_DOWN))
	{
		if (isMoveBelow())
		{
			m_indexY++;
		}
		else
		{
			for (int x = 0; x < 4; x++)
			{
				for (int y = 0; y < 4; y++)
				{
					if (testTypeAndIsThere(x, y))
					{
						int posX = x + m_indexX;
						int posY = y + m_indexY;
						m_pMap->setBlock(posX, posY, m_random);
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
			if (!m_isTest)
			{
				m_rotateNum += 1;
				//testPosX = 0;
			}
			else
			{
				if (m_rotateNum == 3)
				{

				}
				m_indexX += testPosX;
				m_rotateNum += 1;
			}
		}
		if (m_rotateNum > 3)
		{
			m_rotateNum = 0;
		}
	}

	if (Pad::isTrigger(PAD_INPUT_10))
	{
		m_isFallContinue = true;
	}
	//落とせるところまで落とす
	if (m_isFallContinue)
	{
		if (isMoveBelow())
		{
			m_indexY++;
		}
		else
		{
			for (int x = 0; x < 4; x++)
			{
				for (int y = 0; y < 4; y++)
				{
					if (testTypeAndIsThere(x, y))
					{
						int posX = x + m_indexX;
						int posY = y + m_indexY;
						m_pMap->setBlock(posX, posY, m_random);
					}
				}
			}
			create();
			m_isFallContinue = false;
		}
	}

	m_pMap->erase();
	m_pMap->getColor(m_color);

#if _DEBUG
	//if (isRotate())
	//{
	//	m_isTest = false; 
	//}

#endif
}

void MinoManager::draw()
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			//本体
			if (testTypeAndIsThere(x, y))
			{
				int posX = (m_indexX + x + testPosX) * Map::kMapSize;
				int posY = (m_indexY + y) * Map::kMapSize;
				DrawBox(posX + 100, posY + 100, posX + Map::kMapSize + 100, posY + 100 + Map::kMapSize, m_color, true);
			}
		}
	}

#ifdef _DEBUG

	DrawFormatString(500, 100, 0xffffff, "m_indexX = %d", m_indexX);
	DrawFormatString(500, 120, 0xffffff, "m_indexY = %d", m_indexY);
	DrawFormatString(500, 140, 0xffffff, "m_random = %d", m_random);
	DrawFormatString(500, 160, 0xffffff, "m_rotateNum = %d", m_rotateNum);

	if (isRotate())
	{
		DrawString(500, 200, "回転 = TRUE", 0xffffff);
	}
	else
	{
		DrawString(500, 200, "回転 = FALSE", 0xffffff);
	}
	if (m_isTest)
	{
		DrawString(500, 220, "ずらし = TRUE", 0xffffff);
	}
	else
	{
		DrawString(500, 220, "ずらし = FALSE", 0xffffff);
	}

#endif
}

void MinoManager::create()
{
	//ランダム計算
	std::random_device rd;
	std::mt19937 mt(rd());
	//0～6までの数字をランダム生成
	std::uniform_int_distribution<int> rdt(MinoType::T, MinoType::Z);
	m_indexX = 4;
	m_indexY = 0;
	m_rotateNum = 0;
	//m_random = MinoType::S;
	m_random = MinoType::I;
	//m_random = rdt(mt);
	createColor(m_random);
}

/// <summary>
/// 1個下にブロックを移動できるかどうか
/// </summary>
/// <returns></returns>
bool MinoManager::isMoveBelow()
{
	//いずれかがの条件(？)
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
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
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
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
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
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
	int kariPosX = 0;
	int kariPosY = 0;
	int testX = 0; 
	int testY = 0;

	//struct indexData
	//{
	//	int posX;
	//	int posY;
	//};

	//constexpr indexData offset[8] =
	//{
	//	{1,0},
	//	{-1,0},
	//	{0,1},
	//	{1,0},
	//	{1,1},
	//	{1,-1},
	//	{-1,1},
	//	{-1,-1},
	//};

	for (int y = 3; y >= 0; y--)
	{
		for (int x = 0; x < 4; x++)
		{
			//次の回転先の状態で比べる
			if (getRotateMinoData(x, y, m_rotateNum + 1) == 1)
			{
				int posX = x + m_indexX;
				int posY = y + m_indexY;
				m_isTest = false;
				//ブロックがある場合
				if (m_pMap->isBlock(posX, posY))
				{
					return false;
				}
				//画面外
				if (testX < 0)
				{
					return false;
				}
				if (posX > Map::kMapX - 1)
				{
					//testPosX = posX - Map::kMapX - 1;
					//return false;
					//kariPosX = m_indexX - 1;
					//kariPosY = m_indexY + 1;
					//if (m_pMap->isBlock(kariPosX, kariPosY))
					//{
					//	return false;
					//}
					////左に1つずらす(回転可能)
					//else
					//{
					//	
					//}
					
					//(仮) m_indexXが７
					testPosX = posX - Map::kMapX - 1;
					m_isTest = true;
				}
			}
		}
	}
	return true;
}

bool MinoManager::testTypeAndIsThere(int x, int y)
{
	if (m_rotateNum == 0)
	{
		if (m_minoData[m_random].shape[y][x] == 1)
		{
 			return true;
		}
	}
	else if (m_rotateNum == 1)
	{
		if (m_minoData[m_random].shape90[y][x] == 1)
		{
			return true;
		}
	}
	else if (m_rotateNum == 2)
	{
		if (m_minoData[m_random].shape180[y][x] == 1)
		{
			return true;
		}
	}
	else if (m_rotateNum == 3)
	{
		if (m_minoData[m_random].shape270[y][x] == 1)
		{
			return true;
		}
	}

	return false;
}

int MinoManager::getRotateMinoData(int x, int y,int rotateNum)
{
	int data = 0;
	if (rotateNum > 3)
	{
		rotateNum = 0;
	}

	if(rotateNum == 1)
	{
		data = m_minoData[m_random].shape90[y][x];
	}
	else if (rotateNum == 2)
	{
		data = m_minoData[m_random].shape180[y][x];
	}
	else if(rotateNum == 3)
	{
		data = m_minoData[m_random].shape270[y][x];
	}
	else if (rotateNum == 0)
	{
		data = m_minoData[m_random].shape[y][x];
	}

	return data;
}

void MinoManager::createColor(int randomNum)
{
	if (randomNum == MinoType::T)			//紫
	{
		m_color = 0xa260bf;
	}
	else if (randomNum == MinoType::L)		//オレンジ
	{
		m_color = 0xfd7e00;
	}
	else if (randomNum == MinoType::J)		//青
	{
		m_color = 0x0000ff;
	}
	else if (randomNum == MinoType::I)		//水色
	{
		m_color = 0x00ffff;
	}
	else if (randomNum == MinoType::square)	//黄色
	{
		m_color = 0xffff00;
	}
	else if (randomNum == MinoType::S)	//緑
	{
		m_color = 0x00ff00;
	}
	else if (randomNum == MinoType::Z)	//赤
	{
		m_color = 0xff0000;
	}

}

//if (m_rotateNum == 0)
//{
//	if (m_minoData[m_random].shape90[y][x] == 1)
//	{
//		posX = x + m_indexX;
//		posY = y + m_indexY;
//		//ブロックがある場合
//		if (m_pMap->isBlock(posX, posY))
//		{
//			return false;
//		}
//		//画面外
//		if (posX < 0)
//		{
//			return false;
//		}
//		if (posX > Map::kMapX - 1)
//		{
//			return false;
//			kariPosX = m_indexX - 1;
//			kariPosY = m_indexY - 1;
//			if (m_pMap->isBlock(kariPosX, kariPosY))
//			{
//				return false;
//			}
//			//左に1つずらす
//			else
//			{
//				m_isTest = true;
//			}
//		}
//		if (posY > Map::kMapY - 1)
//		{
//			return false;
//		}
//	}
//}
//else if (m_rotateNum == 1)
//{
//	if (m_minoData[m_random].shape180[y][x] == 1)
//	{
//		posX = x + m_indexX;
//		posY = y + m_indexY;
//		//ブロックがある場合
//		if (m_pMap->isBlock(posX, posY))
//		{
//			return false;
//		}
//		//画面外
//		if (posX < 0)
//		{
//			return false;
//
//		}
//		if (posX > Map::kMapX - 1)
//		{
//			return false;
//			kariPosX = m_indexX - 1;
//			kariPosY = m_indexY - 1;
//			if (m_pMap->isBlock(kariPosX, kariPosY))
//			{
//				return false;
//			}
//			//左に1つずらす
//			else
//			{
//				m_isTest = true;
//			}
//		}
//		if (posY > Map::kMapY - 1)
//		{
//			return false;
//		}
//	}
//}
//else if (m_rotateNum == 2)
//{
//	if (m_minoData[m_random].shape270[y][x] == 1)
//	{
//		posX = x + m_indexX;
//		posY = y + m_indexY;
//		//ブロックがある場合
//		if (m_pMap->isBlock(posX, posY))
//		{
//			return false;
//		}
//		//画面外
//		if (posX < 0)
//		{
//			return false;
//		}
//		if (posX > Map::kMapX - 1)
//		{
//			return false;
//			//一番左のミノの1つ左にミノがあるかどうか
//			kariPosX = m_indexX - 1;
//			kariPosY = m_indexY - 1;
//			if (m_pMap->isBlock(kariPosX, kariPosY))
//			{
//				return false;
//			}
//			//左に1つずらす
//			else
//			{
//				m_isTest = true;
//			}
//		}
//		if (posY > Map::kMapY - 1)
//		{
//			return false;
//		}
//	}
//}
//else if (m_rotateNum == 3)
//{
//	if (m_minoData[m_random].shape[y][x] == 1)
//	{
//		posX = x + m_indexX;
//		posY = y + m_indexY;
//		//ブロックがある場合
//		if (m_pMap->isBlock(posX, posY))
//		{
//			return false;
//		}
//		//画面外
//		if (posX < 0)
//		{
//			return false;
//		}
//		if (posX > Map::kMapX - 1)
//		{
//			//return false;
//			kariPosX = m_indexX - 1;
//			kariPosY = m_indexY - 1;
//			if (m_pMap->isBlock(kariPosX, kariPosY))
//			{
//				return false;
//			}
//			//左に1つずらす
//			else
//			{
//				m_isTest = true;
//			}
//		}
//		if (posY > Map::kMapY - 1)
//		{
//			return false;
//		}
//	}
//}