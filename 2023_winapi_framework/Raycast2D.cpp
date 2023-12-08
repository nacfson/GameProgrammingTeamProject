#include "pch.h"
#include "Raycast2D.h"
#include "Object.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "Collider.h"

Raycast2D::Raycast2D()
{
}

Raycast2D::Raycast2D(OBJECT_GROUP _eObjectGroup)
{
	m_eTargetGroup = _eObjectGroup;
}

Raycast2D::~Raycast2D()
{
}

Collider* Raycast2D::ShootRay(Vec2 _pos,Vec2 _dir, float _distance)
{
	std::shared_ptr<Scene> pCurScene = SceneMgr::GetInst()->GetCurScene();
	std::vector<Object*> _objects = pCurScene->GetGroupObject(OBJECT_GROUP::GROUND);

	std::vector<Collider*> _checkedColliders;

	for(Object* obj : _objects)
	{
		if(nullptr == obj->GetCollider())
		{
			continue;
		}

		const Vec2& objPos = obj->GetCollider()->GetFinalPos();
		const Vec2& colScale = obj->GetCollider()->GetScale();


		const Vec2& rayStartPos = _pos;
		const Vec2& rayEndPos = _pos + (m_vDir * m_fDistance);

		bool xIn = objPos.x - colScale.x * 0.5f <= rayStartPos.x && rayStartPos.x <= objPos.x + colScale.x * 0.5f;
		bool yIn = objPos.y - colScale.y * 0.5f >= rayStartPos.y;

		bool isRay = xIn && yIn;

 		if(isRay)
		{
			if(obj->GetObjectGroup() == m_eTargetGroup)
			{
				_checkedColliders.push_back(obj->GetCollider());
			}
		}
	}

	Collider* nearestObj = nullptr;

	float nearVal = 10000.f;
	for(Collider* col : _checkedColliders)
	{
		float vCompareVal = abs(_pos.x - col->GetFinalPos().x) + abs(_pos.y - col->GetFinalPos().y);

		if (nullptr == nearestObj)
		{
			nearestObj = col;
			nearVal = vCompareVal;
			continue;
		}
			
		if(nearVal > vCompareVal)
		{
			nearestObj = col;
			nearVal = vCompareVal;
			continue;
		}
	}
	if(nearestObj == nullptr)
	{
		assert("wtf");
	}

	return nearestObj;
}