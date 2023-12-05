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

	Vec2 vResolution = Core::GetInst()->GetResolution();

	const auto mapVec = TileMgr::GetInst()->GetTileVec("Res\\Map\\Start_Scene.json");

	int cnt = 0;
	for(const Tile& tile : mapVec)
	{
		//Vec2 groundScale = Vec2(100, 100);
		Vec2 groundScale = Vec2(tile.width, tile.height);
		Ground* pGround = new Ground(groundScale);
		Vec2 tilePos = Vec2(tile.x, tile.y);

		pGround->SetPos(tilePos);
		pGround->SetObjGroup(OBJECT_GROUP::GROUND);

		AddObject(pGround, OBJECT_GROUP::GROUND);
		cnt++;

		if(cnt == 10)
		{
			std::cout << "100";
		}
	}
	

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
