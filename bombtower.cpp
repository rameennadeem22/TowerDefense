#include "bombtower.h"

void BombTower::attack(Enemy** enemies, int enemycount, float dt) {
	time_between_shots -= dt;
	if (time_between_shots > 0.f) {
		return;
	}

	Enemy* primary = findClosestEnemy(enemies, enemycount);
	if (primary == nullptr) return;
	float explosionX = primary->getX();
	float explosionY = primary->getY();

	for (int i = 0; i < enemycount; i++) {
		if (!enemies[i]->isAlive()) continue;
		float dx = enemies[i]->getX() - explosionX;
		float dy = enemies[i]->getY() - explosionY;
		float distance = sqrt(dx * dx + dy * dy);
		if (distance <= splashRadius) {
			enemies[i]->damagetoenemy(damage);
		}
	}
	time_between_shots = 1.f / firerate;
}

void BombTower::render(sf::RenderWindow& window) {
	drawRange(window);
	sprite.setPosition(x, y);
	window.draw(sprite);
}

