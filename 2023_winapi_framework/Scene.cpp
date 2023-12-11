#include "pch.h"
#include "Scene.h"

#include "Core.h"
#include "PlayerMgr.h"
#include "Object.h"
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
