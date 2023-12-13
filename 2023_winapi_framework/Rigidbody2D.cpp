#include "pch.h"
#include "Rigidbody2D.h"
#include "Collider.h"
#include "Object.h"
#include "TimeMgr.h"
#include "Core.h"
#include "Raycast2D.h"

void Rigidbody2D::Init()
{
	POINT resolution = Core::GetInst()->GetResolution();
	m_fResolutionMaxX = resolution.x;
	m_fResolutionMaxY = resolution.y;

	m_fApplyDeAcceleration = m_deAcceleration;

	const Vec2& finalPos = m_pCollider->GetFinalPos();
	const Vec2& colScale = m_pCollider->GetScale();
}

void Rigidbody2D::AddForce(Vec2&& direction, float power)
{
	m_velocity = m_velocity + Vec2((float)direction.x * power, (float)direction.y * power);
}

void Rigidbody2D::AddForce(Vec2& direction, float power)
{
	m_velocity = m_velocity + Vec2((float)direction.x * power, (float)direction.y * power);
}

void Rigidbody2D::MoveInterpolation(Collider* _pOther)
{
	if (_pOther == nullptr) return;


	Vec2 vOriginPos = m_pCollider->GetFinalPos();
	Vec2 vOriginScale = m_pCollider->GetScale();


	Vec2 vOtherPos = _pOther->GetFinalPos();
	Vec2 vOtherScale = _pOther->GetScale();


	float fXInterpolation = m_pCollider->GetFinalPos().x;
	float fYInterpolation = m_pCollider->GetFinalPos().y;


	if(vOriginPos.y - vOriginScale.y * 0.5f <= vOtherPos.y - vOtherScale.y * 0.5f && m_velocity.y <= 0.f)
	{
		if (vOriginPos.x > vOtherPos.x && m_velocity.x < 0.f)
		{
			fXInterpolation = vOtherPos.x + vOtherScale.x * 0.5f + vOriginScale.x * 0.5f;
		}
		else if (vOriginPos.x < vOtherPos.x && m_velocity.x > 0.f)
		{
			fXInterpolation = vOtherPos.x - vOtherScale.x * 0.5f - vOriginScale.x * 0.5f;
		}
	}


	if (vOriginPos.y > vOtherPos.y && m_velocity.y < 0.f)
	{
		fYInterpolation = vOtherPos.y + vOtherScale.y * 0.5f + vOriginScale.y * 0.5f;
	}
	else if (vOriginPos.y < vOtherPos.y && m_velocity.y > 0.f)
	{
		fYInterpolation = vOtherPos.y - vOtherScale.y * 0.5f - vOriginScale.y * 0.5f;
	}

	m_object->SetPos(Vec2(fXInterpolation, fYInterpolation));
}

void Rigidbody2D::EnterCollision(Collider* _pOther)
{
	m_pOtherCol = _pOther;
}

void Rigidbody2D::ExitCollision(Collider* _pOther)
{

	m_pOtherCol = nullptr;
	m_bIsGrounded = false;
}

void Rigidbody2D::StayCollision(Collider* _pOther)
{
	if(_pOther->GetObj()->GetObjectGroup() == OBJECT_GROUP::GROUND)
	{
		Vec2 vOriginPos = m_pCollider->GetFinalPos();
		Vec2 vOriginScale = m_pCollider->GetScale();

		Vec2 vOtherPos = _pOther->GetFinalPos();
		Vec2 vOtherScale = _pOther->GetScale();

		// Check if the collision is from above
		if (vOriginPos.y < vOtherPos.y && vOriginPos.y + vOriginScale.y * 0.5f >= vOtherPos.y - vOtherScale.y * 0.5f)
		{
			m_bIsGrounded = true;
		}
		else
		{
			m_bIsGrounded = false;
		}
		MoveInterpolation(_pOther);
	}
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
	if(m_bIsGrounded)
	{
		m_fApplyDeAcceleration = m_fGroundedDeAcceleration;

	}
	else
	{
		m_fApplyDeAcceleration = m_deAcceleration;
		ApplyGravity();
	}
	ApplyDeAccel();
	ApplyVelocity();
	if(m_bIsGrounded)
	{
		if (m_velocity.y > 0.f)
		{
			m_velocity = Vec2(0.f, 0.f);
		}
	}
}

void Rigidbody2D::FinalUpdate()
{
	
}

void Rigidbody2D::ApplyGravity()
{              
	m_velocity.y += m_gravity * m_gravityMultiply * TimeMgr::GetInst()->GetDT();
}

void Rigidbody2D::ApplyVelocity()
{
	Vec2 curPos = m_object->GetPos();
	
	curPos = curPos + m_velocity;


	float fYBouncePower = 1.f;
	float fXBouncePower = 0.7f;
	if(curPos.x > m_fResolutionMaxX)
	{
		curPos.x = m_fResolutionMaxX;
		//AddForce(Vec2(-fXBouncePower,-fYBouncePower),1.f);
	}
	if((curPos.x < 0.f))
	{
		curPos.x = 0.f;
		//AddForce(Vec2(fXBouncePower,-fYBouncePower),1.f);
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