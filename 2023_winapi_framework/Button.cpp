#include "pch.h"
#include "Button.h"
#include "Collider.h"
#include "ResMgr.h"
#include "SceneMgr.h"
#include "KeyMgr.h"
#include "SelectGDI.h"
#include "Texture.h"
#include "TimeMgr.h"


Button::Button()
	:m_pTex(nullptr),
	m_fTimer(0.f),
	m_bOnTimer(false),
	m_fTargetTime(0.3f)
{
	Vec2 btnScale = Vec2(100.f, 50.f);

	m_vScale = btnScale;
	m_vCurScale = m_vScale;
	m_vTargetScale = Vec2(120.f, 50.f);

	m_pTex = ResMgr::GetInst()->TexLoad(L"NormalBtn",L"Texture\\StartBtn.bmp");

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
	m_vCurTargetScale = m_vTargetScale;
}



void Button::OnMouseExit()
{
	m_bOnMouse = false;
	m_bOnTimer = true;

	m_fTimer = 0.f;
	m_vCurTargetScale = m_vScale;
}

void Button::OnMouseClicked()
{
	if(m_bOnMouse)
	{
		Callback();
	}
}

void Button::Update()
{
	POINT mousePos = KeyMgr::GetInst()->GetMousePos();

	if (m_vPos.x - m_vScale.x * 0.5f <= mousePos.x &&
		m_vPos.x + m_vScale.x * 0.5f >= mousePos.x &&
		m_vPos.y - m_vScale.y * 0.5f <= mousePos.y &&
		m_vPos.y + m_vScale.y * 0.5f >= mousePos.y)
	{
		if (m_bOnMouse == false)
		{
			OnMouseEnter();
		}
	}
	else
	{
		if(m_bOnMouse)
		{
			OnMouseExit();
		}
	}

	if (m_bOnMouse && KEY_UP(KEY_TYPE::LBUTTON))
	{
		OnMouseClicked();
	}


	if(m_bOnTimer)
	{
		if (m_fTimer <= m_fTargetTime)
		{
			m_fTimer += TimeMgr::GetInst()->GetDT();
			SetScaleByValue(m_vCurScale, m_vCurTargetScale, (float)m_fTimer / m_fTargetTime);
		}
	}
}

void Button::Render(HDC _dc)
{
	//Vec2 textMargin = Vec2(5.f, 5.f);
	//Vec2 vTextSize = Vec2(.05f * m_sText.length(),.5f);
	//Vec2 vTextPos = Vec2(m_vPos.x - vTextSize.x * 0.5f,m_vPos.y + vTextSize.y * 0.5f);

	//TextOut(_dc, vTextPos.x, vTextPos.y, m_sText.c_str(), m_sText.length());

	PEN_TYPE ePen = PEN_TYPE::BLUE;

	if(m_bOnMouse)
	{
		ePen = PEN_TYPE::GREEN;
	}
	else
	{
		ePen = PEN_TYPE::BLUE;
	}

	SelectGDI pen(_dc, ePen);
	SelectGDI brush(_dc, BRUSH_TYPE::BLUE);
	

	//float fWidth = m_pTex->GetWidth();
	//float fHeight = m_pTex->GetHeight();


	//BitBlt(_dc
	//,(int)(m_vPos.x - m_vCurScale.x / 2)
	//,(int)(m_vPos.y - m_vCurScale.y / 2)
	//, fWidth, fHeight, m_pTex->GetDC()
	//,0,0,SRCCOPY);
	RECT_RENDER(m_vPos.x, m_vPos.y, m_vCurScale.x, m_vCurScale.y, _dc);
}


void Button::SetScaleByValue(Vec2 _startScale, Vec2 _targetScale, float _value)
{
	Vec2 applyValue = (_targetScale - _startScale);
	m_vCurScale = _startScale + Vec2(applyValue.x * _value,applyValue.y * _value);
}


