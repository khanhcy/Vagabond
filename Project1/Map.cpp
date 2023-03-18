#include"Map.h"
//#include"commonFuncion.h"


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
			if (x >= 0) {
				if (j > gamemap.maxX) {
					gamemap.maxX = j;
				}
				if (i > gamemap.maxY) {
					gamemap.maxY = i;
				}
			}
		}
	}
	
	gamemap.maxX = gamemap.maxX * TILE_SIZE;
	gamemap.maxY = gamemap.maxY * TILE_SIZE;
	
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
	int mapX = 0;
	int mapY = 0;

	// tính toán vị trí bắt đầu và kết thúc của tilemap dựa trên vị trí của nhân vật
	int startX = gamemap.startX / TILE_SIZE;
	int startY = gamemap.startY / TILE_SIZE;
	int endX = (gamemap.startX + SCREEN_WIDTH) / TILE_SIZE;
	int endY = (gamemap.startY + SCREEN_HEIGHT) / TILE_SIZE;

	// giới hạn vị trí bắt đầu và kết thúc tilemap trong phạm vi của map
	if (startX < 0) {
		startX = 0;
	}
	if (startY < 0) {
		startY = 0;
	}
	if (endX > gamemap.maxX) {
		endX = gamemap.maxX;
	}
	if (endY > gamemap.maxY) {
		endY = gamemap.maxY;
	}

	// vẽ từng tile trong phạm vi của tilemap
	for (int i = startY; i < endY; i++) {
		for (int j = startX; j < endX; j++) {
			// lấy thông tin của tile từ mảng gamemap.tile
			int tileType = gamemap.tile[i][j];
			// nếu tileType không phải là 0 (tức là không phải là ô trống), vẽ tile đó lên màn hình
			if (tileType >= 0) {
				// tính toán vị trí của tile trên màn hình
				int x = (j * TILE_SIZE) - gamemap.startX;
				int y = (i * TILE_SIZE) - gamemap.startY;
				// lấy texture của tile từ tileSet và vẽ lên màn hình
				tileSet[0].setCurrentFrame(commonFuc::getTileSet(tileType));
				tileSet[0].setEntity(x, y, TILE_SIZE, TILE_SIZE);
				commonFuc::render(tileSet[0]);
			}
		}
	}
}
