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
	//�g
	for (int y = 0; y < kMapY; y++)
	{
		for (int x = 0; x < kMapX; x++)
		{
			DrawBox(0,100,x * kMapSize + kMapSize,y * kMapSize + kMapSize + 100,0xffffff,false);
		}
	}
}

/// <summary>
/// �~�m�����邩�ǂ���
/// </summary>
/// <param name="x">�����W</param>
/// <param name="y">�c���W</param>
/// <returns>true : ����@false : �Ȃ�</returns>
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
	//Y���W�ۑ�
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
	//��񑵂����炻�̗������
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
