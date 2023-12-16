#include "pch.h"
#include "Second_Scene.h"

#include "CollisionMgr.h"
#include "JumpTrap.h"
#include "HurtTrap.h"

Second_Scene::Second_Scene()
{
}

Second_Scene::~Second_Scene()
{
}

bool Second_Scene::CanChangeNextScene()
{
    return MapScene::CanChangeNextScene();
}

bool Second_Scene::CanChangePrevScene()
{
    return MapScene::CanChangePrevScene();
}

void Second_Scene::Init()
{
    MapScene::Init();
    SetMapIdx(3);

    std::string path = "Res\\Map\\Map" + std::to_string(m_iMapIdx) + ".json";
    const auto mapVec = TileMgr::GetInst()->GetTileVec(path);
	
    CreateMapObjects(mapVec);
    CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::GROUND);
    SetNextScene(L"Third_Scene", L"First_Scene");

    CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::Trap);
    JumpTrap* trap = new JumpTrap();
    trap->SetTrapInfo(1.f, Vec2(-.5f, -.5f));
    trap->SetPos(Vec2(150.f, 500.f));
    trap->SetScale(Vec2(30.f, 30.f));
    AddObject(trap, OBJECT_GROUP::Trap);

}
