#ifndef basicenemy
#define basicenemy
#include "enemy.h"
class BasicEnemy : public Enemy {
public:
	BasicEnemy(float x, float y) : Enemy(x, y, 100, 1.5f, 10) {
		texture.loadFromFile("basic_enemy.png");
		sprite.setTexture(texture);
		sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
		sprite.setScale(0.06f, 0.06f);
	}
	void move(sf::Vector2f* path, int pathSize) override;
	void render(sf::RenderWindow& window) override;
	~BasicEnemy() {}
};
#endif


//basic enemy hp is 100, speed is 1.5 and reward to kill is 10