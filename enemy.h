#include "entity.h"
#ifndef ENEMY
#define ENEMY
class Enemy : public Entity {
protected:
	float speed;
	float basespeed; //for the effect of the slow tower
	float slowTimer;
	int pathIndex;
	int reward;
	bool reachedEnd;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Enemy(float x, float y, int hp, float speed, int reward) : Entity(x, y, hp), speed(speed), basespeed(speed),slowTimer(0.f), pathIndex(1), reward(reward), reachedEnd(false) {}

	virtual void move(sf::Vector2f* path, int pathSize) = 0;

	virtual void render(sf::RenderWindow& window) = 0;

	void drawHpBar(sf::RenderWindow& window) {
		float barWidth = 40.f;
		float barHeight = 6.f;
		sf::RectangleShape background(sf::Vector2f(barWidth, barHeight));
		background.setFillColor(sf::Color::Red);
		background.setPosition(x - barWidth / 2, y - 30.f);
		float hpPercent = (float)hp / (float)maximumhp;
		sf::RectangleShape remaining_Health(sf::Vector2f(barWidth * hpPercent, barHeight));
		remaining_Health.setFillColor(sf::Color::Green);
		remaining_Health.setPosition(x - barWidth / 2,y - 30.f);
		window.draw(background);
		window.draw(remaining_Health);
	}
	void applySlow(float strength, float duration) {
		speed = basespeed * strength;
		slowTimer = duration;
	}
	void updateSlow(float dt) {
		if (slowTimer > 0.f) {
			slowTimer -= dt;
			if (slowTimer <= 0.f) {
				slowTimer = 0.f;
				speed = basespeed;
			}
		}
	}
	bool isSlowed() const {
		return slowTimer > 0.f;
	}
	float getSpeed() const {
		return speed;
	}
	int getReward() const {
		return reward;
	}
	bool hasReachedEnd() const {
		return reachedEnd;
	}
	int getPathIndex() const {
		return pathIndex;
	}
	void setSpeed(float s) {
		speed = s;
	}
	virtual~Enemy() {}
};
#endif