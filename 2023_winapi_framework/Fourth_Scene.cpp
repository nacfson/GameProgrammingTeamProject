#include "pch.h"
#include "Fourth_Scene.h"

#include "CollisionMgr.h"

void Fourth_Scene::Init()
{
    MapScene::Init();
    SetMapIdx(5);

    std::string path = "Res\\Map\\Map" + std::to_string(m_iMapIdx) + ".json";
    const auto mapVec = TileMgr::GetInst()->GetTileVec(path);
	
    CreateMapObjects(mapVec);
    CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::GROUND);
    SetNextScene(L"First_Scene", L"Third_Scene");
}
