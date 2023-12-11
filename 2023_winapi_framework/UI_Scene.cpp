#include "pch.h"
#include "UI_Scene.h"
#include "Button.h"
#include "CollisionMgr.h"
#include "ResMgr.h"
#include "SceneMgr.h"
#include "Core.h"
#include "Texture.h"
void UI_Scene::Init()
{
	//Scene::Init();
	Button* btn = new Button();
	                                     
	btn->SetPos(Vec2(300.f, 450.f));
	btn->SetBtnAction([]() {SceneMgr::GetInst()->LoadScene(L"Start_Scene"); });

	m_pBackgroundTex = ResMgr::GetInst()->TexLoad(L"UI_Back",L"Texture\\rabbitAndTurtle.bmp");
	
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

void UI_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
	// POINT pResolution = Core::GetInst()->GetResolution();
	//
	// BitBlt(_dc
	// 	,(int)(0)
	// 	,(int)(0)
	// 	, pResolution.x,pResolution.y, m_pBackgroundTex->GetDC()
	// 	,0,0,SRCCOPY);
}
