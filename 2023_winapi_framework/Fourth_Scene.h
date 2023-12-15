#pragma once
#include "MapScene.h"

class Fourth_Scene : public MapScene
{
public:
    void Init() override;
    bool CanChangeNextScene() override;
    bool CanChangePrevScene() override;
};
