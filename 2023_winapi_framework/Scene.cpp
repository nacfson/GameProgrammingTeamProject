#include "pch.h"
#include "Scene.h"
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
		if (i == static_cast<UINT>(OBJECT_GROUP::PLAYER)) continue;
		for (size_t j = 0; j < m_vecObj[i].size(); ++j)
		{
			delete m_vecObj[i][j];
		}
		m_vecObj[i].clear();
	}
}

bool Scene::CanChangeNextScene()
{
	return false;
}

bool Scene::CanChangePrevScene()
{
	return false;
}
