#pragma once
#include <string>

class MapManager
{
public:
	MapManager();
	~MapManager();
	
	static void LoadMap(std::string path, int sizeX, int sizeY);

private:
};