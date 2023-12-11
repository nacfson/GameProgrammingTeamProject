#pragma once
#include "Texture.h"
#include "tileson.hpp"

enum class EIMAGE_TYPE
{
	NORMAL = 0,
	END = 30
};
struct Tile
{
	int x;
	int y;

	int width;
	int height;

	EIMAGE_TYPE eImage_type;
	bool bHasCollider;
};
class TileMgr
{
	SINGLE(TileMgr);

public:
	void Init();
	std::vector<Tile> GetTileVec(const std::string& _path);
	void LoadTilesetTex();
private:
	std::map<std::string,std::vector<Tile>> m_mapTile;
	std::map<int,Texture*> m_mapTileset;

	float m_fWidth;
	float m_fHeight;

	int m_iWidthCnt;
	int m_iHeightCnt;
};

