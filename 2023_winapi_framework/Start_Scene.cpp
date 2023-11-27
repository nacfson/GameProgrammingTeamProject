#include "pch.h"
#include "Start_Scene.h"
#include "Object.h"
#include "Core.h"
#include "Player.h"
#include "Monster.h"
#include "KeyMgr.h"
#include "CollisionMgr.h"
#include "ResMgr.h"
#include "Ground.h"
#include "Slider.h"
#include "SceneMgr.h"
#include "EventMgr.h"
#include "PlayerMgr.h"
void Start_Scene::Init()
{
	if(PlayerMgr::GetInst()->IsChanged == false)
	{
		Player* pObj = new Player;
		pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
		pObj->SetScale(Vec2(100.f, 100.f));
		AddObject(pObj, OBJECT_GROUP::PLAYER);
	}
	else
	{
		Player* pObj = new Player;
	}


	//EventMgr::GetInst()->AddPlayer(pObj);

	// ���� ���� �������� ��ġ�� �غ��ô�.

	Vec2 vResolution = Core::GetInst()->GetResolution();


	float fGroundScale = 50.f; // ���� ũ��
	Vec2 groundScale = Vec2(fGroundScale, fGroundScale);

	Ground *pGround = new Ground(groundScale);
	pGround->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f, 600.f));
	pGround->SetScale(groundScale);

	AddObject(pGround, OBJECT_GROUP::GROUND);


	Slider *pSlider = new Slider;

	pObj->SetSlider(pSlider);
	AddObject(pSlider, OBJECT_GROUP::UI);

	// ���� ����
	ResMgr::GetInst()->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
	ResMgr::GetInst()->LoadSound(L"Shoot", L"Sound\\laserShoot.wav", false);
	ResMgr::GetInst()->Play(L"BGM");


	// �浹üũ�ؾߵǴ°͵��� ��������.
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::BULLET, OBJECT_GROUP::MONSTER);
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::GROUND);

	SetNextScene(L"First_Scene");
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
	return false;
}
