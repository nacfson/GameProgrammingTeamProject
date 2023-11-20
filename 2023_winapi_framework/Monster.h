#pragma once
#include "Object.h"
class Monster : public Object
{
public:
	Monster();
	~Monster();
public:
	void Update() override;
	virtual void EnterCollision(Collider* _pOther) override;
	virtual void ExitCollision(Collider* _pOther)  override;
	virtual void StayCollision(Collider* _pOther)  override;

public:
	void SetSpeed(float _f) { m_fSpeed = _f; }
	void SetCenterPos(Vec2 _vPos) { m_vCenterPos = _vPos; }
	void SetMoveDis(float _f) { m_fMaxDis = _f; }
	const float& GetSpeed() const { return m_fSpeed; }
private:
	float m_fSpeed; // ���� ���ǵ�
	Vec2 m_vCenterPos; // �߽� ��ġ
	float m_fMaxDis; // �̵��� �� �ִ� �ִ� �Ÿ�
	float m_fDir; // ����(-1: ����, 1: ������)
	int   m_iHp; // ü��
};

