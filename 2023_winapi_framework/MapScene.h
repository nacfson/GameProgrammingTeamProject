#pragma once
#include "Scene.h"
class Text;
static const Vec2 s_vTextPos = Vec2(450.f,20.f); 

class MapScene : public Scene
{
public:
    void SetMapIdx(int _idx);
    void Render(HDC _dc) override;
protected:
    int m_iMapIdx;
private:
    Text* m_text;
};
