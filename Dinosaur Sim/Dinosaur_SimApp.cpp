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
	//set up node map
	const int mapX = 20;
	const int mapY = 20;
	std::vector<Pathfinding::Node*> nodeMap = GenerateNodeMap(mapX, mapY, getWindowWidth(), getWindowHeight());

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	//Player Agent
	m_player = new Agent();
	m_player->SetPosition(vector2(100.0f, 100.0f));
	m_player->SetVelocity(vector2(0, 0));
	m_keyboardBehaviour = new KeyboardBehaviour();
	m_player->AddBehaviour(m_keyboardBehaviour); //movement behaviour

	//instaniate terrain
	grassPatch = new Grass();
	grassPatch->SetPosition(nodeMap.front()->connections.back().target->connections.back().target->connections.back().target->connections.back().target->connections.back().target);
	bodyOfWater = new Water();
	bodyOfWater->SetPosition(nodeMap.front()->connections.back().target->connections.back().target);
	
	//chooser
	m_chooser = new Dinosaur();
	m_chooser->SetPosition(vector2(200, 200));
	m_chooser->SetVelocity(vector2(0, 0));
	m_chooser->SetDinosaur(20, 35, true, 10, 3);
	m_chooser->SetCurrentHunger(20);
	m_chooser->SetCurrentThirst(35);
	m_Attackdecision = new DecisionBehaviour();
	/*ABDecision* withinRange50 = new ABDecision(new AttackDecision(m_player), new PursueDecision(m_player, 30), new WithinRangeCondition(m_player, 50));
	ABDecision* withinRange200 = new ABDecision(withinRange50, new WanderDecision(), new WithinRangeCondition(m_player, 200));*/
	Decision* FindFood = new FindFoodDecision(FindClosestNode(grassPatch->GetPosition().x, grassPatch->GetPosition().y, nodeMap), nodeMap);
	Decision* FindWater = new FindWaterDecision(FindClosestNode(bodyOfWater->GetPosition().x, bodyOfWater->GetPosition().y, nodeMap), nodeMap);
	ABDecision* isHungry = new ABDecision(FindFood, new WanderDecision(), new HungryCondition());
	ABDecision* isThirsty = new ABDecision(new WanderDecision(), isHungry, new ThirstyCondition());
	m_Attackdecision->addDecision(isThirsty);
	m_chooser->AddBehaviour(m_Attackdecision); //if within range, attck

	

	////enemy Agent
	//m_enemy = new Agent();
	//m_enemy->SetPosition(vector2(500.0f, 500.0f));
	//m_enemy->SetVelocity(vector2(0, 0));
	//m_enemyBehaviour = new FiniteStateMachine();
	//m_enemy->AddBehaviour(m_enemyBehaviour); //enemy behaviour

	return true;
}

void Dinosaur_SimApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void Dinosaur_SimApp::update(float deltaTime) {
	
	m_player->Update(deltaTime);
	m_chooser->Update(deltaTime);
	m_chooser->StatsDecay(deltaTime);
	//m_enemy->Update(deltaTime);

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
	grassPatch->Draw(m_2dRenderer);
	bodyOfWater->Draw(m_2dRenderer);
	//m_enemy->Draw(m_2dRenderer);
	

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font,"Hunger: Thirst: ", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}