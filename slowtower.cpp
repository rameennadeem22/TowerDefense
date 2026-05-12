#include "slowtower.h"
#include <cmath>

void SlowTower::attack(Enemy** enemies, int enemycount, float dt) {
	time_between_shots -= dt;
	if (time_between_shots > 0.f) {
		return;
	}
	bool hit = false;
	for (int i = 0; i < enemycount; i++) {
		if (!enemies[i]->isAlive()) {
			continue;
		}
		float dx = enemies[i]->getX() - x;
		float dy = enemies[i]->getY() - y;
		float distance = sqrt(dx * dx + dy * dy);
		if (distance <= range) {
			enemies[i]->applySlow(slowStrength, slowDuration);
			hit = true;
		}
	}
	if (hit) {
		time_between_shots = 1.f / firerate;
	}
}

void SlowTower::render(sf::RenderWindow& window) {
	drawRange(window);
	sprite.setPosition(x, y);
	window.draw(sprite);
}