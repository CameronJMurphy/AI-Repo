#include "Dinosaur.h"
//Setters
void Dinosaur::SetCurrentHunger(float val)
{
	if (val > GetMaxHunger())
	{
		val = GetMaxHunger();
	}
	currentHunger = val;
}
void Dinosaur::SetMaxHunger(float val)
{
	maxHunger = val;
}
void Dinosaur::SetCurrentThirst(float val)
{
	if (val > GetMaxThirst())
	{
		val = GetMaxThirst();
	}
	currentThirst = val;
}
void Dinosaur::SetMaxThirst(float val)
{
	maxThirst = val;
}
void Dinosaur::SetCarnivore(bool isCarnivore)
{
	carnivore = isCarnivore;
}
void Dinosaur::SetCurrentHealth(float val)
{
	currentHealth = val;
}
void Dinosaur::SetMaxHealth(float val)
{
	maxHealth = val;
}
void Dinosaur::SetDamage(float val)
{
	damage = val;
}
void Dinosaur::SetDinosaur(float _hunger, float _thirst, bool _carnivore, int _health, int _damage, vector2 winDim)
{
	SetMaxHunger(_hunger);
	SetMaxThirst(_thirst);
	SetCarnivore(_carnivore);
	SetMaxHealth(_health);
	SetDamage(_damage);
	windowDimensions = winDim;
}

//Getters
int Dinosaur::GetCurrentHealth()
{
	return currentHealth;
}
int Dinosaur::GetMaxHealth()
{
	return maxHealth;
}
int Dinosaur::GetDamage()
{
	return damage;
}
float Dinosaur::GetCurrentHunger()
{
	return currentHunger;
}
float Dinosaur::GetMaxHunger()
{
	return maxHunger;
}
float Dinosaur::GetCurrentThirst()
{
	return currentThirst;
}
float Dinosaur::GetMaxThirst()
{
	return maxThirst;
}
bool Dinosaur::IsCarnivore()
{
	return carnivore;
}

void Dinosaur::Hurt(int val) {
	currentHealth -= val;
	if (currentHealth < 0)
	{
		Die();
	}
}

void Dinosaur::Die() {
	isDead = true;
}
void Dinosaur::StatsDecay(float deltaTime)
{
	// reduce hungry and thirst per sec
	SetCurrentThirst(GetCurrentThirst() - (decayAmount * deltaTime));
	SetCurrentHunger(GetCurrentHunger() - (decayAmount * deltaTime));
}
void Dinosaur::Eat(Food* food) 
{
	SetCurrentHunger(GetCurrentHunger() + food->HungerValue());
}
void Dinosaur::Drink(Water* water) {
	SetCurrentThirst(GetCurrentThirst() + water->WaterValue());
}