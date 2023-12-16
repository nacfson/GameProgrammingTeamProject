#include "pch.h"
#include "SceneMgr.h"

#include "Core.h"
#include "Eighth_Scene.h"
#include "Fifth_Scene.h"
#include "Start_Scene.h"
#include "Game_Scene.h"
#include "First_Scene.h"
#include "PlayerMgr.h"
#include "SelectGDI.h"
#include "UI_Scene.h"
#include "Second_Scene.h"
#include "Third_Scene.h"
#include "Fourth_Scene.h"
#include "Last_Scene.h"
#include "Ninth_Scene.h"
#include "PathMgr.h"
#include "Seventh_Scene.h"
#include "Sixth_Scene.h"

void SceneMgr::Init()
{
	m_pCurScene = nullptr;
	
	RegisterScene(L"Start_Scene",std::make_shared<Start_Scene>());
	RegisterScene(L"Game_Scene", std::make_shared<Game_Scene>());
	RegisterScene(L"First_Scene", std::make_shared<First_Scene>());
	RegisterScene(L"Second_Scene",std::make_shared<Second_Scene>());
	RegisterScene(L"Third_Scene",std::make_shared<Third_Scene>());
	RegisterScene(L"Fourth_Scene",std::make_shared<Fourth_Scene>());
	RegisterScene(L"Fifth_Scene",std::make_shared<Fifth_Scene>());
	RegisterScene(L"Sixth_Scene",std::make_shared<Sixth_Scene>());
	RegisterScene(L"Seventh_Scene",std::make_shared<Seventh_Scene>());
	RegisterScene(L"Eighth_Scene",std::make_shared<Eighth_Scene>());
	RegisterScene(L"Ninth_Scene",std::make_shared<Ninth_Scene>());
	RegisterScene(L"Last_Scene", std::make_shared<Last_Scene>());
	RegisterScene(L"UI_Scene", std::make_shared<UI_Scene>());
	
	LoadScene(L"UI_Scene");
}

void SceneMgr::Update()
{
	m_pCurScene->Update();
	m_pCurScene->FinalUpdate();
}

void SceneMgr::Render(HDC _dc)
{
	int test = AddFontResource(L"Res\\Texture\\한국기계연구원_bold.ttf"); // 한번만 하면 되는건가
	
	HFONT hFont = CreateFont(30, 0, 0, 0, FW_BOLD, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, L"한국기계연구원_bold");
	//SelectObject(_dc, hFont);
	SelectGDI selectFont(_dc, hFont);
	
	m_pCurScene->Render(_dc);
}

void SceneMgr::LoadScene(const wstring _scenename)
{
	if (m_pCurScene != nullptr)
	{
		m_pCurScene->Release();
		m_pCurScene = nullptr;
	}

	auto iter = m_mapScenes.find(_scenename);
	if (iter != m_mapScenes.end())
	{
		m_pCurScene = iter->second;
		m_pCurScene->Init();
	}
}

void SceneMgr::RegisterScene(const wstring& _scenename, std::shared_ptr<Scene> _scene)
{
	m_mapScenes.insert(m_mapScenes.end(), {_scenename, _scene});
}
