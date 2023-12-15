#pragma once
#include "Object.h"
#include "Collider.h"
class Poop :
    public Object
{
public:
    Poop();
    ~Poop();

    void Update() override;
private:
    float m_moveSpeed;
};

