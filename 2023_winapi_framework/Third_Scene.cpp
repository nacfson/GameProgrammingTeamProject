#include "pch.h"
#include "Third_Scene.h"

#include "CollisionMgr.h"

void Third_Scene::Init()
{
    MapScene::Init();
    
    SetMapIdx(4);
    std::string path = "Res\\Map\\Map" + std::to_string(m_iMapIdx) + ".json";
    const auto mapVec = TileMgr::GetInst()->GetTileVec(path);
	
    CreateMapObjects(mapVec);
    CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::GROUND);
    SetNextScene(L"Fourth_Scene", L"Second_Scene");
}

bool Third_Scene::CanChangeNextScene()
{
    return MapScene::CanChangeNextScene();
}

bool Third_Scene::CanChangePrevScene()
{
    return MapScene::CanChangePrevScene();
}
