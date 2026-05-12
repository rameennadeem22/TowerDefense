#pragma once
#include "tower.h"
class SlowTower : public Tower {
	float slowDuration;
	float slowStrength;

public:
	SlowTower(float x, float y) : Tower(x, y, 999, 120.f, 1.0f, 0, 100), slowDuration(2.0f), slowStrength(0.5f) {
		texture.loadFromFile("slow_tower.png");
		sprite.setTexture(texture);
		sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
		sprite.setScale(0.08f, 0.08f);
	}

	void attack(Enemy** enemies, int enemycount, float dt) override;
	void render(sf::RenderWindow& window) override;
	~SlowTower() {}
};