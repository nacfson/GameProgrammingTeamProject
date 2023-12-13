#include "pch.h"
#include "Text.h"

#include "Core.h"
#include "SelectGDI.h"

void Text::SetText(const wstring& _text, const Vec2& _pos)
{
    m_text = _text;
    m_vStartPos = _pos;
}

Text::Text()
    :m_text(L"None"),
    m_vStartPos(Vec2(0.f,0.f))
{
}

Text::~Text()
{
    
}

void Text::Render(HDC _dc)
{

    
    const Vec2 pos = m_vStartPos;
    SetBkMode(_dc, TRANSPARENT);
    SetTextColor(_dc, RGB(255,255,255));
    TextOut(_dc,pos.x,pos.y,m_text.c_str(),m_text.length());
}

