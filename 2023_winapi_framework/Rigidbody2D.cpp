#include "pch.h"
#include "Rigidbody2D.h"
#include "Collider.h"
#include "Object.h"
#include "TimeMgr.h"

Rigidbody2D::Rigidbody2D(Object* _object, Collider* _collider)
{
	m_object = _object;
	m_collider = _collider;

	m_velocity = Vec2(0.f, 0.f);
}

Rigidbody2D::~Rigidbody2D()
{
	//delete m_collider;
	//delete m_object;
}

void Rigidbody2D::Update()
{
	//주석다는척.
	if (0 == m_collider->IsGrounded())
	{
		ApplyGravity();
	}
	else
	{
		m_velocity.y = 0.f;
	}

	ApplyDeAccel();
	ApplyVelocity();
}

void Rigidbody2D::ApplyGravity()
{
	float dt = TimeMgr::GetInst()->GetDT();
	float temp = m_gravity * m_gravityMultiply;
	m_velocity.y += m_gravity * m_gravityMultiply * TimeMgr::GetInst()->GetDT();
}

void Rigidbody2D::ApplyVelocity()
{
	Vec2 curPos = m_object->GetPos();
	//curPos.y += m_gravity * m_gravityMultiply * TimeMgr::GetInst()->GetDT();
	curPos = curPos + m_velocity;
	m_object->SetPos(curPos);
}

void Rigidbody2D::ApplyDeAccel()
{
	if (m_velocity.x > 0)
	{
		m_velocity.x -= m_deAcceleration * TimeMgr::GetInst()->GetDT();
	}
	else if (m_velocity.x < 0)
	{
		m_velocity.x += m_deAcceleration * TimeMgr::GetInst()->GetDT();
	}
}
