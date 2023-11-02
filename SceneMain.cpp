#include "SceneMain.h"
#include "SceneManager.h"
#include "SceneTitle.h"
#include "SceneDebug.h"

#include "MinoManager.h"
#include "Map.h"

#include "Pad.h"
#include "game.h"
#include <DxLib.h>

SceneMain::SceneMain(SceneManager& manager) :
    SceneBase(manager)
{
    m_pMinoManager = new MinoManager;
    m_pMap = new Map;
    m_pMinoManager->setMap(m_pMap);
    m_pMinoManager->init();
    m_pMap->init();
}

SceneMain::~SceneMain()
{

}

void SceneMain::init()
{
}

void SceneMain::update()
{

    m_pMinoManager->update();
    m_pMap->update();
}

void SceneMain::draw()
{
    m_pMinoManager->draw();
    m_pMap->draw();
}
