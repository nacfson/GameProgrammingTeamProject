#include "pch.h"
#include "TileMgr.h"

#include "PathMgr.h"
#include "tileson.hpp"
#include "ResMgr.h"
#include "WinUser.h"
#include "Texture.h"
#define TILECNT 60
void TileMgr::Init()
{
	LoadTilesetTex();
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


	int size=   map->getLayers().size();
	for(tson::Layer layer : map->getLayers())
	{
		Tile tile;
		int size = layer.getTileObjects().size();
		//int a = 3;
		for (auto& [pos, tileObject] : layer.getTileObjects())
		{
			tson::Rect drawingRect = tileObject.getDrawingRect();
			tson::Vector2f position = tileObject.getPosition();
			tson::Tileset* tileset = tileObject.getTile()->getTileset();

			tson::Tile* d = tileObject.getTile();
			int id = d->getGid() - tileset->getFirstgid();

			tile.x = position.x;
			tile.y = position.y;

			int cnt = tileset->getTileCount();

			m_iHeightCnt = sqrt(cnt);
			m_iWidthCnt = sqrt(cnt);

			m_fWidth = drawingRect.width;
			m_fHeight = drawingRect.height;

			tile.width = drawingRect.width;
			tile.height = drawingRect.height;

			tile.bHasCollider = true;

			std::string layerName = layer.getName();
			layerName.replace(layerName.find("Ground"), 6, "");
			tile.id = std::stoi(layerName);
			returnTilemap.push_back(tile);
		}
	}

	m_mapTile.insert({ _path,returnTilemap });
	return returnTilemap;
}

void TileMgr::LoadTilesetTex()
{
	if(false == m_mapTileset.empty()) return;
	
	for(int i = 1; i <= TILECNT; i++)
	{
		Texture* pTex = new Texture;


		wstring _strFilePath = PathMgr::GetInst()->GetResPath();
		_strFilePath += L"Texture\\Tileset\\Tile_";
		_strFilePath += std::to_wstring(i) + L".bmp";

		pTex->Load(_strFilePath);

		m_mapTileset.insert({i,pTex});
	}
}
