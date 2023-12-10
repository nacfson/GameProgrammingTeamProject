#pragma once
#include "Ground.h"
//#include "Object.h"
class Object;
#include "TileMgr.h"
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
	const bool& GetIsInit() const { return m_bIsInit; }
public:
	void AddObject(Object* _pObj, OBJECT_GROUP _eType)
	{
		m_vecObj[(UINT)_eType].push_back(_pObj);
	}
	const wstring GetNextSceneName() const { return m_nextSceneName; }
	const wstring GetPrevSceneName() const { return m_prevSceneName; }

	void CreateMapObjects(const vector<Tile> _tileVec)
	{
		for(const Tile& tile : _tileVec)
		{
			//Vec2 groundScale = Vec2(100, 100);
			Vec2 groundScale = Vec2(tile.width, tile.height);
			Ground* pGround = new Ground(groundScale);
			Vec2 tilePos = Vec2(tile.x, tile.y);

			pGround->SetPos(tilePos);
			pGround->SetObjGroup(OBJECT_GROUP::GROUND);

			AddObject(pGround, OBJECT_GROUP::GROUND);
		}
	}
	
protected:
//	Object*  m_obj;
	Texture* m_pBackgroundTex;
	vector<Object*> m_vecObj[(UINT)OBJECT_GROUP::END];

	wstring m_nextSceneName;
	wstring m_prevSceneName;

	bool m_bIsInit;
};

