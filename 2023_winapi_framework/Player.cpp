#include "pch.h"
#include "Player.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Bullet.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Texture.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
#include "Slider.h"
#include "Rigidbody2D.h"

Player::Player()
	: m_pTex(nullptr),
	m_pTexL(nullptr),
	m_pTexR(nullptr),
	m_fPlusJumpPower(.4f),
	m_fCurJumpPower(0.f),
	m_fMinJumpPower(0.f),
	m_fMaxJumpPower(1.1f),
	m_curDir(DIRECTION_TYPE::LEFT)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Player", L"Texture\\jiwoo.bmp");
	m_pTexL = ResMgr::GetInst()->TexLoad(L"PlayerL", L"Texture\\rabbitL.bmp");
	m_pTexR = ResMgr::GetInst()->TexLoad(L"PlayerR", L"Texture\\rabbitR.bmp");
	CreateCollider();

	GetCollider()->SetScale(Vec2(20.f,30.f));
	GetCollider()->SetOffSetPos(Vec2(0.f,0.f));

	ResMgr::GetInst()->LoadSound(L"Jump",L"Jump.wav",false);
	ResMgr::GetInst()->LoadSound(L"BGM",L"BGM.wav",true);
	
	CreateAnimator();
	
	GetAnimator()->CreateAnim(L"RabbitL", m_pTexL, Vec2(32.f, 0.f),
		Vec2(32.f, 32.f), Vec2(32.f, 0.f), 2, 0.2f);
	GetAnimator()->CreateAnim(L"RabbitR", m_pTexR, Vec2(0.f, 0.f),
		Vec2(32.f, 32.f), Vec2(32.f, 0.f), 2, 0.2f);
	GetAnimator()->CreateAnim(L"RabbitL_Jump", m_pTexL, Vec2(0.f, 0.f),
		Vec2(32.f, 32.f), Vec2(32.f, 0.f), 1, 0.2f);
	GetAnimator()->CreateAnim(L"RabbitR_Jump", m_pTexR, Vec2(64.f, 0.f),
		Vec2(32.f, 32.f), Vec2(32.f, 0.f), 1, 0.2f);
	GetAnimator()->PlayAnim(L"RabbitL", true);
	//GetAnimator()->CreateAnim(L"Jiwoo_Front", m_pTex,Vec2(0.f, 150.f),
	//	Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
	//GetAnimator()->CreateAnim(L"Jiwoo_Back", m_pTex, Vec2(0.f, 100.f),
	//	Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
	//GetAnimator()->CreateAnim(L"Jiwoo_Left", m_pTex, Vec2(0.f, 0.f),
	//	Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
	//GetAnimator()->CreateAnim(L"Jiwoo_Right", m_pTex, Vec2(0.f, 50.f),
	//	Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
	//GetAnimator()->CreateAnim(L"Jiwoo_Attack", m_pTex, Vec2(0.f, 200.f),
	//	Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
	//GetAnimator()->PlayAnim(L"Jiwoo_Front",true);

	m_pRigidbody2D = new Rigidbody2D(this, GetCollider());
	m_pRigidbody2D->SetGravityMultiply(0.1f);
	m_pRigidbody2D->Init();

	m_eGroup = OBJECT_GROUP::PLAYER;

	ResMgr::GetInst()->Play(L"BGM");

}

Player::Player(Player& player)
{
}

Player::~Player()
{
	delete m_pSlider;
	delete m_pRigidbody2D;
	//if (nullptr != m_pTex)
	//	delete m_pTex;
}

void Player::Init()
{
	m_pRigidbody2D->Init();
	m_pCollider->Init();
	m_pSlider = nullptr;
	m_bCanMove = true;
}

void Player::Update()
{
	if(m_bCanMove)
	{
		KEY_TYPE prevPressKey = KeyMgr::GetInst()->GetPrevKey();
		if (prevPressKey == KEY_TYPE::LEFT || prevPressKey == KEY_TYPE::RIGHT)
		{
			m_prevPressMoveKey = prevPressKey;
		}
	}
	
	Vec2 vPos = GetPos();


	if(KEY_UP(KEY_TYPE::T))
	{
		vPos.y = -10.f;
	}


	if (true == m_pRigidbody2D->IsGrounded())
	{
		if(m_bCanMove)
		{
			if (KEY_PRESS(KEY_TYPE::LEFT))
			{
				vPos.x -= 100.f * fDT;
				//GetAnimator()->PlayAnim(L"Jiwoo_Left", true);
				GetAnimator()->PlayAnim(L"RabbitL", true);
				m_curDir = DIRECTION_TYPE::LEFT;
			}
			if (KEY_PRESS(KEY_TYPE::RIGHT))
			{
				vPos.x += 100.f * fDT;
				//GetAnimator()->PlayAnim(L"Jiwoo_Right", true);
				GetAnimator()->PlayAnim(L"RabbitR", true);
				m_curDir = DIRECTION_TYPE::RIGHT;
			}
		}

		if (KEY_PRESS(KEY_TYPE::SPACE))
		{
			m_bCanMove = false;

			if (m_fCurJumpPower <= m_fMaxJumpPower)
			{
				m_fCurJumpPower += m_fPlusJumpPower * TimeMgr::GetInst()->GetDT();

				m_pSlider->SetSlider(m_fCurJumpPower / m_fMaxJumpPower);
			}
			//ResMgr::GetInst()->Play(L"Charge");
			//ResMgr::GetInst()->Play(L"Shoot");
		}
		if (KEY_UP(KEY_TYPE::SPACE))
		{
			if (m_fCurJumpPower >= m_fMinJumpPower)
			{
				Vec2 jumpDirection = Vec2(.5f,-1.0f);
				switch(m_prevPressMoveKey)
				{
				case KEY_TYPE::LEFT:
					jumpDirection = Vec2(-.5f, -1.0f).Normalize();
					GetAnimator()->PlayAnim(L"RabbitL_Jump", true);
					m_curDir = DIRECTION_TYPE::LEFT;
					break;
				case KEY_TYPE::RIGHT:
					jumpDirection = Vec2(.5f, -1.0f).Normalize();
					GetAnimator()->PlayAnim(L"RabbitR_Jump", true);
					m_curDir = DIRECTION_TYPE::RIGHT;
					break;
				}
				m_pRigidbody2D->AddForce(jumpDirection, m_fCurJumpPower);
				ResMgr::GetInst()->Play(L"Jump");
				
			}
			//ResMgr::GetInst()->P(L"Charge");
			m_fCurJumpPower = 0.f;
			m_pSlider->SetSlider(0.f);
			m_bCanMove = true;

		}
	}

	const Vec2 offset = Vec2(0.f, -40.f);

	m_pSlider->SetPos(vPos + offset);
	m_pSlider->SetScale(Vec2(50.f, 10.f));

	//if(KEY_PRESS(KEY_TYPE::CTRL))
	//	GetAnimator()->PlayAnim(L"Jiwoo_Attack", false, 1);

	SetPos(vPos);
	GetAnimator()->Update();
	m_pRigidbody2D->Update();
}




void Player::Render(HDC _dc)
{
	//Vec2 vPos = GetPos();
	//Vec2 vScale = GetScale();
	//int Width = m_pTex->GetWidth();
	//int Height = m_pTex->GetHeight();                
	//// 1. �⺻ �ű��
	//BitBlt(_dc
	//	,(int)(vPos.x - vScale.x /2)
	//	,(int)(vPos.y - vScale.y /2)
	//	, Width,Height, m_pTex->GetDC()
	//	,0,0,SRCCOPY);

	//// 2. ���� �Ⱦ��
	//TransparentBlt(_dc
	//	, (int)(vPos.x - vScale.x / 2)
	//	, (int)(vPos.y - vScale.y / 2)
	//	, Width, Height, m_pTex->GetDC()
	//	, 0, 0, Width,Height, RGB(255,0,255));

	//// 3. Ȯ�� �� ���
	//StretchBlt(_dc
	//	, (int)(vPos.x - vScale.x / 2)
	//	, (int)(vPos.y - vScale.y / 2)
	//	, Width ,Height, m_pTex->GetDC()
	//	, 0, 0, Width, Height, SRCCOPY);

	// 4. ȸ��
	// �ﰢ�Լ�, ȸ�����
	//Plgblt(_dc
	//	, (int)(vPos.x - vScale.x / 2)
	//	, (int)(vPos.y - vScale.y / 2)
	//	, Width, Height, m_pTex->GetDC()
	//	, 0, 0, Width, Height, RGB(255, 0, 255));
	Component_Render(_dc);
}

void Player::FinalUpdate()
{
	Object::FinalUpdate();
	if(m_pRigidbody2D)
		m_pRigidbody2D->FinalUpdate();
}

void Player::EnterCollision(Collider* _pOther)
{
	Object::EnterCollision(_pOther);
	m_pRigidbody2D->EnterCollision(_pOther);
	if (m_curDir == DIRECTION_TYPE::LEFT)
	{
		GetAnimator()->PlayAnim(L"RabbitL", true);
	}
	else
	{
		GetAnimator()->PlayAnim(L"RabbitR", true);
	}
}

void Player::ExitCollision(Collider* _pOther)
{
	Object::ExitCollision(_pOther);
	m_pRigidbody2D->ExitCollision(_pOther);
	if (m_curDir == DIRECTION_TYPE::LEFT)
	{
		GetAnimator()->PlayAnim(L"RabbitL_Jump", true);
	}
	else
	{
		GetAnimator()->PlayAnim(L"RabbitR_Jump", true);
	}
}

void Player::StayCollision(Collider* _pOther)
{
	Object::StayCollision(_pOther);
	m_pRigidbody2D->StayCollision(_pOther);
}

void Player::SetPower(Vec2 dir, float power)
{
	m_pRigidbody2D->AddForce(dir, power);
}

void Player::GetHit()
{
	float jumpDir = .5f;
	if (m_curDir == DIRECTION_TYPE::LEFT)
		jumpDir *= -1;
	
	m_pRigidbody2D->AddForce(Vec2(jumpDir, -1.0f), 0.2f);
}

