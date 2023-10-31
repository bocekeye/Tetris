#include "MinoManager.h"
#include "Map.h"
#include <random>
#include <DxLib.h>
#include "Pad.h"

MinoManager::MinoManager() :
	m_indexX(0),
	m_indexY(0),
	m_fallInterval(0),
	m_isFallTheBottom(false),
	m_isMoveRight(false),
	m_isMoveLeft(false),
	m_count(0),
	m_random(0),
	m_rotateNum(0),
	m_color(0),
	m_isHoldEnable(false),
	m_isHoldFirst(false),
	m_isGameOver(false),
	m_holdType(0)
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			m_holdMap[x][y] = 0;
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
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0},
		},
		{
			{0,0,1,0},
			{0,0,1,0},
			{0,0,1,0},
			{0,0,1,0},
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
	if (m_fallInterval++ >= 120)
	{
		if (isMoveBelow(m_indexY))
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
						m_pMap->setBlock(posX, posY, m_random + 1);
						isGameOver(posX, posY);
					}
				}
			}
			create();
		}
		m_fallInterval = 0;
	}


	if (Pad::isTrigger(PAD_INPUT_DOWN))
	{
		if (isMoveBelow(m_indexY))
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
						m_pMap->setBlock(posX, posY, m_random + 1);
						isGameOver(posX, posY);
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

	//��]
	if (Pad::isTrigger(PAD_INPUT_1) || Pad::isTrigger(PAD_INPUT_2))
	{
		if (isRotate(m_indexX, m_indexY))
		{
			m_rotateNum += 1;
		}
		else
		{
			//1������ĉ�]�ł��邩�m�F����
			if (test3(m_indexX + 1, m_indexY, m_rotateNum))
			{
				m_indexX += 1;
				m_rotateNum += 1;
			}
			else if (test3(m_indexX + 2, m_indexY, m_rotateNum))
			{
				m_indexX += 2;
				m_rotateNum += 1;
			}
			else if (test3(m_indexX - 1, m_indexY, m_rotateNum))
			{
				m_rotateNum += 1;
				if (m_random == MinoType::I)
				{
					m_indexX -= 1;
				}
			}
			else if (test3(m_indexX - 2, m_indexY, m_rotateNum))
			{
				if (m_random == MinoType::I)
				{
					m_indexX -= 2;
				}
				else
				{
					m_indexX -= 1;

				}
				m_rotateNum += 1;
			}
			else if (test3(m_indexX - 3, m_indexY, m_rotateNum))
			{
				m_indexX -= 2;
				m_rotateNum += 1;
			}
			else if (test3(m_indexX, m_indexY + 1, m_rotateNum))
			{
				m_indexY += 1;
				m_rotateNum += 1;
			}
		}
		if (m_rotateNum > 3)
		{
			m_rotateNum = 0;
		}
	}

	if (Pad::isTrigger(PAD_INPUT_UP))
	{
		m_isFallContinue = true;
	}
	//���Ƃ���Ƃ���܂ŗ��Ƃ�
	if (m_isFallContinue)
	{
		if (isMoveBelow(m_indexY))
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
						m_pMap->setBlock(posX, posY, m_random + 1);
						isGameOver(posX, posY);
					}
				}
			}
			//
			m_isFallContinue = false;
			create();
		}
	}

	//�z�[���h
	//�~�m��ݒu������z�[���h��1��ł���悤�ɂ���
#if true
	if (m_isHoldEnable)
	{
		if (Pad::isTrigger(PAD_INPUT_3))
		{		
			//���ݐ�������Ă���~�m��ۑ�(?)����
			int strageMap[4][4];

			for (int x = 0; x < 4; x++)
			{
				for (int y = 0; y < 4; y++)
				{
					if (m_holdMap[x][y] == 1)
					{
						strageMap[x][y] = 1;
						m_holdMap[x][y] = 0;
					}
					else 
					{
						strageMap[x][y] = 0;
					}
				}
			}

			for (int x = 0; x < 4; x++)
			{
				for (int y = 0; y < 4; y++)
				{
					if (testTypeAndIsThere(x, y))
					{
						m_holdMap[x][y] = 1;
					}
					else
					{
						m_holdMap[x][y] = 0;
					}
				}
			}	

			int strageColor = m_color;
			//�F�̕ۑ�
			m_holdColor = m_color;
			//��x�z�[���h���ꂽ�ꍇ�̓z�[���h�ł��Ȃ��悤�ɂ���
			m_isHoldEnable = false;	
			//��ԍŏ��̓z�[���h����Ă��Ȃ��̂�
			//�ŏ����z�[���h���ꂽ��V�����~�m�𐶐����Ȃ�
	
			if (!m_isOnce)
			{
				m_holdType = m_random;
				m_isOnce = true;
			}		
			if (!m_isHoldFirst)
			{
				create();
				printfDx("%d\n", m_holdType);
			}
			//�z�[���h����Ă���ꍇ
			else
			{
				int frontType = m_holdType;
				m_holdType = m_random;
				m_random = frontType;
				m_isHold = true;
			}
			m_isHoldFirst = true;		
		}
	}
#endif

	//�Q�[���I��
	if (m_isGameOver)
	{
		DrawFormatString(300, 300, 0xffffff, "GAME OVER");
	}
	m_pMap->erase();
}

void MinoManager::draw()
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			//�{��
			if (testTypeAndIsThere(x, y))
			{
				int posX = (m_indexX + x) * Map::kMapSize + Map::kDisplayX;
				int posY = (m_indexY + y) * Map::kMapSize + Map::kDisplayY;				
				int color = createColor(m_random);
			
				DrawBox(posX, posY, posX + Map::kMapSize, posY + Map::kMapSize, color, true);
				
			}
			

			if (m_minoData[m_nextRandom].shape[y][x] == 1)
			{
				//���̃~�m
				int nextMinoPosX = 500 + x * Map::kMapSize + Map::kDisplayX;
				int nextMinoPosY = 300 + y * Map::kMapSize + Map::kDisplayY;
				DrawBox(nextMinoPosX, nextMinoPosY , nextMinoPosX + Map::kMapSize , nextMinoPosY + Map::kMapSize, m_nextColor, true);
			}

			if (m_holdMap[x][y] == 1)
			{
				//�z�[���h�~�m
				int holdMinoPosX = (x * Map::kMapSize) + 100;
				int holdMinoPosY = 100 + y * Map::kMapSize + Map::kDisplayY;
				DrawBox(holdMinoPosX, holdMinoPosY, holdMinoPosX + Map::kMapSize, holdMinoPosY + Map::kMapSize, m_holdColor, true);
			}

			//�g
			int nextFrameX = 500 + x * Map::kMapSize + Map::kDisplayX;
			int nextFrameY = 300 + y * Map::kMapSize + Map::kDisplayY;
			DrawBox(nextFrameX, nextFrameY, nextFrameX + Map::kMapSize, nextFrameY + Map::kMapSize, 0xffffff, false);


			int holdFrameX = 100 + (x * Map::kMapSize);
			int holdFrameY = 100 + (y * Map::kMapSize) + Map::kDisplayY;
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128); // 128�͓����x�̒l�i0����255�܂ł͈̔�
			DrawBox(holdFrameX, holdFrameY, holdFrameX + Map::kMapSize, holdFrameY + Map::kMapSize, 0xffffff, false);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

			
		}
	}
	putDisplayLower();
	
	

	DrawString(510 + Map::kDisplayX, 350, "NEXT BLOCK",0xffffff, true);

	DrawFormatString(900, 100, 0xfffffff, "m_random = %d", m_random);
	DrawFormatString(900, 120, 0xfffffff, "m_holdType = %d", m_holdType);

	DrawString(900, 750, "��{�^���ŉ�]", 0xffffff, true);
	DrawString(900, 850, "1�{�^���Ńz�[���h", 0xffffff, true);

#ifdef _DEBUG

	/*DrawFormatString(500, 100, 0xffffff, "m_display = %d", m_display);
	DrawFormatString(500, 120, 0xffffff, "m_indexY = %d", m_indexY);
	DrawFormatString(500, 140, 0xffffff, "m_random = %d", m_random);
	DrawFormatString(500, 160, 0xffffff, "m_nextRandom = %d", m_nextRandom);
	DrawFormatString(500, 180, 0xffffff, "testPosX = %d", m_testPosX);

	if (isRotate(m_indexX,m_indexY))
	{
		DrawString(500, 200, "��] = TRUE", 0xffffff);
	}
	else
	{
		DrawString(500, 200, "��] = FALSE", 0xffffff);
	}
	if (m_isTest)
	{
		DrawString(500, 220, "m_isTest = TRUE", 0xffffff);
	}
	else
	{
		DrawString(500, 220, "m_isTest = FALSE", 0xffffff);
	}*/

#endif
}

void MinoManager::create()
{
	//�����_���v�Z
	std::random_device rd;
	std::mt19937 mt(rd());
	//0�`6�܂ł̐����������_������
	std::uniform_int_distribution<int> rdt(MinoType::T, MinoType::Z);
	m_indexX = 4;
	m_indexY = 0;
	m_rotateNum = 0;
	m_random = rdt(mt);				//���݂̃~�m
	//��񂾂��ʂ�悤�ɂ���
	//���O�ɐ����������̃~�m�𐶐�������
	if (m_next)
	{
		m_random = m_nextRandom;
	}
	m_nextRandom = rdt(mt);			//���̃~�m
	m_next = true;
	m_isHoldEnable = true;
	int tempX = 0;
	int tempY = 0;
	//��ԏ�Ƀ~�m���Ȃ��������i��ɂ�����
	while (true)
	{
		//1�ł���ԏ�Ƀ~�m���������烋�[�v����߂�
		if (m_minoData[m_random].shape[0][tempY] == 1)
		{
			break;
		}
		tempY++;
		if (tempY == 3)
		{
			m_indexY = -1;
			break;
		}
	}
	//��ԍ��Ƀ~�m���Ȃ������獶��1���炷
	while (true)
	{
		if (m_minoData[m_random].shape[tempX][0] == 1)
		{
			break;
		}
		tempX++;
		if (tempX == 3)
		{
			m_indexX = 3;
			break;
		}
	}
	//�����_���̐�����F�𐶐�����
	m_color = createColor(m_random);
	m_nextColor = createColor(m_nextRandom);
	//�F�����擾����
	m_pMap->getColor(m_random);
}

/// <summary>
/// 1���Ƀu���b�N���ړ��ł��邩�ǂ���
/// </summary>
/// <returns></returns>
bool MinoManager::isMoveBelow(int indexY)
{
	//�����ꂩ���̏���(�H)
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (testTypeAndIsThere(x, y))
			{
				int posX = (m_indexX + x);
				int posY = (indexY + y);

				//�ړ�����
				if (posY >= Map::kMapY - 1)
				{
					return false;
				}
				//1���Ƀu���b�N���������ꍇ
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
/// �E�Ɉړ��ł��邩�ǂ���
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

				//�ړ�����
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
/// ���Ɉړ��ł��邩�ǂ���
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

				//�ړ�����
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
bool MinoManager::testTypeAndIsThere(int x, int y)
{
	if (m_rotateNum == RotateAngle::shape0)
	{
		if (m_minoData[m_random].shape[y][x] == 1)
		{
 			return true;
		}
	}
	else if (m_rotateNum == RotateAngle::shape90)
	{
		if (m_minoData[m_random].shape90[y][x] == 1)
		{
			return true;
		}
	}
	else if (m_rotateNum == RotateAngle::shape180)
	{
		if (m_minoData[m_random].shape180[y][x] == 1)
		{
			return true;
		}
	}
	else if (m_rotateNum == RotateAngle::shape270)
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

	if (rotateNum == RotateAngle::shape0)
	{
		data = m_minoData[m_random].shape[y][x];
	}
	else if(rotateNum == RotateAngle::shape90)
	{
		data = m_minoData[m_random].shape90[y][x];
	}
	else if (rotateNum == RotateAngle::shape180)
	{
		data = m_minoData[m_random].shape180[y][x];
	}
	else if(rotateNum == RotateAngle::shape270)
	{
		data = m_minoData[m_random].shape270[y][x];
	}
	return data;
}

int MinoManager::createColor(int randomNum)
{
	int color = 0;
	if (randomNum == MinoType::T)			//��
	{
		color = 0xa260bf;
	}
	else if (randomNum == MinoType::L)		//�I�����W
	{
		color = 0xfd7e00;
	}
	else if (randomNum == MinoType::J)		//��
	{
		color = 0x0000ff;
	}
	else if (randomNum == MinoType::I)		//���F
	{
		color = 0x00ffff;
	}
	else if (randomNum == MinoType::square)	//���F
	{
		color = 0xffff00;
	}
	else if (randomNum == MinoType::S)	//��
	{
		color = 0x00ff00;
	}
	else if (randomNum == MinoType::Z)	//��
	{
		color = 0xff0000;
	}

	return color;
}

/// <summary>
/// ��]�ł��邩�ǂ���
/// </summary>
/// <param name="indexX"></param>
/// <param name="indexY"></param>
/// <param name="rorateNum"></param>
/// <returns>true:��]�ł���</returns>

bool MinoManager::isRotate(int indexX, int indexY)
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			int posX = x + indexX;
			int posY = y + indexY;

			if (posX < 0)
			{
				return false;
			}
			if (posX > Map::kMapX - 1)
			{
				return false;
			}
			if (posY > Map::kMapY - 1)
			{
				return false;
			}
				
			//���̉�]���̈ʒu�ƃ}�b�v�̃u���b�N������ʒu����v����(�d�Ȃ��Ă�����)true��Ԃ�
			if (getRotateMinoData(x, y, m_rotateNum + 1) == 1 && m_pMap->isBlock(posX, posY))
			{
				return false;
			}
		}
	}
	return true;
}

bool MinoManager::test3(int indexX, int indexY, int rotateNum)
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 3; y >= 0; y--)
		{
			int posX = x + indexX;
			int posY = y + indexY;

			if (posX < 0)
			{
				return false;
			}
			if (posX > Map::kMapX - 1)
			{
				return false;
			}
			if (posY > Map::kMapY - 1)
			{
				return false;
			}

			if (m_pMap->isBlock(posX, posY))
			{
				return false;
			}

		}
	}

	return true;
}



void MinoManager::putDisplayLower()
{		
	if (isDisplay(m_display))
	{
		m_display++;
	}
	else
	{
		int temp = m_display;
		for (int x = 0; x < 4; x++)
		{
			for (int y = 0; y < 4; y++)
			{
				if (testTypeAndIsThere(x, y))
				{
					int posX = (x + m_indexX) * Map::kMapSize + Map::kDisplayX;
					int posY = (m_indexY + y + temp) * Map::kMapSize + Map::kDisplayY;
					int color = createColor(m_random);
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128); // 128�͓����x�̒l�i0����255�܂ł͈̔�
					DrawBox(posX, posY, posX + Map::kMapSize, posY + Map::kMapSize, color, true);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				}
			}
		}
		m_display = 0;
	}

	printfDx("%d\n", m_display);


}

bool MinoManager::isDisplay(int display)
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (testTypeAndIsThere(x, y))
			{
				int posX = m_indexX + x;
				int posY = m_indexY + y + display;

				//����
				if (posY >= Map::kMapY - 1)
				{
					return false;
				}
				//1���Ƀu���b�N���������ꍇ
				if (m_pMap->isBlock(posX, posY + 1))
				{
					return false;
				}
			}
		}
	}
	return true;
}

void MinoManager::isGameOver(int x, int y)
{
	if (y <= 0)
	{
 		m_isGameOver = true;
	}
}


//bool MinoManager::test(int testX, int testY)
//{
//	struct indexData
//	{
//		int test[5];
//	};
//	constexpr indexData offset =
//	{
//		{-2,-1,0,1,2}
//	};
//
//	//�u���b�N����
//	for (int x = 0; x < 4; x++)
//	{
//		for (int y = 0; y < 4; y++)
//		{
//			if (getRotateMinoData(x, y, m_rotateNum + 1) == 1)
//			{
//				for (auto& ofs : offset.test)
//				{
//					int testPosX = m_indexX + x + ofs;
//					int testPosY = m_indexY + y + ofs;
//
//					//��ʊO
//					if (testPosX > Map::kMapX - 1)
//					{
//						continue;
//					}
//					if (testPosX < 0)
//					{
//						continue;
//					}
//					//�u���b�N�����������]�ł��Ȃ�
//					if (m_pMap->isBlock(testPosX, testPosY))
//					{
//						continue;
//					}
//					else
//					{
//						//�u���b�N���Ȃ��Ƃ��낪���������]�ł���H
//						return true;
//					}
//				}
//			}
//		}
//	}
//	
//	return false;
//}

//bool MinoManager::test2(int x, int y)
//{
//	struct indexData
//	{
//		int test[5];
//	};
//	constexpr indexData offset =
//	{
//		{-2,-1,0,1,2}
//	};
//
//	for (auto& ofs: offset.test)
//	{
//		int posX = x + ofs;
//		int posY = x + ofs;
//		
//		//���݂̃~�m�̃C���f�b�N�X���
//		int presentIndexX = m_indexX +1;
//		if (x > presentIndexX)
//		{
//			if (ofs < 0)
//			{
//				continue;
//			}
//		}
//		else
//		{
//			if (ofs > 0)
//			{
//				continue;
//			}
//		}
//		//�u���b�N���������ꍇ
//		if (m_pMap->isBlock(posX, posY))
//		{
//			return false;
//		}
//		else
//		{
//			return true;
//		}
//	}
//	return false;
//}


//��ʊO
//if (posX < 0)
//{
//	testPosX = posX - 0;
//	testPosX *= -1;
//	m_isTest = true;
//	//					return false;
//}
//if (posX > Map::kMapX - 1)
//{
//	testPosX = posX - (Map::kMapX - 1);
//	testPosX *= -1;
//	/*if (m_pMap->isBlock(m_indexX + testPosX, posY))
//	{
//		return false;
//	}*/
//	m_isTest = true;
//
//	//return false;
//}