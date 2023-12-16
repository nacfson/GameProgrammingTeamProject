#pragma once
#include "Object.h"
#include "Collider.h"
class Texture;
class HurtTrap :
    public Object
{
public:
    HurtTrap();
    ~HurtTrap();

    void Render(HDC _dc) override;

    void EnterCollision(Collider* _pOther) override;
private:
    Texture* m_pTex;
};

