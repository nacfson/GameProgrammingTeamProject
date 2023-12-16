#pragma once
#include "Object.h"
#include "Collider.h"
class Texture;
class JumpTrap :
    public Object
{
public:
    JumpTrap();
    ~JumpTrap();

    void Render(HDC _dc) override;

    void EnterCollision(Collider* _pOther) override;

    void SetTrapInfo(float power, Vec2 dir) 
    {
        m_jumpPower = power;
        m_jumpDir = dir;
    }
private:
    Texture* m_pTex;
    Vec2 m_jumpDir;
    float m_jumpPower;
};

