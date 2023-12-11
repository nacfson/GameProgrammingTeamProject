#include "pch.h"
#include "TileMgr.h"

#include "PathMgr.h"
#include "tileson.hpp"
#include "ResMgr.h"
#include "WinUser.h"
void TileMgr::Init()
{

	
	// m_mapTileset[] = til
	// m_pTex = _pTex;
	// for (int i = 0; i < _framecount; ++i)
	// {
	// 	m_vecAnimFrame.push_back(tAnimFrame({ _vLT + _vStep * i,
	// 		_vSliceSize, _fDuration,{0.f,0.f} }));
	// }
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
				//auto a= d->getAnimation().getFrames()[0];
				int id = d->getGid() - tileset->getFirstgid(); 
                               
				tile.x = position.x;
				tile.y = position.y;

				int cnt = tileset->getTileCount();

				m_iHeightCnt = pow(cnt,2);
				m_iWidthCnt = pow(cnt,2);
								
				m_fWidth = drawingRect.width;
				m_fHeight = drawingRect.height;

				tile.width =  drawingRect.width;
				tile.height = drawingRect.height;

				tile.bHasCollider = true;
				tile.eImage_type = EIMAGE_TYPE::NORMAL;
				returnTilemap.push_back(tile);
			}
		}
	}

	m_mapTile.insert({ _path,returnTilemap });

	LoadTilesetTex();


	return returnTilemap;
}

void TileMgr::LoadTilesetTex()
{
	if(false == m_mapTileset.empty()) return;
	
	//Texture* tilesetTex = ResMgr::GetInst()->TexLoad(L"Tileset",L"Texture\\tileset.bmp");
	//Vec2 _vLT, Vec2 _vSliceSize, Vec2 _vStep, int _framecount, float _fDuration;
	
	for(int i = 0; i < m_iWidthCnt * m_iHeightCnt; i++)
	{
		Texture* pTex = new Texture;
		wstring _strFilePath = 		PathMgr::GetInst()->GetResPath();
		_strFilePath += L"Texture\\tileset.bmp";

		pTex->Load(_strFilePath,i * m_fWidth, i * m_fHeight,m_fWidth,m_fHeight);
		m_mapTileset.insert({i,pTex});
	}
}

