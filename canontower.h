#ifndef canontower
#define canontower
#include "tower.h"
class CanonTower : public Tower {
public:
	CanonTower(float x, float y) : Tower(x, y, 999, 150.f, 0.5f, 80, 100) {
		texture.loadFromFile("canon_tower.png");
		sprite.setTexture(texture);
		sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
		sprite.setScale(0.2f, 0.2f);
	}
	void attack(Enemy** enemies, int enemycount, float dt) override;
	void render(sf::RenderWindow& window) override;
	~CanonTower() {}
};
#endif
