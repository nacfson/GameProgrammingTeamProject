#include "pch.h"
#include "Ground.h"
#include "Collider.h"

Ground::Ground(Vec2& const _colScale )
{
	CreateCollider();
	GetCollider()->SetScale(_colScale);
}

Ground::~Ground()
{

}

//void Ground::Render(HDC _dc)
//{
//	Component_Render(_dc);
//}
