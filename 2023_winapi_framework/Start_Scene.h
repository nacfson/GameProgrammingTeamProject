#pragma once
#include "Scene.h"
#include "MapScene.h"
class Start_Scene :
    public MapScene
{
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void Release() override;
    virtual bool CanChangeNextScene() override;
    virtual bool CanChangePrevScene() override;
};

