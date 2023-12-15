#include "pch.h"
#include "Fifth_Scene.h"

#include "CollisionMgr.h"

void Fifth_Scene::Init()
{
    MapScene::Init();
    
    SetMapIdx(6);
    std::string path = "Res\\Map\\Map" + std::to_string(m_iMapIdx) + ".json";
    const auto mapVec = TileMgr::GetInst()->GetTileVec(path);
    
    
    CreateMapObjects(mapVec);
    CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::GROUND);
    SetNextScene(L"Sixth_Scene", L"Fourth_Scene");
}

bool Fifth_Scene::CanChangeNextScene()
{
    return MapScene::CanChangeNextScene();
}

bool Fifth_Scene::CanChangePrevScene()
{
    return MapScene::CanChangePrevScene();
}
