#include "pch.h"
#include "JumpTrap.h"
#include "PlayerMgr.h"
#include "Player.h"
JumpTrap::JumpTrap() : m_jumpPower(0.f), m_jumpDir(Vec2(0.f,0.f))
{
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

	}
}
