#pragma once
#include "Collider.h"
class Object;
class Raycast2D;
class Rigidbody2D
{
private :
	float m_gravity = 9.81f;
	float m_gravityMultiply = 0.01f;

	float m_deAcceleration = .1f;
	float m_fApplyDeAcceleration = .0f;
	float m_fGroundedDeAcceleration = .5f;

	Raycast2D* m_pGroundRay;
	Raycast2D* m_pLeftRay;
	Raycast2D* m_pRightRay;




	std::vector<Raycast2D*> m_rayVec;

	float m_fResolutionMaxY = 0.f;
	float m_fResolutionMaxX = 0.f;

	Collider* m_pCollider;
	Collider* m_pOtherCol;

	Object* m_object;
	Vec2 m_velocity;


public:
	void Init();
	
	void SetGravityMultiply(float _value) { m_gravityMultiply = _value; }
	void SetVelocity(Vec2& const _value) { m_velocity = _value; }
	void AddForce(Vec2&& direction, float power);
	void AddForce(Vec2& direction, float power);

	void MoveInterpolation(const Collider* _pOther);

	const Vec2& GetVelocity() const { return m_velocity; }

	void EnterCollision(Collider* _pOther);
	void ExitCollision(Collider* _pOther);
	void StayCollision(Collider* _pOther);


	
	Rigidbody2D(Object* _object, Collider* _collider);
	~Rigidbody2D();

	void Update();
	void FinalUpdate();
private:
	void ApplyGravity();
	void ApplyVelocity();
	void ApplyDeAccel();
};

