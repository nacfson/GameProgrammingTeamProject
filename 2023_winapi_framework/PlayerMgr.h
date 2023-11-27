#pragma once
#include "Player.h"

class PlayerMgr
{
	SINGLE(PlayerMgr);

public:
	const Player* GetPlayer() const { return m_pPlayer; }

	void Init();
	void Update();
	void Release();

	void Render(HDC _dc);
	void LoadPlayer(Player* const player)
	{
		m_pPlayer = player;
		IsChanged = true;
	}
	bool IsChanged = false;
private:
	Player* m_pPlayer;
};

