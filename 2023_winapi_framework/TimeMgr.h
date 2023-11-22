#pragma once
class TimeMgr
{
	SINGLE(TimeMgr);
public:
	void Init();
	void Update();
public:
	const float& GetDT() const { return m_dT; }
private:
	// DT(1�����Ӵ� �ð�: Delta time)
	LARGE_INTEGER m_llPrevCount; // �����ð�
	LARGE_INTEGER m_llCurCount; // ����ð�
	LARGE_INTEGER m_llFrequency; // ���ļ�
	float m_dT; // �����Ӱ��� �ð� ��

	// FPS
	UINT  m_fps; // FPS
	UINT  m_frameCount; // ������ ȣ�� üũ
	float m_accFrameTime; // �ð� ����

};

