#pragma once
#include "Scene.h"
class Game_Scene :
    public Scene
{
public :
	Game_Scene();
	~Game_Scene();

	virtual void Init() override;
	bool CanChangeNextScene() override;
	bool CanChangePrevScene() override;
};

