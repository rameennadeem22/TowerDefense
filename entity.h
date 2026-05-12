#ifndef ENTITY
#define ENTITY
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
using namespace std;

class Entity {
protected:
	float x, y;
	int hp;
	int maximumhp;
public:
	Entity(float a, float b, int h) : x(a), y(b), hp(h), maximumhp(h) {}
	virtual void render(sf::RenderWindow& window) = 0;
	virtual void damagetoenemy(int dam) {
		hp -= dam;
		if (hp < 0) {
			hp = 0;
		}
	}
	float getX() const {
		return x;
	}
	float getY() const {
		return y;
	}
	int getHp() const {
		return hp;
	}
	int getmaximumhp() const {
		return maximumhp;
	}
	bool isAlive() const {
		return (hp > 0);
	}
	virtual~Entity() {
	}

	bool operator==(const Entity& other) const {
		return x == other.x && y == other.y;
	}
	bool operator!=(const Entity& other) const {
		return!(*this == other);
	}
};
#endif
