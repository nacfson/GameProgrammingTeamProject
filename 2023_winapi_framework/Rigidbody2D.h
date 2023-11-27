#pragma once

class Object;
class Collider;

class Rigidbody2D
{
private :
	float m_gravity = 9.81f;
	float m_gravityMultiply = 0.01f;

	float m_deAcceleration = .1f;

	float m_fResolutionMaxY = 0.f;
	float m_fResolutionMaxX = 0.f;

	Collider* m_collider;
	Object* m_object;
	Vec2 m_velocity;


public:
	void Init();
	
	void SetGravityMultiply(float _value) { m_gravityMultiply = _value; }
	void SetVelocity(Vec2& const _value) { m_velocity = _value; }
	void AddForce(Vec2&& direction, float power);
	void AddForce(Vec2& direction, float power);

	const Vec2& GetVelocity() const { return m_velocity; }

	Rigidbody2D(Object* _object, Collider* _collider);
	~Rigidbody2D();

	void Update();
private:
	void ApplyGravity();
	void ApplyVelocity();
	void ApplyDeAccel();
};

