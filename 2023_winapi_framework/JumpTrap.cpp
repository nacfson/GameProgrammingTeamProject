#include "pch.h"
#include "JumpTrap.h"
#include "PlayerMgr.h"
#include "Player.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animation.h"
#include "Animator.h"
JumpTrap::JumpTrap() : m_jumpPower(0.f), m_jumpDir(Vec2(0.f,0.f)), m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"JumpTrap", L"Texture\\JumpTrap.bmp");

	CreateCollider();
	GetCollider()->SetScale(Vec2(100.f, 52.f));

	CreateAnimator();
	GetAnimator()->CreateAnim(L"JumpTrap", m_pTex, Vec2(0.f, 0.f), Vec2(100.f, 52.f), Vec2(0.f, 0.f), 1, 1.f);
	m_eGroup = OBJECT_GROUP::Trap;

	GetAnimator()->PlayAnim(L"JumpTrap", false);
}

JumpTrap::~JumpTrap()
{
}

void JumpTrap::Render(HDC _dc)
{
	Component_Render(_dc);
}

void JumpTrap::EnterCollision(Collider* _pOther)
{
	if (_pOther->GetObj()->GetObjectGroup() == OBJECT_GROUP::PLAYER) 
	{
		PlayerMgr::GetInst()->GetPlayer()->SetPower(m_jumpDir,m_jumpPower * 1.5f);
	}
}
