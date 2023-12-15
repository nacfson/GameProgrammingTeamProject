#include "pch.h"
#include "Ninth_Scene.h"

#include "CollisionMgr.h"

void Ninth_Scene::Init()
{
    MapScene::Init();

    SetMapIdx(10);
	
    std::string path = "Res\\Map\\Map" + std::to_string(m_iMapIdx) + ".json";
    const auto mapVec = TileMgr::GetInst()->GetTileVec(path);
	
    CreateMapObjects(mapVec);
    CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::GROUND);
    SetNextScene(L"Last_Scene", L"Eighth_Scene");
}
