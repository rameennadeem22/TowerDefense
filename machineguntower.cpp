#include "machineguntower.h"

void MachineGunTower::attack(Enemy** enemies, int enemycount, float dt) {
	time_between_shots -= dt;
	if (time_between_shots > 0.f) return;
	Enemy* target = findClosestEnemy(enemies, enemycount);
	if (target != nullptr) {
		target->damagetoenemy(damage);
		time_between_shots = 1.f / firerate;
	}
}

void MachineGunTower::render(sf::RenderWindow& window) {
	drawRange(window);
	sprite.setPosition(x, y);
	window.draw(sprite);
}