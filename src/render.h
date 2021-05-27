#include <ncurses.h>
#include <string>
#include <fstream>
#include <iostream>
#include "snakeMove.h"
// pair
#include <utility>
// random
#include <cstdlib>
// time
#include <ctime>
// time sleep
#include <unistd.h>
#define EMPTY '0'
#define WALL '1'
#define IMMUNEWALL '2'
#define SNAKEHEAD '3'
#define SNAKEBODY '4'
#define GROWTHITEM '5'
#define POISONITEM '6'
#define GATE '7'
#define ROW 23
#define COL 23

class Render {
  char initMapDataArray[ROW][COL];
  char mapDataArray[ROW][COL];
  std::pair<int,int> growthItem;
  std::pair<int,int> poisonItem;
  std::pair<int,int> gate[2];
  SnakeMove player;
  WINDOW *snakeWindow;
  int dir = KEY_RIGHT;
  bool poison_hit = 0;
  bool growth_hit = 0;
  bool gate_hit = 0;
public:
  Render(char stage='1');
  void initUI();
  void updateUI(int time = 0);
  void endWindow();
  void setMap(int stage);
  char getMapData(int row, int col);
  void updateMapData(int time);
  void spawnGrowthItem();
  void spawnPoisonItem();
  void spawnGate();
  void changeDirAfterPassingGate();
  bool keyInput();
};
