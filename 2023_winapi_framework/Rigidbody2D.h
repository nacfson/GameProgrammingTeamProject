#pragma once

class Object;
class Collider;

class Rigidbody2D
{
private :
	float m_gravity = 9.81f;
	float m_gravityMultiply = 5.0f;

	Collider* m_collider;
	Object* m_object;
public:
	void SetGravityMultiply(float value) { m_gravityMultiply = value; }
	Rigidbody2D(Object* _object, Collider* _collider);
	~Rigidbody2D();
	void Update();
private :
	void ApplyGravity();
};

