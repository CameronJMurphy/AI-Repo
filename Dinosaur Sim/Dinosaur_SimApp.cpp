#include "Dinosaur_SimApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Dinosaur_SimApp::Dinosaur_SimApp() {

}

Dinosaur_SimApp::~Dinosaur_SimApp() {

}

bool Dinosaur_SimApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	//Player Agent
	m_player = new Agent();
	m_player->SetPosition(vector2(100.0f, 100.0f));
	m_player->SetVelocity(vector2(0, 0));
	m_keyboardBehaviour = new KeyboardBehaviour();
	m_player->AddBehaviour(m_keyboardBehaviour); //movement behaviour

	
	//chooser
	m_chooser = new Agent();
	m_chooser->SetPosition(vector2(200, 200));
	m_chooser->SetVelocity(vector2(0, 0));
	m_Attackdecision = new DecisionBehaviour();
	ABDecision* withinRange50 = new ABDecision(new AttackDecision(m_player), new PursueDecision(m_player, 30), new WithinRangeCondition(m_player, 50));
	ABDecision* withinRange200 = new ABDecision(withinRange50, new WanderDecision(), new WithinRangeCondition(m_player, 200));
	m_Attackdecision->addDecision(withinRange200); 
	m_chooser->AddBehaviour(m_Attackdecision); //if within range, attck







	////enemy Agent
	//m_enemy = new Agent();
	//m_enemy->SetPosition(vector2(500.0f, 500.0f));
	//m_enemy->SetVelocity(vector2(0, 0));
	//m_enemyBehaviour = new FiniteStateMachine();
	//m_enemy->AddBehaviour(m_enemyBehaviour); //enemy behaviour

	////create new states
	//auto attackState = new AttackState(m_player, 150); auto idleState = new IdleState(); 
	//// create the condition, setting the player as the target
	//auto withinRangeCondition = new WithinRangeCondition(m_player, 200); 
	//// create the transition, this will transition to the attack state when the 
	//// withinRange condition is met 
	//auto toAttackTransition = new Transition(attackState, withinRangeCondition); 
	//// add the transition to the idle state 
	//idleState->addTransition(toAttackTransition); 
	//// add all the states, conditions and transitions to the FSM (the enemy // behaviour) 
	//m_enemyBehaviour->addState(attackState); 
	//m_enemyBehaviour->addState(idleState); 
	//m_enemyBehaviour->addCondition(withinRangeCondition); 
	//m_enemyBehaviour->addTransition(toAttackTransition); // set the current state of the FSM
	//m_enemyBehaviour->setCurrentState(idleState);
	////Cat Agent
	//m_cat = new Agent();
	//m_cat->SetPosition(vector2(400.0f, 400.0f));
	//m_cat->SetVelocity(vector2(0, 0));
	//m_fleeBehaviour = new FleeBehaviour();
	//m_fleeBehaviour->SetTarget(m_enemy);
	//m_cat->AddBehaviour(m_fleeBehaviour); //flee behaviour

	////The unsure traveller
	//m_traveller = new Agent();
	//m_traveller->SetPosition(vector2(600.0f, 600.0f));
	//m_traveller->SetVelocity(vector2(0, 0));
	//m_wanderBehaviour = new WanderBehaviour();
	//m_traveller->AddBehaviour(m_wanderBehaviour); //wander behaviour

	////The Chaser
	//m_Chaser = new Agent();
	//m_Chaser->SetPosition(vector2(500.0f, 500.0f));
	//m_Chaser->SetVelocity(vector2(0, 0));
	//m_pursueBehaviour = new PursueBehaviour();
	//m_pursueBehaviour->SetTarget(m_player);
	//m_Chaser->AddBehaviour(m_pursueBehaviour); //Pursue behaviour

	////The Runner
	//m_Runner = new Agent();
	//m_Runner->SetPosition(vector2(700.0f, 500.0f));
	//m_Runner->SetVelocity(vector2(0, 0));
	//m_evadeBehaviour = new EvadeBehaviour();
	//m_evadeBehaviour->SetTarget(m_player);
	//m_Runner->AddBehaviour(m_evadeBehaviour); //Evade behaviour

	////The Arriver
	//m_arrvier = new Agent();
	//m_arrvier->SetPosition(vector2(700.0f, 500.0f));
	//m_arrvier->SetVelocity(vector2(0, 0));
	//m_arrivalBehviour = new ArrivalBehaviour();
	//m_arrivalBehviour->SetTarget(m_player);
	//m_arrvier->AddBehaviour(m_arrivalBehviour); //Evade behaviour

	return true;
}

void Dinosaur_SimApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void Dinosaur_SimApp::update(float deltaTime) {
	
	m_player->Update(deltaTime);
	m_chooser->Update(deltaTime);
	//m_enemy->Update(deltaTime);
	//m_cat->Update(deltaTime);
	//m_traveller->Update(deltaTime);
	//m_Chaser->Update(deltaTime);
	/*m_Runner->Update(deltaTime);*/
	//m_arrvier->Update(deltaTime);

	// input
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Dinosaur_SimApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_player->Draw(m_2dRenderer);
	m_chooser->Draw(m_2dRenderer);
	//m_enemy->Draw(m_2dRenderer);
	//m_cat->Draw(m_2dRenderer);
	//m_traveller->Draw(m_2dRenderer);
	//m_Chaser->Draw(m_2dRenderer);
	/*m_Runner->Draw(m_2dRenderer);*/
	//m_arrvier->Draw(m_2dRenderer);
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}