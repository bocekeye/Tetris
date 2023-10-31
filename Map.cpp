#include "Map.h"
#include "MinoManager.h"
#include <DxLib.h>

Map::Map():
	m_color(0),
	m_count(0)
{
	for (int x = 0; x < kMapX; x++)
	{
		for (int y = 0; y < kMapY; y++)
		{
			m_map[x][y] = 0;
		}
	}
}

Map::~Map()
{
}

void Map::init()
{
}

void Map::update()
{
}

void Map::draw()
{
	//枠 
	for (int x = 0; x < kMapX; x++)
	{
		for (int y = 0; y < kMapY; y++)
		{
			if (m_map[x][y] != 0)
			{
				/*int posX = x * kMapSize;
				int posY = y * kMapSize;*/
				testColor(x, y);

				//DrawBox(posX + 100, posY + 100, posX + kMapSize + 100, posY + 100 + kMapSize, 0xffffff, true);
			}

			//枠
			int frameX = x * kMapSize + kDisplayX;
			int frameY = y * kMapSize + kDisplayY;
			DrawBox(frameX, frameY, frameX + kMapSize,frameY + kMapSize, 0xffffff, false);
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
	if (m_map[x][y] != 0)
	{
		return true;
	}
	return false;
}

void Map::setBlock(int x, int y,int color)
{
	m_map[x][y] = color;
	//m_color = color;
}

void Map::erase()
{
	//Y座標保存
	int strageY = 0;
	//一番下から確認する　
	for (int y = Map::kMapY - 1; y > 0 ; y--)
	{
		m_count = 0;
		for (int x = 0; x < Map::kMapX; x++)
		{
			if (m_map[x][y] != 0)
			{
				m_count += 1;
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
		lower(strageY);
		m_isLineUP = false;
	}
	
}

void Map::lower(int strageY)
{
	for (int y = strageY; y > 0; y--)
	{
		for (int x = 0; x < Map::kMapX; x++)
		{
			//列がそろったところのミノを消す
			m_map[x][y] = 0;
			//一段下げる
			m_map[x][y] = m_map[x][y - 1];
		}
	}

}

void Map::testColor(int x, int y)
{
	int posX = (x * kMapSize) + kDisplayX;
	int posY = (y * kMapSize) + kDisplayY;
	if (m_map[x][y] == 1)
	{
		DrawBox(posX , posY, posX + kMapSize, posY + kMapSize, 0xa260bf, true);
	}
	else if (m_map[x][y] == 2)
	{
		DrawBox(posX, posY , posX + kMapSize , posY + kMapSize, 0xfd7e00, true);
	}
	else if (m_map[x][y] == 3)
	{
		DrawBox(posX, posY , posX + kMapSize , posY+ kMapSize, 0x0000ff, true);
	}
	else if (m_map[x][y] == 4)
	{
		DrawBox(posX, posY , posX + kMapSize , posY + kMapSize, 0x00ffff, true);
	}
	else if (m_map[x][y] == 5)
	{
		DrawBox(posX, posY , posX + kMapSize , posY + kMapSize, 0xffff00, true);
	}
	else if (m_map[x][y] == 6)
	{
		DrawBox(posX, posY , posX + kMapSize, posY + kMapSize, 0x00ff00, true);
	}
	else if (m_map[x][y] == 7)
	{
		DrawBox(posX, posY , posX + kMapSize, posY + kMapSize, 0xff0000, true);
	}
}

void Map::getColor(int color)
{
	if (color == 1)
	{
		m_color = 0xa260bf;
	}
	else if (color == 2)
	{
		m_color = 0xfd7e00;
	}
	else if (color == 3)
	{
		m_color = 0x0000ff;
	}
	else if (color == 4)
	{
		m_color = 0x00ffff;
	}
	else if (color == 5)
	{
		m_color = 0xffff00;
	}
	else if (color == 6)
	{
		m_color = 0x00ff00;
	}
	else if (color == 7)
	{
		m_color = 0xff0000;
	}
	//m_color = color;
}

//void Map::setColor(int x, int y)
//{
//	if (m_color = 1)
//	{
//		DrawBox(x + 100, y + 100, x + kMapSize + 100, y + 100 + kMapSize, 0xa260bf, true);
//	}
//	else if (m_color == 2)
//	{
//		DrawBox(x + 100, y + 100, x + kMapSize + 100, y + 100 + kMapSize, 0xfd7e00, true);
//	}
//	else if (m_color == 3)
//	{
//		DrawBox(x + 100, y + 100, x + kMapSize + 100, y + 100 + kMapSize, 0x0000ff, true);
//	}
//	else if (m_color == 4)
//	{
//		DrawBox(x + 100, y + 100, x + kMapSize + 100, y + 100 + kMapSize, 0x00ffff, true);
//	}
//	else if (m_color == 5)
//	{
//		DrawBox(x + 100, y + 100, x + kMapSize + 100, y + 100 + kMapSize, 0xffff00, true);
//	}
//	else if (m_color == 6)
//	{
//		DrawBox(x + 100, y + 100, x + kMapSize + 100, y + 100 + kMapSize, 0x00ff00, true);
//	}
//	else if (m_color == 7)
//	{
//		DrawBox(x + 100, y + 100, x + kMapSize + 100, y + 100 + kMapSize, 0xff0000, true);
//	}
//}
