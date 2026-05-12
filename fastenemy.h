#pragma once
#include "enemy.h"
class FastEnemy : public Enemy {
public:
	FastEnemy(float x, float y) : Enemy(x, y, 50, 3.5f, 15) {
		texture.loadFromFile("fast_enemy.png");
		sprite.setTexture(texture);
		sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
		sprite.setScale(0.18f, 0.18f);

	}
	void move(sf::Vector2f* path, int pathSize) override;
	void render(sf::RenderWindow& window) override;
	~FastEnemy() {}
};

//fast enemy hp is 50, speed is 3.5 and reward to kill is 15