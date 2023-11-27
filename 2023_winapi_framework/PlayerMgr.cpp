#include "pch.h"
#include "PlayerMgr.h"
#include "SceneMgr.h"
#include "Core.h"
#include "Scene.h"
#include "Slider.h"

void PlayerMgr::Init()
{
	if(GetPlayer() == nullptr)
	{
		m_pPlayer = new Player();

		m_pPlayer->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
		m_pPlayer->SetScale(Vec2(100.f, 100.f));
	}
	m_pPlayer->Init();

	Slider* pSlider = new Slider;

	m_pPlayer->SetSlider(pSlider);

	SceneMgr::GetInst()->GetCurScene()->AddObject(m_pPlayer, OBJECT_GROUP::PLAYER);
	SceneMgr::GetInst()->GetCurScene()->AddObject(pSlider, OBJECT_GROUP::UI);
}

void PlayerMgr::Update()
{
	auto curScene = SceneMgr::GetInst()->GetCurScene();
	if(curScene->CanChangeNextScene())
	{
		SceneMgr::GetInst()->LoadScene(curScene->GetNextSceneName());

		Vec2 pos = m_pPlayer->GetPos();
		auto resolution = Core::GetInst()->GetResolution();
		pos.y = 0.f;

		m_pPlayer->SetPos(pos);
	}

	if(curScene->CanChangePrevScene())
	{
		wstring sceneName = curScene->GetNextSceneName();
		if(sceneName == L"")
		{
			return;
		}
		SceneMgr::GetInst()->LoadScene(curScene->GetNextSceneName());

		Vec2 pos = m_pPlayer->GetPos();
		auto resolution = Core::GetInst()->GetResolution();
		pos.y = -resolution.y * 0.5f;

		m_pPlayer->SetPos(pos);
	}
}

void PlayerMgr::Release()
{

}

