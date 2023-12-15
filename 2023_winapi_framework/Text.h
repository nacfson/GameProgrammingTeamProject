#pragma once
#include "Object.h"

class Text
{
public:
    Text();
    ~Text();
    void Render(HDC _dc);
    void SetText(const wstring& _text, const Vec2& _pos);
private:
    Vec2 m_vStartPos;
    wstring m_text;
};

