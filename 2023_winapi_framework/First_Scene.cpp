#include "pch.h"
#include "First_Scene.h"
#include "CollisionMgr.h"
#include "Ground.h"
#include "Core.h"
#include "JumpTrap.h"
#include "HurtTrap.h"

First_Scene::First_Scene()
{

}

First_Scene::~First_Scene()
{

}

void First_Scene::Init()
{
	Scene::Init();
	SetMapIdx(2);
	
	std::string path = "Res\\Map\\Map" + std::to_string(m_iMapIdx) + ".json";
	const auto mapVec = TileMgr::GetInst()->GetTileVec(path);
	
	CreateMapObjects(mapVec);
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::GROUND);
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::Trap);

	SetNextScene(L"Second_Scene", L"Start_Scene");


}

bool First_Scene::CanChangeNextScene()
{
	return Scene::CanChangeNextScene();
}

bool First_Scene::CanChangePrevScene()
{
	return Scene::CanChangePrevScene();
}
