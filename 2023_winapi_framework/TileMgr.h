#pragma once
#include "tileson.hpp"

enum EIMAGE_TYPE
{
	NORMAL,
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
private:
	std::map<std::string,std::vector<Tile>> m_mapTile;
};

