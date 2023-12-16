#include "pch.h"
#include "Seventh_Scene.h"

#include "CollisionMgr.h"
#include "JumpTrap.h"
void Seventh_Scene::Init()
{
    MapScene::Init();
    SetMapIdx(8);
	
    std::string path = "Res\\Map\\Map" + std::to_string(m_iMapIdx) + ".json";
    const auto mapVec = TileMgr::GetInst()->GetTileVec(path);
	
    CreateMapObjects(mapVec);
    CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::GROUND);
    SetNextScene(L"Eighth_Scene", L"Sixth_Scene");
}

bool Seventh_Scene::CanChangeNextScene()
{
	return MapScene::CanChangeNextScene();
}

bool Seventh_Scene::CanChangePrevScene()
{
	return MapScene::CanChangePrevScene();
}
