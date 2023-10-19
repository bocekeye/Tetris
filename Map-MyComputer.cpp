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
	for (int y = 0; y < kMapY; y++)
	{
		for (int x = 0; x < kMapX; x++)
		{
			DrawBox(0,100,x * 30,y * 30 + 100,0xffffff,false);
		}
	}
}
