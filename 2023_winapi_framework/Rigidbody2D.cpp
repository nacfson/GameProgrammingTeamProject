#include "pch.h"
#include "Rigidbody2D.h"
#include "Collider.h"
#include "Object.h"
#include "TimeMgr.h"
#include "Core.h"

void Rigidbody2D::Init()
{
	POINT resolution = Core::GetInst()->GetResolution();
	m_fResolutionMaxX = resolution.x;
	m_fResolutionMaxY = resolution.y;

	m_fApplyDeAcceleration = m_deAcceleration;
}

void Rigidbody2D::AddForce(Vec2&& direction, float power)
{
	m_velocity = m_velocity + Vec2((float)direction.x * power, (float)direction.y * power);
}

void Rigidbody2D::AddForce(Vec2& direction, float power)
{
	m_velocity = m_velocity + Vec2((float)direction.x * power, (float)direction.y * power);
}



void Rigidbody2D::EnterCollision(Collider* _pOther)
{
	//땅 오브젝트 그룹인 경우
	Object* pOtherObj = _pOther->GetObj();

	if(_pOther->GetObj()->GetObjectGroup() == OBJECT_GROUP::GROUND)
	{
		m_pOtherCol = _pOther;

		Vec2 vMyPos = m_pCollider->GetFinalPos();
		Vec2 vMyScale = m_pCollider->GetScale();

		Vec2 vOtherPos = _pOther->GetFinalPos();
		Vec2 vOtherScale = _pOther->GetScale();

		float fLen = abs(vOtherPos.y - vMyPos.y);
		(vOtherPos.y * 0.5f + vMyScale.y * 0.5f) - fLen;

		vOtherPos = pOtherObj->GetPos();
		vOtherPos.y += fLen;
	}
}

void Rigidbody2D::ExitCollision(Collider* _pOther)
{
	if (_pOther->GetObj()->GetObjectGroup() == OBJECT_GROUP::GROUND)
	{
		m_pOtherCol = nullptr;
	}
}

void Rigidbody2D::StayCollision(Collider* _pOther)
{

}

Rigidbody2D::Rigidbody2D(Object* _object, Collider* _collider)
{
	m_object = _object;
	m_pCollider = _collider;

	m_velocity = Vec2(0.f, 0.f);
}

Rigidbody2D::~Rigidbody2D()
{

}

void Rigidbody2D::Update()
{
	if (false == m_pCollider->IsGrounded())
	{
		m_fApplyDeAcceleration = m_deAcceleration;
		ApplyGravity();
	}
	else if(m_velocity.y >= 0.1f)
	{
		m_fApplyDeAcceleration = m_fGroundedDeAcceleration;
		m_velocity.y = 0.f;
	}


	ApplyDeAccel();
	ApplyVelocity();
}

void Rigidbody2D::FinalUpdate()
{
	if(nullptr != m_pOtherCol)
	{
	}
}

void Rigidbody2D::ApplyGravity()
{              
	m_velocity.y += m_gravity * m_gravityMultiply * TimeMgr::GetInst()->GetDT();
}

void Rigidbody2D::ApplyVelocity()
{
	Vec2 curPos = m_object->GetPos();
	//curPos.y += m_gravity * m_gravityMultiply * TimeMgr::GetInst()->GetDT();
	curPos = curPos + m_velocity;

	if(curPos.x >= m_fResolutionMaxX)
	{
		curPos.x = m_fResolutionMaxX;
	}
	if((curPos.x <= 0.f))
	{
		curPos.x = 0.f;
	}

	m_object->SetPos(curPos);
}


void Rigidbody2D::ApplyDeAccel()
{
	if (m_velocity.x > 0)
	{
		m_velocity.x -= m_fApplyDeAcceleration * TimeMgr::GetInst()->GetDT();
	}
	else if (m_velocity.x < 0)
	{
		m_velocity.x += m_fApplyDeAcceleration * TimeMgr::GetInst()->GetDT();
	}
}
