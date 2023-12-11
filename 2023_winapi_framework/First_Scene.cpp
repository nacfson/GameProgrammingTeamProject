#include "pch.h"
#include "First_Scene.h"
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

	const auto mapVec = TileMgr::GetInst()->GetTileVec("Res\\Map\\Map2.json");


	CreateMapObjects(mapVec);
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
