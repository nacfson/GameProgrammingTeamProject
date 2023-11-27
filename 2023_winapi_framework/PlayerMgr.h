#pragma once
#include "Player.h"

class PlayerMgr
{
	SINGLE(PlayerMgr);

public:
	const Player GetPlayer() const { return m_player; }
	void Init();
	void LoadPlayer(Player& const player)
	{
		m_player = player;
		IsChanged = true;
	}
	bool IsChanged = false;
private:
	Player m_player;
};

