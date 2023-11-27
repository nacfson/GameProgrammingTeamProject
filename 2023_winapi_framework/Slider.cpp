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
	if(value <= m_fMaxValue)
	{
		m_fCurValue = value;
	}
}

void Slider::ActiveSlider(bool value)
{
}

void Slider::Render(HDC _dc)
{
	if (GetCurrentPercent() == 0) return;

	HPEN hPen = (HPEN)BRUSH_TYPE::GREEN;
	PEN_TYPE ePen = PEN_TYPE::GREEN;

	SelectGDI pen(_dc, ePen);
	SelectGDI brush(_dc, BRUSH_TYPE::GREEN);


	int left = static_cast<int>((m_vPos.x - m_vScale.x / 2));
	int top = static_cast<int>((m_vPos.y - m_vScale.y / 2));
	int right = static_cast<int>((left + (m_vScale.x * GetCurrentPercent())));
	//int right = static_cast<int>((m_vPos.x + m_vScale.x / 2));
	int bottom = static_cast<int>((m_vPos.y + m_vScale.y / 2));

	Rectangle(_dc, left, top, right, bottom);
	//RECT_RENDER(m_vPos.x, m_vPos.y, m_vScale.x * GetCurrentPercent(), m_vScale.y, _dc);
}

