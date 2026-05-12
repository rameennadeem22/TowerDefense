#include "tankenemy.h"
void TankEnemy::damagetoenemy(int damage) {
	int reducedDamage = (int)(damage * 0.8f);
	if (reducedDamage < 1) {
		reducedDamage = 1;
	}
	hp -= reducedDamage;
	if (hp < 0) {
		hp = 0;
	}
}

void TankEnemy::move(sf::Vector2f* path, int pathSize) {
	if (pathIndex >= pathSize) {
		reachedEnd = true;
		return;
	}

	sf::Vector2f target = path[pathIndex];
	float dx = target.x - x;
	float dy = target.y - y;
	float distance = sqrt(dx * dx + dy * dy);
	if (distance < speed) {
		x = target.x;
		y = target.y;
		pathIndex++;
	}
	else {
		x += (dx / distance) * speed;
		y += (dy / distance) * speed;
	}
}

void TankEnemy::render(sf::RenderWindow& window) {
	sprite.setPosition(x, y);
	window.draw(sprite);
	drawHpBar(window);
}