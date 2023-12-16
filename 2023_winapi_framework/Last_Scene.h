#pragma once
#include "MapScene.h"

class Last_Scene : public Scene
{
public:
    void Init() override;
    bool CanChangeNextScene() override;
    bool CanChangePrevScene() override;
    void Update() override;
};
