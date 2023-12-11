#pragma once
#include "Res.h"
class Texture :
    public Res
{
public:
    Texture();
    ~Texture();
    friend class ResMgr;
public:
    void Load(const wstring& _strFilePath);
    void Load(const wstring& _strFilePath,int _iStartX,int _iStartY,int _iWidth, int _iHeight);
    const LONG& GetWidth() const { return (m_bitInfo.bmWidth); }
    const LONG& GetHeight() const { return (m_bitInfo.bmHeight); }
    const HDC& GetDC() const { return m_hDC; }
    const HDC& GetBackDC() const { return m_hBackDC; }
private:
    HBITMAP m_hBit;
    HBITMAP m_hBackBit;
    HDC     m_hDC;
    HDC m_hBackDC;

    BITMAP  m_bitInfo;
};

