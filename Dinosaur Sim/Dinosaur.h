#pragma once
#include "Agent.h"
#include "Food.h"
#include "Water.h"
#include <Bits.h>
class Dinosaur : public Agent, public Food
{
public:

	void SetCurrentHunger(float val);
	void SetMaxHunger(float val);

	void SetCurrentThirst(float val);
	void SetMaxThirst(float val);

	void SetCarnivore(bool val);

	void SetCurrentHealth(float val);
	void SetMaxHealth(float val);
	void SetDamage(float val);

	void SetDinosaur(float _maxHunger, float _maxThirst, bool _carnivore, int _health, int _damage , vector2 windowDimensions);


	int GetCurrentHealth();
	int GetMaxHealth();
	int GetDamage();
	float GetCurrentHunger();
	float GetMaxHunger();
	float GetCurrentThirst();
	float GetMaxThirst();
	bool IsCarnivore();

	void Hurt(int val);
	void Die();
	bool IsDead() { return isDead; };
	void Respawn() { isDead = false; SetCurrentHealth(GetMaxHealth());};
	void StatsDecay(float deltaTime);

	void Eat(Food* food);
	void Drink(Water* water);
private:
	float maxHunger;
	float currentHunger;
	float currentThirst;
	float maxThirst;
	bool carnivore;
	int damage;
	int currentHealth;
	int maxHealth;
	float decayAmount = 1;
	bool isDead = false;
};

