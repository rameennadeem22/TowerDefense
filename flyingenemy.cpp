#include "flyingenemy.h"
void FlyingEnemy::move(sf::Vector2f* path, int pathSize) {
	(void)path;
	(void)pathSize;
	float dx = exitPoint.x - x;
	float dy = exitPoint.y - y;
	float distance = sqrt(dx * dx + dy * dy);
	if (distance < speed) {
		x = exitPoint.x;
		y = exitPoint.y;
		reachedEnd = true;
	}
	else {
		x += (dx / distance) * speed;
		y += (dy / distance) * speed;
	}
}

void FlyingEnemy::render(sf::RenderWindow& window) {
	sprite.setPosition(x, y);
	window.draw(sprite);
	drawHpBar(window);
}