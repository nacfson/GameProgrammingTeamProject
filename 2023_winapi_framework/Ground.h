#pragma once
#include "Object.h"

class Texture;
class Ground : public Object
{
public:
	Ground(Vec2& const _colScale);
	~Ground();
//	void Render(HDC _dc) override;

private:
	Texture* m_pTex;
};

