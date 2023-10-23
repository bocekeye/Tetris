#include "Map.h"
#include "MinoManager.h"
#include <DxLib.h>

Map::Map()
{
}

Map::~Map()
{
}

void Map::init()
{
	for (int y = 0; y < kMapY; y++)
	{
		for (int x = 0; x < kMapX; x++)
		{
			m_map[x][y] = 0;
		}
	}
}

void Map::update()
{
}

void Map::draw()
{
	//枠
	for (int y = 0; y < kMapY; y++)
	{
		for (int x = 0; x < kMapX; x++)
		{
			if (m_map[x][y] == 1)
			{
				int posX = x * kMapSize;
				int posY = y * kMapSize;

				DrawBox(posX + 100, posY + 100, posX + kMapSize + 100, posY + 100 + kMapSize, 0xff0000, true);

			}

			int Frame = kMapSize + 1;
			DrawBox(100,100,x * kMapSize + kMapSize + 100,y * kMapSize + kMapSize + 100,0xffffff,false);
		}
	}

//	DrawFormatString(500, 100, 0xffffff, "m_count = %d", m_count);
}

/// <summary>
/// ミノがあるかどうか
/// </summary>
/// <param name="x">横座標</param>
/// <param name="y">縦座標</param>
/// <returns>true : ある　false : ない</returns>
bool Map::isBlock(int x, int y)
{
	if (m_map[x][y] == 1)
	{
		return true;
	}
	return false;
}

void Map::setBlock(int x, int y,int color)
{
	m_map[x][y] = 1;
	m_color = color;
}

void Map::erase()
{
	//Y座標保存
	int strageY = 0;
	for (int y = Map::kMapY - 1; y > 0 ; y--)
	{
		m_count = 0;
		for (int x = 0; x < Map::kMapX; x++)
		{
			if (m_map[x][y] == 1)
			{
				m_count += 1;
				printfDx("%d\n", m_count);
				if (m_count == 10)
				{
					m_isLineUP = true;
					strageY = y;
				}
			}
		}
	}
	//一列揃ったらその列を消す
	if (m_isLineUP)
	{
		for (int x = 0; x < Map::kMapX; x++)
		{
			m_map[x][strageY] = 0;
		}
		lower();
		m_isLineUP = false;
	}
	
}

void Map::lower()
{
	for (int y = Map::kMapY - 2; y > 0; y--)
	{
		for (int x = 0; x < Map::kMapX; x++)
		{
			if (m_map[x][y] == 1)
			{
				if (m_map[x][y + 1] == 0)
				{
					m_map[x][y] = 0;
					m_map[x][y + 1] = 1;
				}
			}
		}
	}
}

void Map::getColor(int color)
{
	m_color = color;
}
