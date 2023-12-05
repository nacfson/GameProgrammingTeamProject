#include "pch.h"
#include "MapMgr.h"
#include "tileson.hpp"

void MapMgr::Init()
{
	tson::Tileson m_tson;

	m_uptrMap = m_tson.parse(fs::path("Map/Start_Scene.json"));

	if(m_uptrMap->getStatus() != tson::ParseStatus::OK)
	{
		std::cout << "json file error" << std::endl;
	}

	CreateJsonBoard();
}

void MapMgr::CreateJsonBoard()
{
	if(m_uptrMap->getStatus() == tson::ParseStatus::OK)
	{
		tson::Layer* tileLayer = m_uptrMap->getLayer("Tile Layer 1");
		tson::Layer* objLayer = m_uptrMap->getLayer("Object Layer 1");
		if(objLayer->getName() == "Ground")
		{
			
		}

		tson::Object* mario = objLayer->firstObj("Ground");
		for(auto &obj : objLayer->getObjects())
		{
			if(obj.getName() == "Ground")
			{
				obj.getPosition();
				//그라운드 세팅
			}
		}

		if(tileLayer->getType() == tson::LayerType::TileLayer)
		{
			for(auto& [pos,tileObject] : tileLayer->getTileObjects())
			{
				tson::Tileset* tileset = tileObject.getTile()->getTileset();
				tson::Rect drawingRect = tileObject.getDrawingRect();
				tson::Vector2f position = tileObject.getPosition();
				tson::Vector2i imageSize = tileset->getImageSize();

				Texture* tex = StoreAndLoadImage(tileset->getImage().generic_string(), {0, 0});

				if(nullptr != tex)
				{
					position.x;
					position.y;
				}
			}
		}
	}
}

Texture* MapMgr::StoreAndLoadImage(const std::string& _image, const Vec2& _pos)
{
	fs::path path = _image;
	if(m_mapTex.count(_image) > 0)
	{
		if (fs::exists(path) && fs::is_regular_file(path))
		{
			std::unique_ptr<Texture> tex = std::make_unique<Texture>();
			//bool imageFound = tex->Load(path.generic_string());


			std::unique_ptr<Texture> spr = std::make_unique<Texture>();
		}
		else
		{
			std::cout << "Can't find" << path.generic_string() << std::endl;
		}
	}


	if(m_mapTex.count(_image) > 0)
	{
		return m_mapTex[_image].get();
	}
	return nullptr;
}
