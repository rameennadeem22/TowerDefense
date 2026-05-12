#pragma once
#include <SFML/Graphics.hpp>
#include "enemy.h"
#include "tower.h"

#include "basicenemy.h"
#include "fastenemy.h"
#include "tankenemy.h"
#include "flyingenemy.h"
#include "shieldedenemy.h"

#include "canontower.h"
#include "snipertower.h"
#include "machineguntower.h"
#include "slowtower.h"
#include "bombtower.h"

class Game {
private:
	static const int tilesize = 40;
	static const int cols = 25;
	static const int rows = 16;
	static const int max_enemies = 200;
	static const int max_towers = 100;
	static const int max_path = 20;

	sf::RenderWindow window;
	int grid[rows][cols];
	sf::Vector2f path[max_path];
	int pathSize;
	
	Enemy* enemies[max_enemies];
	int enemycount;
	Tower* towers[max_towers];
	int towerCount;
	int gold;
	int lives;
	int currentWave;
	bool gameOver;
	bool gameWon;
	int selectedTower;
	sf::Font font;
	sf::Clock gameClock;

	void mapgrid();
	void managewaves();
	void pressedkey();
	void update(float dt); 
	void drawSidePanel();
	void render();
	void drawMap();
	void drawgame();
	void drawGameOver();
	void placeTower(int mouseX, int mouseY);
	void cleanupDead();
	

public:
	Game();
	~Game();
	void run();
};

