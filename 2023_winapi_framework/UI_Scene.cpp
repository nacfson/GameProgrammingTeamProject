#include "pch.h"
#include "UI_Scene.h"
#include "Button.h"
#include "CollisionMgr.h"

void UI_Scene::Init()
{
	//Scene::Init();
	Button* btn = new Button();
	                                     
	btn->SetPos(Vec2(300.f, 450.f));
	btn->SetSceneName(L"Start_Scene");
	btn->SetText(L"Start Game");
	
	AddObject(btn, OBJECT_GROUP::UI);
}

bool UI_Scene::CanChangeNextScene()
{
	return false;
}

bool UI_Scene::CanChangePrevScene()
{
	return false;
}
