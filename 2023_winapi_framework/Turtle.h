#pragma once
#include "Object.h"
class Texture;
class Turtle :
    public Object
{
public:
    Turtle();
    ~Turtle();

public:
    void Update() override;
    void Render(HDC _dc) override;

private:
    Texture* m_pTex;
    float moveSpeed;
};

