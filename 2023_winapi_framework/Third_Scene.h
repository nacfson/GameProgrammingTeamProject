#pragma once
#include "MapScene.h"
class Third_Scene : public MapScene
{
public:
    void Init() override;
    bool CanChangeNextScene() override;
    bool CanChangePrevScene() override;
};
