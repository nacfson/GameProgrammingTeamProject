#pragma once
class Object;
class Player;
struct tEvent
{
	EVENT_TYPE eEve; // �̺�Ʈ Ÿ��
	Object* Obj;
	OBJECT_GROUP ObjType;
};
struct tPlayerEvent
{
	EVENT_TYPE eEve; // �̺�Ʈ Ÿ��
	Player* Obj;
};
class EventMgr
{
	SINGLE(EventMgr);
public:
	void Update();
	void DeleteObject(Object* _pObj);
	void AddPlayer(Player* player);
private:
	void Excute(const tEvent& _eve);
private:
	vector<tEvent> m_vecEvent;
	vector<Object*> m_vecDead;
};

