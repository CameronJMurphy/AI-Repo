#pragma once
#include "Agent.h"
#include "Food.h"
#include "Water.h"
#include <Bits.h>
class Dinosaur : public Agent, public Food
{
public:
	//setters
	void SetCurrentHunger(float val);
	void SetMaxHunger(float val);

	void SetCurrentThirst(float val);
	void SetMaxThirst(float val);

	void SetCarnivore(bool val);

	void SetCurrentHealth(float val);
	void SetMaxHealth(float val);
	void SetDamage(float val);

	void SetDinosaur(float _maxHunger, float _maxThirst, bool _carnivore, int _health, int _damage , vector2 windowDimensions);

	//getters
	int GetCurrentHealth();
	int GetMaxHealth();
	int GetDamage();
	float GetCurrentHunger();
	float GetMaxHunger();
	float GetCurrentThirst();
	float GetMaxThirst();
	bool IsCarnivore();
	bool IsDead() { return isDead; };
	//death
	void Hurt(int val);
	void Die();
	//respawn
	void Respawn() { isDead = false; SetCurrentHealth(GetMaxHealth());};

	//stat modifiers
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
	float decayAmount = 1; //how much will my stats decay per second
	bool isDead = false;
};

