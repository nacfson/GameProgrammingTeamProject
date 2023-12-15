#include "pch.h"
#include "Eighth_Scene.h"

#include "CollisionMgr.h"

void Eighth_Scene::Init()
{
    MapScene::Init();

    SetMapIdx(9);
	
    std::string path = "Res\\Map\\Map" + std::to_string(m_iMapIdx) + ".json";
    const auto mapVec = TileMgr::GetInst()->GetTileVec(path);
	
    CreateMapObjects(mapVec);
    CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::GROUND);
    SetNextScene(L"Ninth_Scene", L"Seventh_Scene");
}

bool Eighth_Scene::CanChangeNextScene()
{
	return MapScene::CanChangeNextScene();
}

bool Eighth_Scene::CanChangePrevScene()
{
	return MapScene::CanChangePrevScene();
}
