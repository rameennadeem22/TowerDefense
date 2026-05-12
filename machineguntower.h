#pragma once
#include "tower.h"
class MachineGunTower : public Tower {
public:
	MachineGunTower(float x, float y) : Tower(x, y, 999, 100.f, 5.0f, 8, 125) {
		texture.loadFromFile("machinegun_tower.png");
		sprite.setTexture(texture);
		sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
		sprite.setScale(0.3f, 0.3f);
	}
	void attack(Enemy** enemies, int enemycount, float dt) override;
	void render(sf::RenderWindow& window) override;
	~MachineGunTower() {}
};