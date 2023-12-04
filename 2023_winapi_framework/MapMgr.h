#pragma once
#include "tileson.hpp"
#include "Texture.h"
class MapMgr
{
public:
	void Init();
	void CreateJsonBoard();
	Texture* StoreAndLoadImage(const std::string& _image,const Vec2& _pos);

	SINGLE(MapMgr);
private:
	std::unique_ptr<tson::Map> m_uptrMap;
	std::map<std::string, std::unique_ptr<Texture>> m_mapTex;
	//std::map<std::string, std::unique_ptr<Texture>> m_mapTex;
}

;

