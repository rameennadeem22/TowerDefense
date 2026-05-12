#include "snipertower.h"

Enemy* SniperTower::findFurthestEnemy(Enemy** enemies, int enemycount) {
	Enemy* target = nullptr;
	int bestIndex = -1;
	for (int i = 0; i < enemycount; i++) {
		if (!enemies[i]->isAlive()) continue;
		float dx = enemies[i]->getX() - x;
		float dy = enemies[i]->getY() - y;
		float distance = sqrt(dx * dx + dy * dy);
		if (distance > range) continue;
		if (enemies[i]->getPathIndex() > bestIndex) {
			bestIndex = enemies[i]->getPathIndex();
			target = enemies[i];
		}
	}
	return target;
}

void SniperTower::attack(Enemy** enemies,int enemycount, float dt) {
	time_between_shots -= dt;
	if (time_between_shots > 0.f) return;
	Enemy* target = findFurthestEnemy(enemies, enemycount);
	if (target != nullptr) {
		target->damagetoenemy(damage);
		time_between_shots = 1.f / firerate;
	}
}

void SniperTower::render(sf::RenderWindow& window) {
	drawRange(window);
	sprite.setPosition(x, y);
	window.draw(sprite);
}