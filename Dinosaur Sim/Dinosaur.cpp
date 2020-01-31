#include "Dinosaur.h"
//Setters
void Dinosaur::SetCurrentHunger(float val)
{
	currentHunger = val;
}
void Dinosaur::SetMaxHunger(float val)
{
	maxHunger = val;
}
void Dinosaur::SetCurrentThirst(float val)
{
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
void Dinosaur::SetDinosaur(float _hunger, float _thirst, bool _carnivore, int _health, int _damage)
{
	SetMaxHunger(_hunger);
	SetMaxThirst(_thirst);
	SetCarnivore(_carnivore);
	SetMaxHealth(_health);
	SetDamage(_damage);
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