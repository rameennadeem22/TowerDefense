#ifndef TOWER
#define TOWER
#include "enemy.h"
#include "entity.h"
class Tower : public Entity {
protected:
	float range;
	float firerate;
	int damage;
	int cost;
	float time_between_shots;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Tower(float x, float y, int hp, float range, float firerate, int damage, int cost) : Entity(x, y, hp), range(range), firerate(firerate), time_between_shots(0.f), damage(damage), cost(cost) {}

	virtual void attack(Enemy** enemies, int enemycount, float dt) = 0;

	virtual void render(sf::RenderWindow& window) = 0;

	void drawRange(sf::RenderWindow& window) {
		sf::CircleShape circle(range);
		circle.setFillColor(sf::Color(255, 255, 255, 25));
		circle.setOutlineColor(sf::Color(255, 255, 255, 70));
		circle.setOutlineThickness(1.f);
		circle.setOrigin(range, range);
		circle.setPosition(x, y);
		window.draw(circle);
	}
	Enemy* findClosestEnemy(Enemy** enemies, int enemycount) {
		Enemy* target = nullptr;
		double nearestenemy = range;
		for (int i = 0; i < enemycount; i++) {
			if (!enemies[i]->isAlive()) continue;
			double dx = enemies[i]->getX() - x;
			double dy = enemies[i]->getY() - y;
			float distance = sqrt(dx * dx + dy * dy);
			if (distance <= nearestenemy) {
				nearestenemy = distance;
				target = enemies[i];
			}
		}
		return target;
	}
	float getRange() const {
		return range;
	}
	float getfirerate() const {
		return firerate;
	}
	int getDamage() const {
		return damage;
	}
	int getCost() const {
		return cost;
	}
	virtual~Tower() {}
};
#endif