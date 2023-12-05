#include "pch.h"
#include "UI_Scene.h"
#include "Button.h"
#include "CollisionMgr.h"
#include "SceneMgr.h"

void UI_Scene::Init()
{
	//Scene::Init();
	Button* btn = new Button();
	                                     
	btn->SetPos(Vec2(300.f, 450.f));
	btn->SetBtnAction([]() {SceneMgr::GetInst()->LoadScene(L"Start_Scene"); });
	
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
