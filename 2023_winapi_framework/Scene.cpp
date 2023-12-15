#include "pch.h"
#include "Scene.h"
#include "CollisionMgr.h"
#include "Core.h"
#include "PlayerMgr.h"
#include "Object.h"
#include "ResMgr.h"

Scene::Scene()
{

}

Scene::~Scene()
{
	Release();
}

void Scene::Init()
{
	PlayerMgr::GetInst()->Init();
	m_pBackgroundTex = ResMgr::GetInst()->TexLoad(L"BackGround", L"Texture\\Background_1.bmp");
}

void Scene::SetNextScene(wstring _nextSceneName, wstring _prevSceneName)
{
	m_nextSceneName = _nextSceneName;
	m_prevSceneName = _prevSceneName;
}

void Scene::Update()
{
	PlayerMgr::GetInst()->Update();
	for (UINT i = 0; i < (UINT)OBJECT_GROUP::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); ++j)
		{
			if(!m_vecObj[i][j]->GetIsDead())
				m_vecObj[i][j]->Update();
		}
	}
}

void Scene::FinalUpdate()
{
	for (UINT i = 0; i < (UINT)OBJECT_GROUP::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); ++j)
		{
			m_vecObj[i][j]->FinalUpdate();
		}
	}
}

void Scene::Render(HDC _dc)
{
	if(m_pBackgroundTex != nullptr)
	{
		POINT ptResolution = Core::GetInst()->GetResolution();

		BitBlt(_dc
			, 0
			, 0
			, ptResolution.x, ptResolution.y, m_pBackgroundTex->GetDC()
			, 0, 0, SRCCOPY);
	}


	for (UINT i = 0; i < (UINT)OBJECT_GROUP::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size();)
		{
			if (!m_vecObj[i][j]->GetIsDead())
			{
				m_vecObj[i][j]->Render(_dc);
				++j;
			}
			else
				m_vecObj[i].erase(m_vecObj[i].begin() + j);
		}
	}



}


void Scene::Release()
{
	for (UINT i = 0; i < (UINT)OBJECT_GROUP::END; ++i)
	{
		if(i != (UINT)OBJECT_GROUP::PLAYER)
		{
			for (size_t j = 0; j < m_vecObj[i].size(); ++j)
			{
				delete m_vecObj[i][j];
			}
		}
		m_vecObj[i].clear();
	}
	CollisionMgr::GetInst()->CheckReset();
}

bool Scene::CanChangeNextScene()
{
	auto resolution = Core::GetInst()->GetResolution();

	if (PlayerMgr::GetInst()->GetPlayer()->GetPos().y <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Scene::CanChangePrevScene()
{
	auto resolution = Core::GetInst()->GetResolution();

	if (PlayerMgr::GetInst()->GetPlayer()->GetPos().y >= resolution.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
