#pragma once
#include "enemy.h"

class FlyingEnemy : public Enemy {
	sf::Vector2f exitPoint;
public:
	FlyingEnemy(float x, float y, sf::Vector2f exit) : Enemy(x, y, 80, 2.0f, 20), exitPoint(exit) {
		texture.loadFromFile("flying_enemy.png");
		sprite.setTexture(texture);
		sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
		sprite.setScale(0.07f, 0.07f);

}
	void move(sf::Vector2f* path, int pathSize) override;
	void render(sf::RenderWindow& window) override;
	~FlyingEnemy() {}
};

//flyingt enemy hp is 80, speed is 2 and reward to kill is 20