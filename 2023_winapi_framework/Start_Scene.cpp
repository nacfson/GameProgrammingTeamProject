#include "pch.h"
#include "Start_Scene.h"
#include "Collider.h"
#include "Object.h"
#include "Core.h"
#include "CollisionMgr.h"
#include "Ground.h"
#include "PlayerMgr.h"
#include "TileMgr.h"
#include <fstream>
#include <iostream>
#include "tileson.hpp"

void Start_Scene::Init()
{
	PlayerMgr::GetInst()->Init();

	const auto mapVec = TileMgr::GetInst()->GetTileVec("Res\\Map\\Start_Scene.json");
	
	CreateMapObjects(mapVec);
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::GROUND);
	SetNextScene(L"First_Scene");
}


void Start_Scene::Update()
{
	Scene::Update();
}

void Start_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Start_Scene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}

bool Start_Scene::CanChangeNextScene()
{
	return Scene::CanChangeNextScene();
}

bool Start_Scene::CanChangePrevScene()
{
	return Scene::CanChangePrevScene();
}
