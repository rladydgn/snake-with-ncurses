#include "Map.h"

Map::Map(){
  mapFile = "./map/map1.txt" // "./map/map" + stage + ".txt"
  std::ifstream readFile(mapFile);

  int row = 0;
  int col = 0;
  int c;
  while((c = readFile.get()) != EOF) {
    if (c == '\n') {
      row += 1;
      col = 0;
      continue;
    }
    else if (c != '0' && c != '1' && c != '2') {
      continue;
    }

    mapData[row][col] = (char)c;
    col += 1;
  }
  readFile.close();
}
char Map::getMapData(int row, int col) {
  return mapDataArray[i][j];
}
