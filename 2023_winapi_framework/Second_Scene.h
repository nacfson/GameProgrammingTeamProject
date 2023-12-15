#pragma once
#include "MapScene.h"

class Second_Scene : public MapScene
{
public:
    Second_Scene();
    ~Second_Scene();
    bool CanChangeNextScene() override;
    bool CanChangePrevScene() override;
    void Init() override;
    
    
};
