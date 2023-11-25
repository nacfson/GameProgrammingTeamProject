#pragma once
#include "Object.h"

class Slider : public Object
{
public:
	Slider();

	~Slider();

	void SetSlider(float value);

	void SetValues(float _minValue, float _maxValue)
	{
		m_fMinValue = _minValue;
		m_fMaxValue = _maxValue;
	}
	void ActiveSlider(bool value);

	void Render(HDC _dc) override;

	//can assert divide zero
	const float& GetCurrentPercent() const { return  m_fCurValue / m_fMaxValue; }
	
private:
	float m_fMaxValue;
	float m_fMinValue;

	float m_fCurValue;
};

