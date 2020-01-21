#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Agent.h"
#include "KeyboardBehaviour.h"
#include "SeekBehaviour.h"
#include <vector.h>
#include "Behaviour.h"
#include "FleeBehaviour.h"
#include "WanderBehaviour.h"
#include"Pursue.h"
#include"EvadeBehaviour.h"
#include "ArrivalBehaviour.h"
#include "FiniteStateMachine.h"
#include "AttackState.h"
#include "IdleState.h"
#include "WithinRangeCondition.h"


class Dinosaur_SimApp : public aie::Application {
public:

	Dinosaur_SimApp();
	virtual ~Dinosaur_SimApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	
	Agent* m_player; //the player
	KeyboardBehaviour* m_keyboardBehaviour;
	
	Agent* m_enemy; //the enemy
	FiniteStateMachine* m_enemyBehaviour;
	
	Agent* m_cat; // the cat
	FleeBehaviour* m_fleeBehaviour;
	
	Agent* m_traveller; // the travller
	WanderBehaviour* m_wanderBehaviour;

	Agent* m_Chaser;
	PursueBehaviour* m_pursueBehaviour;

	Agent* m_Runner;
	EvadeBehaviour* m_evadeBehaviour;

	Agent* m_arrvier;
	ArrivalBehaviour* m_arrivalBehviour;


};