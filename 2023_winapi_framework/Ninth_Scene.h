#pragma once
#include "Eighth_Scene.h"
class Ninth_Scene : public MapScene
{
public:
    void Init() override;
    bool CanChangeNextScene() override;
    bool CanChangePrevScene() override;
};
