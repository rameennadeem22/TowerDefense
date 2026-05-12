#pragma once
#include "enemy.h"

class TankEnemy :public Enemy {
public:
	TankEnemy(float x, float y) : Enemy(x, y, 400, 0.6f, 30) {
		texture.loadFromFile("tank_enemy.png");
		sprite.setTexture(texture);
		sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
		sprite.setScale(0.17f, 0.17f);

	}
	void damagetoenemy(int damage) override;
	void move(sf::Vector2f* path, int pathSize) override;
	void render(sf::RenderWindow& window) override;
	~TankEnemy() {}
};

//tank enemy hp is 400, speed is 0.6 and reward to kill is 30