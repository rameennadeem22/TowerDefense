#include "game.h"
#include "shieldedenemy.h"
#include <SFML/Window/Event.hpp> 


Game::Game() : window(sf::VideoMode(1200,rows* tilesize + 50), "Tower Defense")
,gold(500), lives(10), currentWave(0), enemycount(0), 
towerCount(0), pathSize(0), gameOver(false), gameWon(false), selectedTower(1) {
	window.setFramerateLimit(60);
	for (int i = 0; i < max_enemies; i++) {
		enemies[i] = nullptr;
	}
	for (int i = 0; i < max_towers; i++) {
		towers[i] = nullptr;
	}
	if (!font.loadFromFile("arial.ttf")) {
		cout << "Warning. Font not loaded!" << endl;
	}
	mapgrid();
	managewaves();
}

Game::~Game() {
	for (int i = 0; i < enemycount; i++) {
		delete enemies[i];
		enemies[i] = nullptr;
	}
	for (int j = 0; j < towerCount; j++) {
		delete[] towers[j];
		towers[j] = nullptr;
	}
}

void Game::mapgrid() {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			grid[r][c] = 0;
		}
	}
	for (int c = 0; c <= 24; c++) {
		grid[2][c] = 1;
	}
	for (int r = 2; r <= 8; r++) {
		grid[r][24] = 1;
	}
	for (int c = 0; c <= 24; c++) {
		grid[8][c] = 1;
	}
	for (int r = 8; r <= 13; r++) {
		grid[r][0] = 1;
	}
	for (int c = 0; c <= 24; c++) {
		grid[13][c] = 1;
	}
	pathSize = 0;
	path[pathSize++] = sf::Vector2f(0 * tilesize + 20.f, 2 * tilesize + 20.f);
	path[pathSize++] = sf::Vector2f(24 * tilesize + 20.f, 2 * tilesize + 20.f);
	path[pathSize++] = sf::Vector2f(24 * tilesize + 20.f, 8 * tilesize + 20.f);
	path[pathSize++] = sf::Vector2f(0 * tilesize + 20.f, 8 * tilesize + 20.f);
	path[pathSize++] = sf::Vector2f(0 * tilesize + 20.f, 13 * tilesize + 20.f);
	path[pathSize++] = sf::Vector2f(24 * tilesize + 20.f, 13 * tilesize + 20.f);


}
void Game::managewaves() {
	currentWave++;
	sf::Vector2f exitPoint = path[pathSize - 1]; //for flying birds
	if (currentWave == 1) {
		for (int i = 0; i < 8 && enemycount < max_enemies; i++) {
			enemies[enemycount++] = new BasicEnemy(path[0].x - i * 55.f, path[0].y);
		}
	}
	else if (currentWave == 2) {
		for (int i = 0; i < 6 && enemycount < max_enemies; i++) {
			enemies[enemycount++] = new BasicEnemy(path[0].x - i * 55.f, path[0].y);
		}
		for (int i = 0; i < 5 && enemycount < max_enemies; i++) {
			enemies[enemycount++] = new FastEnemy(path[0].x - (i + 6) * 40.f, path[0].y);
		}
	}
	else if (currentWave == 3) {
		for (int i = 0; i < 5 && enemycount < max_enemies; i++) {
			enemies[enemycount++] = new BasicEnemy(path[0].x - i * 55.f, path[0].y);
		}
		for (int i = 0; i < 4 && enemycount < max_enemies; i++) {
			enemies[enemycount++] = new FastEnemy(path[0].x - (i + 5) * 40.f, path[0].y);
		}
		for (int i = 0; i < 2 && enemycount < max_enemies; i++) {
			enemies[enemycount++] = new TankEnemy(path[0].x - (i + 9) * 70.f, path[0].y);
		}
		for (int i = 0; i < 3 && enemycount < max_enemies; i++) {
			enemies[enemycount++] = new ShieldedEnemy(path[0].x - (i + 11) * 55.f, path[0].y);
		}

	}
	else if (currentWave == 4) {
		for (int i = 0; i < 4 && enemycount < max_enemies; i++) {
			enemies[enemycount++] = new TankEnemy(path[0].x - i * 70.f, path[0].y);
		}
		for (int i = 0; i < 6 && enemycount < max_enemies; i++) {
			enemies[enemycount++] = new FastEnemy(path[0].x - (i + 4) * 40.f, path[0].y);
		}
		for (int i = 0; i < 4 && enemycount < max_enemies; i++) {
			enemies[enemycount++] = new FlyingEnemy(path[0].x - i * 60.f, path[0].y - 80.f, exitPoint);
		}
		for (int i = 0; i < 3 && enemycount < max_enemies; i++) {
			enemies[enemycount++] = new ShieldedEnemy(path[0].x - (i + 10) * 55.f, path[0].y);
		}
	}
	else if (currentWave==5) {
		for (int i = 0; i < 6 && enemycount < max_enemies; i++) {
			enemies[enemycount++] = new BasicEnemy(path[0].x - i * 50.f, path[0].y);
		}
		for (int i = 0; i < 5 && enemycount < max_enemies; i++) {
			enemies[enemycount++] = new FastEnemy(path[0].x - (i + 6) * 38.f, path[0].y);
		}
		for (int i = 0; i < 3  && enemycount < max_enemies; i++) {
			enemies[enemycount++] = new TankEnemy(path[0].x - (i + 11) * 65.f, path[0].y);
		}
		for (int i = 0; i < 4 && enemycount < max_enemies; i++) {
			enemies[enemycount++] = new FlyingEnemy(path[0].x - i * 55.f, path[0].y - 80.f, exitPoint);
		}
		for (int i = 0; i < 3 && enemycount < max_enemies; i++) {
			enemies[enemycount++] = new ShieldedEnemy(path[0].x - (i + 18) * 55.f, path[0].y);
		}
	}
}

void Game::run() {
	while (window.isOpen()) {
		float dt = gameClock.restart().asSeconds();
		pressedkey();
		if (!gameOver && !gameWon) {
			update(dt);
		}
		render();
	}
}

void Game::pressedkey() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape) {
				window.close();
			}
			if (event.key.code == sf::Keyboard::Num1) selectedTower = 1;
			if (event.key.code == sf::Keyboard::Num2) selectedTower = 2;
			if (event.key.code == sf::Keyboard::Num3) selectedTower = 3;
			if (event.key.code == sf::Keyboard::Num4) selectedTower = 4;
			if (event.key.code == sf::Keyboard::Num5) selectedTower = 5;

		}
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				placeTower(event.mouseButton.x, event.mouseButton.y);
			}
		}
	}
}

void Game::update(float dt) {
	for (int i = 0; i < enemycount; i++) {
		if (!enemies[i]->isAlive()) {
			continue;
		}
		enemies[i]->updateSlow(dt);
		enemies[i]->move(path, pathSize);

		if (enemies[i]->hasReachedEnd()) {
			lives--;
			enemies[i]->damagetoenemy(enemies[i]->getHp());
			if (lives <= 0) {
				gameOver = true;
				return;
			}
		}
	}

	for (int i = 0; i < towerCount; i++) {
		towers[i]->attack(enemies, enemycount, dt);
	}
	for (int i = 0; i < enemycount; i++) {
		if (!enemies[i]->isAlive() && !enemies[i]->hasReachedEnd()) {
			gold += enemies[i]->getReward();
			enemies[i]->damagetoenemy(0);
		}
	}

	cleanupDead();

	if (currentWave >= 5 && enemycount == 0) {
		gameWon = true;
	}
	if (enemycount == 0 && !gameWon && currentWave<5) {
		managewaves();
	}
}

void Game::drawSidePanel() {
	sf::RectangleShape panel(sf::Vector2f(200.f, rows * tilesize));
	panel.setPosition(cols * tilesize, 0);
	panel.setFillColor(sf::Color(40, 50, 60));
	window.draw(panel);

	sf::Text t;
	t.setFont(font);
	t.setCharacterSize(15);
	t.setFillColor(sf::Color::White);
	t.setString("Tower Defense Game");
	t.setPosition(cols * tilesize + 10, 10);
	window.draw(t);

	sf::RectangleShape line(sf::Vector2f(180.f, 2.f));
	line.setFillColor(sf::Color(80, 80, 80));
	line.setPosition(cols * tilesize + 10, 35);
	window.draw(line);

	t.setFillColor(sf::Color(255, 150, 150));
	t.setString("Enemies");
	t.setPosition(cols * tilesize + 10, 50);
	window.draw(t);

	t.setFillColor(sf::Color::White);
	t.setString("Remaining in this Wave: " + std::to_string(enemycount));
	t.setPosition(cols * tilesize + 10, 72);
	window.draw(t);

	line.setPosition(cols * tilesize + 10, 120);
	window.draw(line);

	t.setFillColor(sf::Color::White);
	t.setString("Selected Tower");
	t.setPosition(cols * tilesize + 10, 130);
	window.draw(t);

	if (selectedTower == 1) {
		t.setString("Cannon Tower");
		t.setPosition(cols * tilesize + 10, 155);
		window.draw(t);
		t.setString("Cost : 100 gold");
		t.setPosition(cols * tilesize + 10, 175);
		window.draw(t);
	}

	if (selectedTower == 2) {
		t.setString("Sniper Tower");
		t.setPosition(cols * tilesize + 10, 155);
		window.draw(t);
		t.setString("Cost : 150 gold");
		t.setPosition(cols * tilesize + 10, 175);
		window.draw(t);
	}

	if (selectedTower == 3) {
		t.setString("Machine Gun Tower");
		t.setPosition(cols * tilesize + 10, 155);
		window.draw(t);
		t.setString("Cost : 125 gold");
		t.setPosition(cols * tilesize + 10, 175);
		window.draw(t);
	}

	if (selectedTower == 4) {
		t.setString("Slow Tower");
		t.setPosition(cols * tilesize + 10, 155);
		window.draw(t);
		t.setString("Cost : 100 gold");
		t.setPosition(cols * tilesize + 10, 175);
		window.draw(t);
	}

	if (selectedTower == 5) {
		t.setString("Bomb Tower");
		t.setPosition(cols * tilesize + 10, 155);
		window.draw(t);
		t.setString("Cost : 175 gold");
		t.setPosition(cols * tilesize + 10, 175);
		window.draw(t);
	}

	line.setPosition(cols * tilesize + 10, 260);
	window.draw(line);

	t.setFillColor(sf::Color(150, 150, 150));
	t.setCharacterSize(12);
	t.setString("Press 1-5 to select");
	t.setPosition(cols * tilesize + 10, 200);
	window.draw(t);



}

void Game::render() {
	window.clear(sf::Color(40,50,60));
	drawSidePanel();
	drawMap();
	for (int i = 0; i < towerCount; i++) {
		towers[i]->render(window);
	}
	for (int i = 0; i < enemycount; i++) {
		if (enemies[i]->isAlive()) {
			enemies[i]->render(window);
		}
	}
	drawgame();
	if (gameOver) {
		drawGameOver();
	}
	if (gameWon) {
		sf::RectangleShape overlay(sf::Vector2f(cols * tilesize, rows * tilesize));
		overlay.setFillColor(sf::Color(10,20,50));
		window.draw(overlay);
		sf::Text t;
		t.setFont(font);
		t.setCharacterSize(48);
		t.setFillColor(sf::Color::Green);
		t.setString("Game Won!");
		t.setOrigin(t.getLocalBounds().width / 2, t.getLocalBounds().height / 2);
		t.setPosition(cols * tilesize / 2.f, rows * tilesize / 2.f);
		window.draw(t);
	}
	window.display();
}

void Game::drawMap() {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			sf::RectangleShape tile(sf::Vector2f(tilesize - 1.f, tilesize - 1.f));
			tile.setPosition(c * tilesize, r * tilesize);
			
			if (grid[r][c] == 1) {
				tile.setFillColor(sf::Color(220,235,245));
			}
			else {
				tile.setFillColor(sf::Color(150,170,190));
			}
			window.draw(tile);
		}
	}
}

void Game::drawgame() {
	sf::RectangleShape bar(sf::Vector2f(cols * tilesize, 50.f));
	bar.setPosition(0, rows * tilesize);
	bar.setFillColor(sf::Color(40,50,60));
	window.draw(bar);

	sf::Text t;
	t.setFont(font);
	t.setCharacterSize(18);

	t.setFillColor(sf::Color(255, 215, 0));
	t.setString("Gold: " + std::to_string(gold));
	t.setPosition(10, rows * tilesize + 12);
	window.draw(t);

	t.setFillColor(sf::Color::White);
	t.setString("Wave: " + std::to_string(currentWave));
	t.setPosition(110, rows * tilesize + 12);
	window.draw(t);

	t.setFillColor(sf::Color(255,80,80));
	t.setString("Lives: " + std::to_string(lives));
	t.setPosition(210,rows * tilesize + 12);
	window.draw(t);

	t.setCharacterSize(13);

	if (selectedTower == 1) {
		t.setFillColor(sf::Color::Red);
	}
	else {
		t.setFillColor(sf::Color::White);
		t.setString("[1] Cannon 100g");
		t.setPosition(310, rows * tilesize + 14);
		window.draw(t);
	}

	if (selectedTower == 2) {
		t.setFillColor(sf::Color::Red);
	}
	else {
		t.setFillColor(sf::Color::White);
		t.setString("[2] Sniper 150g");
		t.setPosition(450, rows * tilesize + 14);
		window.draw(t);
	}
	
	if (selectedTower == 3) {
		t.setFillColor(sf::Color::Red);
	}
	else {
		t.setFillColor(sf::Color::White);
		t.setString("[3] Machine Gun 125g");
		t.setPosition(550, rows * tilesize + 14);
		window.draw(t);
	}

	if (selectedTower == 4) {
		t.setFillColor(sf::Color::Red);
	}
	else {
		t.setFillColor(sf::Color::White);
		t.setString("[4] Slow 100g");
		t.setPosition(710, rows * tilesize + 14);
		window.draw(t);
	}

	if (selectedTower == 5) {
		t.setFillColor(sf::Color::Red);
	}
	else {
		t.setFillColor(sf::Color::White);
		t.setString("[5] Bomb 175g");
		t.setPosition(810, rows * tilesize + 14);
		window.draw(t);
	}

}

void Game::drawGameOver() {
	sf::RectangleShape overlay(sf::Vector2f(cols * tilesize, rows * tilesize));
	overlay.setFillColor(sf::Color(0, 0, 0, 160));
	window.draw(overlay);

	sf::Text t;
	t.setFont(font);
	t.setCharacterSize(48);
	t.setFillColor(sf::Color::Red);
	t.setString("Game Over :(");
	t.setOrigin(t.getLocalBounds().width / 2, t.getLocalBounds().height / 2);
	t.setPosition(cols * tilesize / 2.f, rows * tilesize / 2.f);
	window.draw(t);
}

void Game::placeTower(int mouseX, int mouseY) {
	int col = mouseX / tilesize;
	int row = mouseY / tilesize;
	if (row < 0 || row >= rows || col < 0 || col >= cols) {
		return;
	}
	if (grid[row][col] == 1) {
		return;
	}
	if (towerCount >= max_towers) {
		return;
	}

	float tileX = col * tilesize + tilesize / 2.f;
	float tileY = row * tilesize + tilesize / 2.f;
	for (int i = 0; i < towerCount; i++) {
		if (towers[i]->getX() == tileX && towers[i]->getY() == tileY) {
			return;
		}
	}
		int cost = 0;
		if (selectedTower == 1) {
			cost = 100;
		}
		if (selectedTower == 2) {
			cost = 150;
		}
		if (selectedTower == 3) {
			cost = 125;
		}
		if (selectedTower == 4) {
			cost = 100;
		}
		if (selectedTower == 5) {
			cost = 175;
		}
		if (gold < cost) {
			return;
		}

		Tower* newTower = nullptr;
		if (selectedTower == 1) {
			newTower = new CanonTower(tileX, tileY);
		}
		if (selectedTower == 2) {
			newTower = new SniperTower(tileX, tileY);
		}
		if (selectedTower == 3) {
			newTower = new MachineGunTower(tileX, tileY);
		}
		if (selectedTower == 4) {
			newTower = new SlowTower(tileX, tileY);
		}
		if (selectedTower == 5) {
			newTower = new BombTower(tileX, tileY);
		}

		if (newTower == nullptr) {
			return;
		}

		towers[towerCount++] = newTower;
		gold -= cost;
}

void Game::cleanupDead() {
	for (int i = enemycount - 1; i >= 0; i--) {
		if (!enemies[i]->isAlive() || enemies[i]->hasReachedEnd()) {
			delete enemies[i];

			for (int j = i; j < enemycount - 1; j++) {
				enemies[j] = enemies[j + 1];
			}
			enemies[enemycount - 1] = nullptr;
			enemycount--;
		}

	}
}