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
#include "DecisionBehaviour.h"
#include "ABDecision.h"
#include "AttackDecision.h"
#include "IdleDecision.h"
#include "WanderDecision.h"
#include "PursueDecision.h"
#include "Dinosaur.h"
#include "HungryCondition.h"
#include "ThirstyCondition.h"
#include <dijkstrasSearch.h>
#include "Grass.h"
#include "Water.h"
#include "FindFoodDecision.h"
#include "FindWaterDecision.h"
#include "ClosestNode.h"
#include "EvadeDecision.h"


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
	
	//herd
	Dinosaur* m_herbivore;
	aie::Texture* herb;
	//carn
	Dinosaur* m_carnivore;
	aie::Texture* carn;
	//decisions
	DecisionBehaviour* m_HerbDecision; //uses decision tree
	DecisionBehaviour* m_CarniDecision; //uses decision tree
	// terrain
	Grass* grassPatch;
	Water* bodyOfWater;

	float timer = 0;
	float respawnTimer = 10;	
};