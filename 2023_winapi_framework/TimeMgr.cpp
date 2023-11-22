#include "pch.h"
#include "TimeMgr.h"
#include "Core.h"
//#include <chrono> // ns
void TimeMgr::Init()
{
	m_llPrevCount = {};
	m_llCurCount = {};
	m_llFrequency = {};	
	m_frameCount = 0;
	m_fps = 0;
	m_accFrameTime = 0.f;
	// ���� ī��Ʈ�� ƽ�� �����´�.(�����ð�)
	// 1�� 2�� �̷� �ʰ� �ƴϾ�. Frequency�� �˾ƾ���.
	QueryPerformanceCounter(&m_llPrevCount);

	// �ʴ� ī��Ʈ Ƚ���� ��ȯ�մϴ�.
	// ���� Ÿ�̸Ӱ� �����ϴ� ���ļ��� ��ȯ�մϴ�. 
	// <-> �ֱ�: �ѹ� �����ϴµ� �ɸ��� �ð�
	QueryPerformanceFrequency(&m_llFrequency);
}

void TimeMgr::Update()
{
	QueryPerformanceCounter(&m_llCurCount);

	// Delta Time: �� �����ӿ� �ɸ� �ð�.
	m_dT = (float)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (float)m_llFrequency.QuadPart;

	// FPS: Frame Per Second
	m_llPrevCount = m_llCurCount;
	//	1. / m_dT;
	m_frameCount++; // ������ ȣ�� ����
	m_accFrameTime += m_dT; // �ð� ����
	if (m_accFrameTime >= 1.f) // 1��
	{
		m_fps = (UINT)(m_frameCount / m_accFrameTime);
		m_accFrameTime = 0.f;
		m_frameCount = 0;
		static wchar_t titlebuf[50] = {};		
		swprintf_s(titlebuf, L"FPS: %d, DT: %f", m_fps, m_dT);
		//wsprintf();
		SetWindowText(Core::GetInst()->GetHwnd(), titlebuf);
	}


}
