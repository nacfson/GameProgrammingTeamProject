#include "pch.h"
#include "KeyMgr.h"
#include "Core.h"
void KeyMgr::Init()
{
	for (int i = 0; i < (int)KEY_TYPE::LAST; ++i)
	{
		m_vecKey.push_back(tKeyInfo{KEY_STATE::NONE, false});
	}
	m_ptMouse = {};
}

void KeyMgr::Update()
{
	HWND hWnd = GetFocus();
//	HWND hMainHwnd = Core::GetInst()->GetHwnd();
	if (hWnd != nullptr)
	{
		for (int i = 0; i < (int)KEY_TYPE::LAST; ++i)
		{
			// Ű�� ���ȴ�.
			if (GetAsyncKeyState(m_arrVKKey[i]))
			{
				// ������ ���Ⱦ�
				if (m_vecKey[i].IsPrevCheck)
				{
					m_vecKey[i].eState = KEY_STATE::PRESS;
				}
				else // ������ �ȴ��Ⱦ�. ���� ��!!! ����
				{
					m_vecKey[i].eState = KEY_STATE::DOWN;
					m_prevPressKey = static_cast<KEY_TYPE>(i);
				}
				m_vecKey[i].IsPrevCheck = true;
			}
			// Ű�� �ȴ��ȴ�.
			else
			{
				// ������ �����־���.
				if (m_vecKey[i].IsPrevCheck)
				{
					m_vecKey[i].eState = KEY_STATE::UP;
				}
				else
				{
					m_vecKey[i].eState = KEY_STATE::NONE;
				}
				m_vecKey[i].IsPrevCheck = false;
			}
		}
		// Mouse
		GetCursorPos(&m_ptMouse); // ���콺 Ŀ�� ��ǥ �ޱ�
		// �츮�� ���� ������ â �������� ��ǥ ����
		ScreenToClient(Core::GetInst()->GetHwnd(), &m_ptMouse);
	}

	// ��Ŀ�� ���� alt + tap
	else
	{
		for (int i = 0; i < (int)KEY_TYPE::LAST; ++i)
		{
			m_vecKey[i].IsPrevCheck = false;
			if (m_vecKey[i].eState == KEY_STATE::PRESS ||
				m_vecKey[i].eState == KEY_STATE::DOWN)
				m_vecKey[i].eState = KEY_STATE::UP;

			if (m_vecKey[i].eState == KEY_STATE::UP)
				m_vecKey[i].eState = KEY_STATE::NONE;
		}
	}
	

}
