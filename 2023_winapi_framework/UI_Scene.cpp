#include "pch.h"
#include "UI_Scene.h"
#include "Button.h"
#include "CollisionMgr.h"
#include "ResMgr.h"
#include "SceneMgr.h"
#include "Core.h"
#include "Texture.h"
#include "Core.h"


void UI_Scene::Init()
{


	Button* btn = new Button();
	Button* exitBtn = new Button();

	auto startBtnTex = ResMgr::GetInst()->TexLoad(L"NormalBtn",L"Texture\\BackBtn.bmp");
	auto exitBtnTex = ResMgr::GetInst()->TexLoad(L"NormalBtn",L"Texture\\BackBtn.bmp");

	HWND hWnd = Core::GetInst()->GetHwnd();
	Vec2 btnScale = Vec2(120.f,70.f);


	                                     
	btn->SetPos(Vec2(300.f, 450.f));
	btn->SetScale(btnScale);
	btn->SetBtnAction([]() {SceneMgr::GetInst()->LoadScene(L"Start_Scene"); });
	btn->SetTexture(startBtnTex);
	btn->SetText(L"START",Vec2(300.f - btnScale.x * 0.44f,450.f - btnScale.y * 0.25f) );

	exitBtn->SetPos(Vec2(300.f,600.f));
	exitBtn->SetScale(btnScale);
	exitBtn->SetBtnAction([hWnd](){ SendMessage(hWnd,WM_CLOSE,0,0); });
	exitBtn->SetTexture(exitBtnTex);
	exitBtn->SetText(L"EXIT",Vec2(300.f - btnScale.x * 0.3f,600.f - btnScale.y * 0.25f) );
	
	
	m_pBackgroundTex = ResMgr::GetInst()->TexLoad(L"UI_Back",L"Texture\\rabbitAndTurtle.bmp");
	AddObject(btn, OBJECT_GROUP::UI);
	AddObject(exitBtn, OBJECT_GROUP::UI);
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
	POINT pResolution = Core::GetInst()->GetResolution();

	BitBlt(_dc
		, (int)(0)
		, (int)(0)
		, pResolution.x, pResolution.y, m_pBackgroundTex->GetDC()
		, 0, 0, SRCCOPY);
	Scene::Render(_dc);

}
