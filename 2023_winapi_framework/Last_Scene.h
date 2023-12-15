#pragma once
#include "MapScene.h"

class Last_Scene : public MapScene
{
public:
    void Init() override;
    bool CanChangeNextScene() override;
    bool CanChangePrevScene() override; 
};
