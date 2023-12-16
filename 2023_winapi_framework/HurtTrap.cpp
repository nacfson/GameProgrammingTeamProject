#include "pch.h"
#include "HurtTrap.h"
#include "PlayerMgr.h"
#include "Player.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
HurtTrap::HurtTrap() : m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"HurtTrap", L"Texture\\HurtTrap.bmp");

	CreateCollider();
	GetCollider()->SetScale(Vec2(50.f, 40.f));

	CreateAnimator();
	GetAnimator()->CreateAnim(L"HurtTrap", m_pTex, Vec2(0.f, 0.f), Vec2(48.f, 45.f), Vec2(0.f, 0.f), 1, 1.f);
	GetAnimator()->PlayAnim(L"HurtTrap", false);
	m_eGroup = OBJECT_GROUP::Trap;
}

HurtTrap::~HurtTrap()
{
}

void HurtTrap::Render(HDC _dc)
{
	Component_Render(_dc);
}

void HurtTrap::EnterCollision(Collider* _pOther)
{
	if (_pOther->GetObj()->GetObjectGroup() == OBJECT_GROUP::PLAYER)
	{
		PlayerMgr::GetInst()->GetPlayer()->GetHit();
	}
}
