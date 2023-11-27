#include "pch.h"
#include "Start_Scene.h"
#include "Object.h"
#include "Core.h"
#include "KeyMgr.h"
#include "CollisionMgr.h"
#include "ResMgr.h"
#include "Ground.h"
#include "SceneMgr.h"
#include "PlayerMgr.h"
void Start_Scene::Init()
{
	//EventMgr::GetInst()->AddPlayer(pObj);

	// ���� ���� �������� ��ġ�� �غ��ô�.
	PlayerMgr::GetInst()->Init();

	Vec2 vResolution = Core::GetInst()->GetResolution();


	float fGroundScale = 50.f; // ���� ũ��
	Vec2 groundScale = Vec2(fGroundScale, fGroundScale);

	Ground *pGround = new Ground(groundScale);
	pGround->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f, 600.f));
	pGround->SetScale(groundScale);

	AddObject(pGround, OBJECT_GROUP::GROUND);


	// ���� ����
	ResMgr::GetInst()->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
	ResMgr::GetInst()->LoadSound(L"Shoot", L"Sound\\laserShoot.wav", false);
	ResMgr::GetInst()->Play(L"BGM");


	// �浹üũ�ؾߵǴ°͵��� ��������.
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::BULLET, OBJECT_GROUP::MONSTER);
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::GROUND);

	SetNextScene(L"First_Scene",L"First_Scene");
}

void Start_Scene::Update()
{
	Scene::Update();

	if (KEY_DOWN(KEY_TYPE::ENTER))
		SceneMgr::GetInst()->LoadScene(m_nextSceneName);
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
	auto resolution = Core::GetInst()->GetResolution();

	if(PlayerMgr::GetInst()->GetPlayer()->GetPos().y <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Start_Scene::CanChangePrevScene()
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
