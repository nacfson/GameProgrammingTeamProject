#pragma once
#include "Scene.h"

class First_Scene : public Scene
{
public:
	First_Scene();
	~First_Scene();
	bool CanChangeNextScene() override;
};

