#include "pch.h"
#include "Sixth_Scene.h"

#include "CollisionMgr.h"

void Sixth_Scene::Init()
{
    MapScene::Init();
	
    SetMapIdx(7);
	
    std::string path = "Res\\Map\\Map" + std::to_string(m_iMapIdx) + ".json";
    const auto mapVec = TileMgr::GetInst()->GetTileVec(path);
	
    CreateMapObjects(mapVec);
    CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::GROUND);
    SetNextScene(L"Seventh_Scene", L"Fifth_Scene");
}
