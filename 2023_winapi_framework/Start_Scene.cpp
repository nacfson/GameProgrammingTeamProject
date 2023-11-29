#include "pch.h"
#include "Start_Scene.h"
#include "Collider.h"
#include "Object.h"
#include "Core.h"
#include "CollisionMgr.h"
#include "Ground.h"
#include "PlayerMgr.h"

void Start_Scene::Init()
{
	PlayerMgr::GetInst()->Init();

		Vec2 vResolution = Core::GetInst()->GetResolution();


		float fGroundScale = 50.f;
		auto underGroundScale = Vec2(static_cast<float>(Core::GetInst()->GetResolution().x), fGroundScale);

		Vec2 groundScale = Vec2(fGroundScale, fGroundScale);

		Ground* pGround = new Ground(groundScale);
		pGround->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f, 600.f));

		pGround->SetScale(underGroundScale);
		pGround->GetCollider()->SetScale(underGroundScale);

		Ground* pGround1 = new Ground(groundScale);
		pGround1->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f + 300.f, 500.f));
		pGround1->SetScale(groundScale);

		Ground* pGround2 = new Ground(groundScale);
		pGround2->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f, 420.f));
		pGround2->SetScale(groundScale);

		Ground* pGround3 = new Ground(groundScale);
		pGround3->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f + 300.f, 300.f));
		pGround3->SetScale(groundScale);

		Ground* pGround4 = new Ground(groundScale);
		pGround4->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f, 200.f));
		pGround4->SetScale(groundScale);

		AddObject(pGround, OBJECT_GROUP::GROUND);
		AddObject(pGround1, OBJECT_GROUP::GROUND);
		AddObject(pGround2, OBJECT_GROUP::GROUND);
		AddObject(pGround3, OBJECT_GROUP::GROUND);


		CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::BULLET, OBJECT_GROUP::MONSTER);
		CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::GROUND);

		SetNextScene(L"First_Scene");
}

void Start_Scene::Update()
{
	Scene::Update();
}	

void Start_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Start_Scene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}

bool Start_Scene::CanChangeNextScene()
{
	return Scene::CanChangeNextScene();
}

bool Start_Scene::CanChangePrevScene()
{
	return Scene::CanChangePrevScene();
}
