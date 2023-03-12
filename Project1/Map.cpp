#include"Map.h"
#include"commonFuncion.h"


//gameMap::gameMap()
//{
//
//}
void gameMap::loadMap(const char* name, const char* path)
{
	std::ifstream file(name);
	for (int i = 0; i < MAX_MAP_Y; i++) {
		std::string s;
		file >> s;
		std::stringstream ss(s);
		std::string c;
		int j = 0;
		while (getline(ss, c, ',')) {
			int x = stoi(c);
			gamemap.tile[i][j] = x;
			j++;
		}
	}
	
	gamemap.maxX = (gamemap.maxX + 1) * TILE_SIZE;
	gamemap.maxY = (gamemap.maxY + 1) * TILE_SIZE;

	gamemap.startX = 0;
	gamemap.startY = 0;

	gamemap.fileName = name;

	Entity tilset(commonFuc::loadTexture(path));
	tileSet.push_back(tilset);

}


void gameMap::drawMap() {
	//vị trí bắt đầu tilemap
	int x1 = 0;
	int y1 = 0;
	// vị trí kết thúc tilemap
	int x2 = 0;
	int y2 = 0;

	//vị trí theo tọa độ chỗ tilemap
	//int mapX = 0;
	//int mapY = 0;

	x1 = (gamemap.startX / TILE_SIZE) * TILE_SIZE;
	x2 = x1 + SCREEN_HEIGHT;
	if (gamemap.startX != x1) { x2 += TILE_SIZE; };

	y1 = (gamemap.startY / TILE_SIZE) * TILE_SIZE;
	y2 = (y1 + SCREEN_WIDTH);
	if (gamemap.startY != y1) { y2 += TILE_SIZE; };

	for (int i = x1; i < x2; i += TILE_SIZE) {
		for (int j = y1; j < y2; j += TILE_SIZE) {
			int val = gamemap.tile[i / TILE_SIZE][j / TILE_SIZE];
			if (val >= 0) {
				tileSet[0].setCurrentFrame(commonFuc::getTileSet(val));
				tileSet[0].setEntity(j, i, TILE_SIZE, TILE_SIZE);
				commonFuc::render(tileSet[0]);
			}
		}
	}

	/*for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 40; j++) {
			int val = gamemap.tile[i][j];
			if (val >= 0) {
				tileSet[0].setCurrentFrame(commonFuc::getTileSet(val));
				tileSet[0].setEntity(j * 64, i * 64, 64, 64);
				commonFuc::render(tileSet[0]);
			}
		}
	}*/

}
