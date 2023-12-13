#include "pch.h"
#include "First_Scene.h"
#include "CollisionMgr.h"
#include "Ground.h"
#include "Core.h"

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
	
	const auto mapVec = TileMgr::GetInst()->GetTileVec("Res\\Map\\Map2.json");
	
	CreateMapObjects(mapVec);
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::GROUND);
	SetNextScene(L"First_Scene", L"Start_Scene");
}

bool First_Scene::CanChangeNextScene()
{
	return Scene::CanChangeNextScene();
}

bool First_Scene::CanChangePrevScene()
{
	return Scene::CanChangePrevScene();
}
