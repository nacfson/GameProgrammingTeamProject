#include "pch.h"
#include "HurtTrap.h"
#include "PlayerMgr.h"
#include "Player.h"
HurtTrap::HurtTrap()
{
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

	}
}
