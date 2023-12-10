#include "pch.h"
#include "TileMgr.h"
#include "tileson.hpp"

void TileMgr::Init()
{

}

std::vector<Tile> TileMgr::GetTileVec(const std::string& _path)
{
	if(m_mapTile.find(_path) != m_mapTile.end())
	{
		return m_mapTile[_path];
	}

	std::vector<Tile> returnTilemap;

	tson::Tileson tson;

	//auto map = tson.parse(fs::path("Map/" + _path));
	auto map = tson.parse(fs::path( _path));

	if(map->getStatus() != tson::ParseStatus::OK)
	{
		std::cout << "not ok";
	}


	for(tson::Layer layer : map->getLayers())
	{
		if(layer.getName() == "Ground")
		{
			Tile tile;
			int size = layer.getTileObjects().size();
			//int a = 3;
			for (auto& [pos, tileObject] : layer.getTileObjects())
			{
				tson::Rect drawingRect = tileObject.getDrawingRect();
				tson::Vector2f position = tileObject.getPosition();
				//tson::Vector2i imageSize = tileset->getImageSize();
				tson::Tileset* tileset = tileObject.getTile()->getTileset();
				
				tson::Tile* d = tileObject.getTile();
				//auto id = d->getId();

				tile.x = position.x;
				tile.y = position.y;

				tile.width =  drawingRect.width;
				tile.height = drawingRect.height;

				tile.bHasCollider = true;
				tile.eImage_type = EIMAGE_TYPE::NORMAL;
				returnTilemap.push_back(tile);
			}
		}
	}

	m_mapTile.insert({ _path,returnTilemap });
	return returnTilemap;
}

