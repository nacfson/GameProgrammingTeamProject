#pragma once
#include "MapScene.h"
class Seventh_Scene : public MapScene
{
public:
    void Init() override;
    bool CanChangeNextScene() override;
    bool CanChangePrevScene() override;
};
