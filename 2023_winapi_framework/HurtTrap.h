#pragma once
#include "Object.h"
#include "Collider.h"
class HurtTrap :
    public Object
{
public:
    HurtTrap();
    ~HurtTrap();

    void Render(HDC _dc) override;

    void EnterCollision(Collider* _pOther) override;
};

