#pragma once
class Collider;
class Animator;
class Object
{
public:
	Object();
	Object(OBJECT_GROUP _eGroup);
	virtual ~Object();
//public:	// ũ��, ��ġ
	//POINT m_ptPos;
	//POINT m_ptScale;
public:
	virtual void Update();
	virtual void FinalUpdate() ; //remove final keyword
	virtual void Render(HDC _dc);

	virtual void EnterCollision(Collider* _pOther);
	virtual void ExitCollision(Collider* _pOther);
	virtual void StayCollision(Collider* _pOther);
	void Component_Render(HDC _dc);
	void SetObjGroup(const OBJECT_GROUP _eGroup) { m_eGroup = _eGroup; }

public:
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }
	const Vec2& GetPos() const { return m_vPos; }
	const Vec2& GetScale() const { return m_vScale; }
	const OBJECT_GROUP& GetObjectGroup() const { return m_eGroup; }

	Collider* GetCollider() const 
	{ return m_pCollider; }
	Animator* GetAnimator()
	{
		return m_pAnimator;
	}
	const wstring& GetName() const { return m_strName; }
	void SetName(wstring _name) { m_strName = _name; }
	bool GetIsDead() const { return !m_IsAlive; }
private:
	void SetDead() { m_IsAlive = false; }
	friend class EventMgr;
public:
	void CreateCollider();
	void CreateAnimator();
protected:
	Vec2 m_vPos; // ��ġ
	Vec2 m_vScale; // ũ��
	Collider* m_pCollider;
	wstring m_strName; // �̸�.
	bool m_IsAlive;
	Animator* m_pAnimator;
	OBJECT_GROUP m_eGroup;
};

