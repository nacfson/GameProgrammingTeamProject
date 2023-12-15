#include "pch.h"
#include "Ground.h"
#include "Collider.h"
#include "Texture.h"
Ground::Ground(Vec2& const _colScale )
{
	CreateCollider();
	GetCollider()->SetScale(_colScale);
}

Ground::~Ground()
{

}

void Ground::Render(HDC _dc)
{
	//Object::Render(_dc);
	Component_Render(_dc);
	if(m_pTex == nullptr) return;

	int width = m_pTex->GetWidth();
	int height = m_pTex->GetHeight();

	StretchBlt(_dc
		, (int)(GetPos().x - GetScale().x * 0.5f)
		, (int)(GetPos().y - GetScale().y * 0.5f)
		, (int)(GetScale().x)
		, (int)(GetScale().y)
		, m_pTex->GetDC()
		,0,0,
		width,height
		,SRCCOPY
	);
}