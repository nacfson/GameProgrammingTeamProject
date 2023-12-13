#pragma once
#include "Object.h"
#include <functional>
class Text;
class Texture;
class Button : public Object
{
public:
	Button();
	~Button();

	void OnMouseEnter();
	void OnMouseExit();
	void OnMouseClicked();

	void SetScale(const Vec2& _scale,float _xExpandValue = 1.2f);
	void SetText(const wstring& _text,const Vec2& _pos);
	void SetTexture(Texture* _tex) { m_pTex = _tex;}
	
	void SetBtnAction(std::function<void()> Callback)
	{
		this->Callback = Callback;
	}

	void Update() override;
	void Render(HDC _dc) override;

protected:
	void SetScaleByValue(Vec2 _startScale, Vec2 _targetScale, float _value);

private:
	Texture* m_pTex;
	bool m_bOnMouse;
	bool m_isClicked;


	bool m_bOnTimer;
	float m_fTimer;
	float m_fTargetTime;

	Vec2 m_vScale;
	Vec2 m_vTargetScale;
	Vec2 m_vCurScale;
	Vec2 m_vCurTargetScale;

	std::function<void()> Callback;
	
	Text* m_text;

};

