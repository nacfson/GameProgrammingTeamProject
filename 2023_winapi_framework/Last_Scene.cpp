#include "pch.h"
#include "Last_Scene.h"
#include "PlayerMgr.h"
#include "CollisionMgr.h"

void Last_Scene::Init()
{
    //MapScene::Init();
	PlayerMgr::GetInst()->Release();
    SetMapIdx(11);
	
    //std::string path = "Res\\Map\\Map" + std::to_string(m_iMapIdx) + ".json";
    //const auto mapVec = TileMgr::GetInst()->GetTileVec(path);
	
    //CreateMapObjects(mapVec);
    //CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::GROUND);
    //SetNextScene(L"Last_Scene", L"Eighth_Scene");
}

bool Last_Scene::CanChangeNextScene()
{
	return false;
}

bool Last_Scene::CanChangePrevScene()
{
	return false;
}
