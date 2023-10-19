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
	//˜g
	for (int y = 0; y < kMapY; y++)
	{
		for (int x = 0; x < kMapX; x++)
		{
			DrawBox(0,100,x * kMapSize + kMapSize,y * kMapSize + kMapSize + 100,0xffffff,false);
		}
	}
}

/// <summary>
/// ƒ~ƒm‚ª‚ ‚é‚©‚Ç‚¤‚©
/// </summary>
/// <param name="x">‰¡À•W</param>
/// <param name="y">cÀ•W</param>
/// <returns>true : ‚ ‚é@false : ‚È‚¢</returns>
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
	//YÀ•W•Û‘¶
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
	//ˆê—ñ‘µ‚Á‚½‚ç‚»‚Ì—ñ‚ğÁ‚·
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
