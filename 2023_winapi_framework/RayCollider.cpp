#include "pch.h"
#include "RayCollider.h"

#include "Player.h"

RayCollider::RayCollider(Player* _player,ERAY_DIR _rayDir)
{
    m_pPlayer = _player;
    m_eRayDir = _rayDir;
}

RayCollider::~RayCollider()
{
    
}

void RayCollider::StayCollision(Collider* _pOther)
{
    Collider::StayCollision(_pOther);
}

void RayCollider::EnterCollision(Collider* _pOther)
{
    Collider::EnterCollision(_pOther);
}

void RayCollider::ExitCollision(Collider* _pOther)
{
    Collider::ExitCollision(_pOther);
}
