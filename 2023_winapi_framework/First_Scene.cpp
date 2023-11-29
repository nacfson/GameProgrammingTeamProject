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
		Vec2 groundScale = Vec2(100.f, 100.f);
		Ground* pGround = new Ground(groundScale);
		pGround->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f, 600.f));
		pGround->SetScale(groundScale);

		AddObject(pGround, OBJECT_GROUP::GROUND);

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
