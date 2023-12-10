#pragma once
class Collider;
class Raycast2D
{

public:
	Raycast2D();
	Raycast2D(OBJECT_GROUP _eObjectGroup);
	~Raycast2D();

	Collider* ShootRay(Vec2 _pos,Vec2 _scale,Vec2 _dir,float _distance);
private:
 	Vec2 m_vDir;
	float m_fDistance;
	OBJECT_GROUP m_eTargetGroup;

};

