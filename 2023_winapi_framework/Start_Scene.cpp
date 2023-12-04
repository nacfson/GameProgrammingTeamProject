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
	std::string pMapPath =
		"D:\\C++\\CppStudy\\GameP\\GameProgrammingProject\\2023_winapi_framework\\Map\\Start_Scene.json";

	std::ifstream file(pMapPath);

	if (!file.is_open())
	{
		std::cerr << "파일을 열 수 없습니다." << std::endl;
		return;
	}

	std::string jsonString((std::istreambuf_iterator(file)), std::istreambuf_iterator<char>());

	rapidjson::Document document{};
	document.Parse(jsonString.c_str());

	if (document.HasParseError())
	{
		assert("Can't Parse Json");
		return;
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
