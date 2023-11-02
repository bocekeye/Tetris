#pragma once

#include "SceneBase.h"
#include <memory>

class SceneManager;
class MinoManager;
class Map;

class SceneMain : public SceneBase
{
public:
	SceneMain(SceneManager& manager);

	virtual ~SceneMain();

	void init();

	void update();
	void draw();

private:

	MinoManager* m_pMinoManager;
	Map* m_pMap;
};
