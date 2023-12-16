#include "pch.h"
#include "Third_Scene.h"

#include "CollisionMgr.h"
#include "JumpTrap.h"
void Third_Scene::Init()
{
    MapScene::Init();
    
    SetMapIdx(4);
    std::string path = "Res\\Map\\Map" + std::to_string(m_iMapIdx) + ".json";
    const auto mapVec = TileMgr::GetInst()->GetTileVec(path);
	
    CreateMapObjects(mapVec);
    CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::GROUND);
    SetNextScene(L"Fourth_Scene", L"Second_Scene");

    CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::Trap);
    JumpTrap* trap = new JumpTrap();
    trap->SetTrapInfo(1.5f, Vec2(.5f, -.5f));
    trap->SetPos(Vec2(150.f, 700.f));
    trap->SetScale(Vec2(30.f, 30.f));
    AddObject(trap, OBJECT_GROUP::Trap);
}

bool Third_Scene::CanChangeNextScene()
{
    return MapScene::CanChangeNextScene();
}

bool Third_Scene::CanChangePrevScene()
{
    return MapScene::CanChangePrevScene();
}
