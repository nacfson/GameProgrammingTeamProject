#include "pch.h"
#include "MapScene.h"
#include "Text.h"

void MapScene::SetMapIdx(int _idx)
{
    m_text = new Text;
    m_iMapIdx = _idx;
    m_text->SetText(L"STAGE " + std::to_wstring(_idx),s_vTextPos);
}

void MapScene::Render(HDC _dc)
{
    Scene::Render(_dc);
    m_text->Render(_dc);
}
