#include "pch.h"
#include "Rigidbody2D.h"
#include "Collider.h"
#include "Object.h"
#include "TimeMgr.h"

Rigidbody2D::Rigidbody2D(Object* _object, Collider* _collider)
{
	m_object = _object;
	m_collider = _collider;
}

Rigidbody2D::~Rigidbody2D()
{

}

void Rigidbody2D::Update()
{
	//주석다는척.
	if (0 == m_collider->IsGrounded())
	{
		ApplyGravity();
	}
}

void Rigidbody2D::ApplyGravity()
{
	Vec2 curPos = m_object->GetPos();
	curPos.y += m_gravity * m_gravityMultiply * TimeMgr::GetInst()->GetDT();
	m_object->SetPos(curPos);
}
