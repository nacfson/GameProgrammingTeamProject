#pragma once
#include "rapidjson-master/include/rapidjson/document.h"

struct Tile
{
	int x;
	int y;
};
class TileMgr
{
	SINGLE(TileMgr);

public:
	void Init();
	Tile GetTilePosition(const rapidjson::Document& document, int layerIndex, int tileGID, int mapWidth);
};

