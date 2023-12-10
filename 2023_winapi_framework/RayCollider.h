#pragma once
#include "Collider.h"
class Player;
class RayCollider : public Collider
{
public:
    RayCollider(Player* _player,ERAY_DIR _rayDir);
    ~RayCollider();
public:
    ERAY_DIR m_eRayDir;
        
    void StayCollision(Collider* _pOther) override;
    void EnterCollision(Collider* _pOther) override;
    void ExitCollision(Collider* _pOther) override;

private:
    Player* m_pPlayer;
};
