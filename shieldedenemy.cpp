#include "shieldedenemy.h"
#include <cmath>

void ShieldedEnemy::damagetoenemy(int damage) {
	if (ShieldActive) {
		ShieldActive = false;
		return;
	}
	hp -= damage;
	if (hp < 0) {
		hp = 0;
	}
}

void ShieldedEnemy::move(sf::Vector2f* path, int pathSize) {
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

void ShieldedEnemy::render(sf::RenderWindow& window) {
	if (ShieldActive) {
		sprite.setTexture(texture);
	}
	else {
		sprite.setTexture(UnshieldedTexture);
	}
	sprite.setPosition(x, y);
	window.draw(sprite);
	drawHpBar(window);
	drawHpBar(window);
}