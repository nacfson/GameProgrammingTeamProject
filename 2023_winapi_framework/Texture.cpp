#include "pch.h"
#include "Texture.h"
#include "Core.h"
#include<assert.h>
Texture::Texture()
	: m_hBit(0)
	, m_hDC(0)
	, m_bitInfo{}
{
}

Texture::~Texture()
{
	DeleteDC(m_hDC);
	DeleteObject(m_hBit);
}

void Texture::Load(const wstring& _strFilePath)
{
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP
		, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	

	assert(m_hBit);
	m_hDC = CreateCompatibleDC(Core::GetInst()->GetMainDC());
	SelectObject(m_hDC, m_hBit);
	GetObject(m_hBit, sizeof(BITMAP),&m_bitInfo);
}

void Texture::Load(const wstring& _strFilePath, int _iStartX, int _iStartY, int _iWidth, int _iHeight)
{
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP
	, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	assert(m_hBit);
	m_hDC = CreateCompatibleDC(Core::GetInst()->GetMainDC());

	HDC     tempDC = CreateCompatibleDC(Core::GetInst()->GetMainDC());
	
	BitBlt(tempDC
		,(int)(_iStartX)
		,(int)(_iStartY)
		, _iWidth,_iHeight, m_hDC
		,0,0,SRCCOPY);

	SelectObject(tempDC, m_hBit);
	GetObject(m_hBit,sizeof(BITMAP),&m_bitInfo);
}