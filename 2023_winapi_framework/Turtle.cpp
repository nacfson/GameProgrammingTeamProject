#include "pch.h"
#include "Turtle.h"
#include "TimeMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Texture.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
Turtle::Turtle() : m_pTex(nullptr), moveSpeed(10.0f)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Turtle", L"Texture\\Turtle.bmp");
	CreateCollider();
	GetCollider()->SetScale(Vec2(64.f, 64.f));
    
	CreateAnimator();
	GetAnimator()->CreateAnim(L"TurtleMove", m_pTex, Vec2(64.f, 64.f),
		Vec2(64.f, 64.f), Vec2(64.f, 0.f), 3, 0.3f);
	

	for (int i = 0; i < 3; i++) {
		GetAnimator()->FindAnim(L"TurtleMove")->Create(m_pTex, Vec2(64.f, 64.f),
			Vec2(64.f, 64.f), Vec2(64.f, 0.f), 3, 0.3f);
	}
	GetAnimator()->FindAnim(L"TurtleMove")->Create(m_pTex, Vec2(0.f, 0.f),
		Vec2(64.f, 64.f), Vec2(64.f, 0.f), 4, 0.2f);
	GetAnimator()->FindAnim(L"TurtleMove")->Create(m_pTex, Vec2(0.f, 64.f),
		Vec2(64.f, 64.f), Vec2(64.f, 0.f), 1, 0.2f);
	GetAnimator()->FindAnim(L"TurtleMove")->Create(m_pTex, Vec2(192.f, 0.f),
		Vec2(64.f, 64.f), Vec2(-64.f, 0.f), 3, 0.2f);

	GetAnimator()->PlayAnim(L"TurtleMove", true);
}

Turtle::~Turtle()
{

}

void Turtle::Update()
{
	Vec2 nextPos = GetPos();
	nextPos.y += moveSpeed * fDT * -1.0f;
	SetPos(nextPos);
	GetAnimator()->Update();
}

void Turtle::Render(HDC _dc)
{
	Component_Render(_dc);
}
