#include "pch.h"
#include "Slider.h"
#include "Core.h"
#include "SelectGDI.h"

Slider::Slider()
{
}

Slider::~Slider()
{
}

void Slider::SetSlider(float value)
{
	m_fCurValue = value;
}

void Slider::ActiveSlider(bool value)
{
}

void Slider::Render(HDC _dc)
{
	//Object::Render(_dc);
	HPEN hPen = (HPEN)BRUSH_TYPE::GREEN;
	PEN_TYPE ePen = PEN_TYPE::GREEN;

	SelectGDI pen(_dc, ePen);
	SelectGDI brush(_dc, BRUSH_TYPE::GREEN);

	RECT_RENDER(m_vPos.x, m_vPos.y, m_vScale.x * GetCurrentPercent(), m_vScale.y, _dc);
	//RECT_RENDER(m_vPos.x, m_vPos.y, m_vScale.x, m_vScale.y, _dc);

}
