#pragma once
#include "Object.h"
class Texture;
class Button : public Object
{
public:
	Button();
	~Button();

	void OnMouseEnter();
	void OnMouseExit();
	void OnMouseClicked();

	void SetSceneName(wstring _sceneName) { m_sceneName = _sceneName; };
	void SetText(wstring _text) { m_sText = _text; }

	void Update() override;
	void Render(HDC _dc) override;

protected:
	void SetScaleByValue(Vec2 _startScale, Vec2 _targetScale, float _value);
	float CalculateTime(Vec2 _startScale, Vec2 _targetScale);

private:
	Texture* m_pTex;
	bool m_bOnMouse;
	bool m_isClicked;

	wstring m_sceneName;

	bool m_bOnTimer;
	bool m_bIsChanging;
	float m_fTimer;
	float m_fTargetTime;

	Vec2 m_vScale;
	Vec2 m_vCurScale;
	Vec2 m_vTargetScale;

	wstring m_sText;
};

