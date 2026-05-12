#include "basicenemy.h"
#include <cmath>
void BasicEnemy::move(sf::Vector2f* path, int pathSize) {
	if (pathIndex >= pathSize) {
		reachedEnd = true;
		return;
	}
	sf::Vector2f target = path[pathIndex];
	double dx = target.x - x;
	double dy = target.y - y;
	double distance = sqrt(dx * dx + dy * dy);
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

void BasicEnemy::render(sf::RenderWindow& window) {
	sprite.setPosition(x, y);
	window.draw(sprite);
	drawHpBar(window);
}

