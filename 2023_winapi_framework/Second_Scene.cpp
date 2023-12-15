#include "pch.h"
#include "Second_Scene.h"

#include "CollisionMgr.h"

void Second_Scene::Init()
{
    MapScene::Init();
    SetMapIdx(3);

    std::string path = "Res\\Map\\Map" + std::to_string(m_iMapIdx) + ".json";
    const auto mapVec = TileMgr::GetInst()->GetTileVec(path);
	
    CreateMapObjects(mapVec);
    CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::GROUND);
    SetNextScene(L"Third_Scene", L"First_Scene");
}
