#pragma once
#include "tower.h"
class SniperTower : public Tower {
	Enemy* findFurthestEnemy(Enemy** enemies, int enemycount);
public:
	SniperTower(float x, float y) : Tower(x, y, 999, 300.f, 0.3f, 120, 150) {
		texture.loadFromFile("sniper_tower.png");
		sprite.setTexture(texture);
		sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
		sprite.setScale(0.1f, 0.1f);
	}
	void attack(Enemy** enemies, int enemycount, float dt) override;
	void render(sf::RenderWindow& window) override;
	~SniperTower() {}
};