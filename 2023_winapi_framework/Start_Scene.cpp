#include "pch.h"
#include "Start_Scene.h"
#include "CollisionMgr.h"
#include "TileMgr.h"
#include "tileson.hpp"

void Start_Scene::Init()
{
	MapScene::Init();
	SetMapIdx(1);
	const auto mapVec = TileMgr::GetInst()->GetTileVec("Res\\Map\\Start_Scene.json");
	
	CreateMapObjects(mapVec);
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::GROUND);
	SetNextScene(L"First_Scene");
}


void Start_Scene::Update()
{
	MapScene::Update();
}

void Start_Scene::Render(HDC _dc)
{
	MapScene::Render(_dc);
}

void Start_Scene::Release()
{
	MapScene::Release();
}

bool Start_Scene::CanChangeNextScene()
{
	return MapScene::CanChangeNextScene();
}

bool Start_Scene::CanChangePrevScene()
{
	return MapScene::CanChangePrevScene();
}
