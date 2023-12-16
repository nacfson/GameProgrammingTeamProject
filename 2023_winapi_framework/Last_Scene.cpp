#include "pch.h"
#include "Last_Scene.h"
#include "PlayerMgr.h"
#include "CollisionMgr.h"
#include "ResMgr.h"
#include "Button.h"
#include "Core.h"
#include "SceneMgr.h"

void Last_Scene::Init()
{
    //MapScene::Init();
	PlayerMgr::GetInst()->Release();
	m_pBackgroundTex = ResMgr::GetInst()->TexLoad(L"Finish",L"Texture\\Finish.bmp");

	auto exitBtnTex = ResMgr::GetInst()->TexLoad(L"NormalBtn", L"Texture\\BackBtn.bmp");

	HWND hWnd = Core::GetInst()->GetHwnd();
	Vec2 btnScale = Vec2(120.f, 70.f);
    Button* pButton = new Button;
	pButton->SetPos(Vec2(300.f, 750.f));
	pButton->SetScale(btnScale);
	pButton->SetBtnAction([hWnd]() { SendMessage(hWnd, WM_CLOSE, 0, 0); });
	pButton->SetTexture(exitBtnTex);
	pButton->SetText(L"EXIT", Vec2(300.f - btnScale.x * 0.25f, 750.f - btnScale.y * 0.25f));
    //std::string path = "Res\\Map\\Map" + std::to_string(m_iMapIdx) + ".json";
    //const auto mapVec = TileMgr::GetInst()->GetTileVec(path);
	
    //CreateMapObjects(mapVec);
    //CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::GROUND);
    //SetNextScene(L"Last_Scene", L"Eighth_Scene");
	AddObject(pButton, OBJECT_GROUP::UI);
}

bool Last_Scene::CanChangeNextScene()
{
	return false;
}

bool Last_Scene::CanChangePrevScene()
{
	return false;
}

void Last_Scene::Update()
{
	Scene::Update();
}
