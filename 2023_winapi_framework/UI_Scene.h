#pragma once
#include "Scene.h"

class UI_Scene : public Scene
{
public:
	virtual void Init() override;

	bool CanChangeNextScene() override;
	bool CanChangePrevScene() override;
};


