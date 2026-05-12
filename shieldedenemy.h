#ifndef shieldedenemy
#define shieldedenemy
#include "enemy.h"
 
class ShieldedEnemy : public Enemy {
private:
	bool ShieldActive;
	sf::Texture texture;
	sf::Texture UnshieldedTexture;
	sf::Sprite sprite;
public:
	ShieldedEnemy(float x, float y) : Enemy(x, y, 120, 1.2f, 25), ShieldActive(true) {
		texture.loadFromFile("shielded.png");
		UnshieldedTexture.loadFromFile("unshielded.png");
		sprite.setTexture(texture);
		sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
		sprite.setScale(0.17f, 0.17f);
	}

	void damagetoenemy(int damage) override;
	void move(sf::Vector2f* path, int pathSize) override;
	void render(sf::RenderWindow& window) override;
	bool isShielded() const {
		return ShieldActive;
	}
	~ShieldedEnemy() {}
};
#endif

//shielded enemy hp is 120, speed is 1.2 and reward to kill is 25
