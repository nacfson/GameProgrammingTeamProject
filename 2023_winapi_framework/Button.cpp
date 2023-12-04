#include "pch.h"
#include "Button.h"
#include "Collider.h"
#include "ResMgr.h"
#include "SceneMgr.h"
#include "KeyMgr.h"
#include "SelectGDI.h"
#include "TimeMgr.h"


Button::Button()
	:m_pTex(nullptr),
	m_fTimer(0.f),
	m_bOnTimer(false),
	m_fTargetTime(0.3f)
{
	Vec2 btnScale = Vec2(100.f, 50.f);

	Object::SetScale(btnScale);

	m_vScale = btnScale;
	m_vCurScale = m_vScale;
	m_vTargetScale = Vec2(120.f, 50.f);

	//m_pTex = ResMgr::GetInst()->TexLoad(L"NormalBtn",L"Texture\\jiwoo.bmp");
	CreateCollider();
	GetCollider()->SetScale(btnScale);
	GetCollider()->SetOffSetPos(Vec2(0.f, 0.f));
}

Button::~Button()
{
}

void Button::OnMouseEnter()
{
	m_bOnMouse = true;
	m_bOnTimer = true;

	m_fTimer = 0.f;
	m_fTargetTime = CalculateTime(m_vScale, m_vTargetScale);
}

void Button::OnMouseExit()
{
	m_bOnMouse = false;
	m_bOnTimer = false;

	m_fTimer = 0.f;
	m_fTargetTime = CalculateTime(m_vTargetScale, m_vScale);
	//SetScaleByValue(m_vScale, m_vTargetScale, (float)m_fTimer / m_fTargetTime);
}

void Button::OnMouseClicked()
{
	if(m_bOnMouse)
	{
		SceneMgr::GetInst()->LoadScene(m_sceneName);
	}
}

void Button::Update()
{
	if (m_fTimer <= m_fTargetTime)
	{
		m_fTimer += TimeMgr::GetInst()->GetDT();
		SetScaleByValue(m_vScale, m_vTargetScale, (float)m_fTimer / m_fTargetTime);
	}

	POINT mousePos = KeyMgr::GetInst()->GetMousePos();

	if( m_vPos.x - m_vScale.x * 0.5f <= mousePos.x &&
		m_vPos.x + m_vScale.x * 0.5f >= mousePos.x &&
		m_vPos.y - m_vScale.y * 0.5f <= mousePos.y &&
		m_vPos.y + m_vScale.y * 0.5f >= mousePos.y)
	{
		if(m_bOnMouse == false)
		{
			OnMouseEnter();
		}
	}
	else
	{
		OnMouseExit();
	}

	if(m_bOnMouse && KEY_UP(KEY_TYPE::LBUTTON))
	{
		OnMouseClicked();
	}


}

void Button::Render(HDC _dc)
{
	Vec2 textMargin = Vec2(5.f, 5.f);

	TextOut(_dc, m_vPos.x - m_vScale.x * 0.5f + textMargin.x, m_vPos.y, m_sText.c_str(), m_sText.length());

	PEN_TYPE ePen = PEN_TYPE::GREEN;

	if(m_bOnMouse)
	{
		ePen = PEN_TYPE::RED;
	}
	else
	{
		ePen = PEN_TYPE::GREEN;
	}

	SelectGDI pen(_dc, ePen);
	SelectGDI brush(_dc, BRUSH_TYPE::HOLLOW);

	RECT_RENDER(m_vPos.x, m_vPos.y, m_vCurScale.x, m_vCurScale.y, _dc);
}


void Button::SetScaleByValue(Vec2 _startScale, Vec2 _targetScale, float _value)
{
	Vec2 applyValue = (_targetScale - _startScale);
	m_vCurScale = _startScale + Vec2(applyValue.x * _value,applyValue.y * _value);
}

float Button::CalculateTime(Vec2 _startScale, Vec2 _targetScale)
{
	return (_targetScale.x - m_vCurScale.x) / m_vCurScale.x;
}


