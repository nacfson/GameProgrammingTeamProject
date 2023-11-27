#pragma once
//#include "Object.h"
class Object;
class Scene
{
public:
	Scene();
	virtual ~Scene();
	// Init(), Update(), Render(), Release();
	virtual void Init();

	virtual void Update();
	virtual void FinalUpdate();
	virtual void Render(HDC _dc);
	virtual void Release();

	virtual bool CanChangeNextScene() abstract;
	virtual bool CanChangePrevScene() abstract;

protected:
	void SetNextScene(wstring _nextSceneName, wstring _prevSceneName = L"");
public:
	const vector<Object*>& GetGroupObject(OBJECT_GROUP _etype) const
	{
		return m_vecObj[(UINT)_etype];
	}
public:
	void AddObject(Object* _pObj, OBJECT_GROUP _eType)
	{
		m_vecObj[(UINT)_eType].push_back(_pObj);
	}
	const wstring GetNextSceneName() const { return m_nextSceneName; }
	const wstring GetPrevSceneName() const { return m_prevSceneName; }
	
protected:
//	Object*  m_obj;
	vector<Object*> m_vecObj[(UINT)OBJECT_GROUP::END];

	wstring m_nextSceneName;
	wstring m_prevSceneName;
};

