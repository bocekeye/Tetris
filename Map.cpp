#include "Map.h"
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
			DrawBox(0,100,x * kMapSize + kMapSize,y * kMapSize + kMapSize + 100,0xffffff,false);
		}
	}
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

void Map::setBlock(int x, int y)
{
	m_map[x][y] = 1;
}

void Map::erase()
{
	//Y座標保存
	int strageY = 0;
	for (int y = 0; y < Map::kMapY; y++)
	{
		m_count = 0;
		for (int x = 0; x < Map::kMapX; x++)
		{
			if (m_map[x][y] == 1)
			{
				m_count += 1;
				strageY = y;
			}
		}
	}
	//一列揃ったらその列を消す
	if (m_count == 10)
	{
		for (int x = 0; x < Map::kMapX; x++)
		{
			m_map[x][strageY] = 0;
		}
	}

}

void Map::testErase(int x, int y)
{
	m_map[x][y] = 0;
}
