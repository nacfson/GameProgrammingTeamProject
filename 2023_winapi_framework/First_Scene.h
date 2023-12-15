#pragma once
#include "Scene.h"
#include "MapScene.h"

class First_Scene : public MapScene
{
public:
	First_Scene();
	~First_Scene();
	bool CanChangeNextScene() override;
	bool CanChangePrevScene() override;
	void Init() override;
};

