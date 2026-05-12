#pragma once
#include "tower.h"

class BombTower : public Tower {
	float splashRadius;
public:
	BombTower(float x, float y) : Tower(x, y, 999, 160.f, 0.4f, 60, 175), splashRadius(60.f) {
		texture.loadFromFile("bomb_tower.png");
		sprite.setTexture(texture);
		sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
		sprite.setScale(0.2f, 0.2f);
	}
	void attack(Enemy** enemies, int enemycount, float dt) override;
	void render(sf::RenderWindow& window) override;
	~BombTower() {}
};