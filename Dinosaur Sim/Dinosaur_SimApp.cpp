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
	const int mapX = 80;
	const int mapY = 80;
	std::vector<Pathfinding::Node*> nodeMap = GenerateNodeMap(mapX, mapY, getWindowWidth(), getWindowHeight());

	herb = new aie::Texture(".\\images\\Brontosaurus.jpg");
	carn = new aie::Texture(".\\images\\TRex.jpg");
	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	//instaniate terrain
	grassPatch = new Grass();
	grassPatch->setHungerValue(100);
	grassPatch->SetPosition(nodeMap[mapX * mapY/3 + mapX /4]);
	bodyOfWater = new Water();
	bodyOfWater->SetPosition(nodeMap[mapX * mapY/2 + mapX/2]);
	
	//set up herbivore so carnivore acn reference
	m_herbivore = new Dinosaur();
	m_herbivore->SetPosition(vector2(200, 200));

	//carnivore
	m_carnivore = new Dinosaur();
	m_carnivore->SetPosition(vector2(400, 400));
	m_carnivore->SetVelocity(vector2(0, 0));
	m_carnivore->SetDinosaur(300, 300, true, 10, 1, vector2(getWindowWidth(), getWindowHeight()));
	m_carnivore->SetCurrentHunger(30);
	m_carnivore->SetCurrentThirst(200);
	m_CarniDecision = new DecisionBehaviour(); //Carni decision tree
	Decision* FindFoodCarni = new FindFoodDecision(m_herbivore, nodeMap);
	Decision* FindWater = new FindWaterDecision(FindClosestNode(bodyOfWater->GetPosition().x, bodyOfWater->GetPosition().y, nodeMap), nodeMap);
	ABDecision* isCarniHungry = new ABDecision(FindFoodCarni, new WanderDecision(), new HungryCondition());
	ABDecision* isCarniThirsty = new ABDecision(FindWater, isCarniHungry, new ThirstyCondition()); //Top of the decision tree
	m_CarniDecision->addDecision(isCarniThirsty);
	m_carnivore->AddBehaviour(m_CarniDecision);

	//herbivore
	m_herbivore->SetVelocity(vector2(0, 0));
	m_herbivore->SetDinosaur(200, 200, true, 3, 0, vector2(getWindowWidth(), getWindowHeight()));
	m_herbivore->SetCurrentHunger(100);
	m_herbivore->SetCurrentThirst(100);
	m_HerbDecision = new DecisionBehaviour(); //Herb decision tree
	Decision* FindFood = new FindFoodDecision(FindClosestNode(grassPatch->GetPosition().x, grassPatch->GetPosition().y, nodeMap), nodeMap);
	ABDecision* isHungry = new ABDecision(FindFood, new WanderDecision(), new HungryCondition());
	ABDecision* isThirsty = new ABDecision(FindWater, isHungry, new ThirstyCondition());
	ABDecision* isChased = new ABDecision(new EvadeDecision(m_carnivore), isThirsty, new WithinRangeCondition(m_carnivore, 100)); //Top of the decision tree
	m_HerbDecision->addDecision(isChased);
	m_herbivore->AddBehaviour(m_HerbDecision);

	return true; //return true if successful
}

void Dinosaur_SimApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete m_herbivore;
	delete m_carnivore;
	delete herb;
	delete carn;
	delete m_HerbDecision;
	delete m_CarniDecision;
	delete grassPatch;
	delete bodyOfWater;
}

void Dinosaur_SimApp::update(float deltaTime) {
	if(!m_herbivore->IsDead()) //if herbivore isnt dead then
	{
		//update this
		m_herbivore->Update(deltaTime);
		m_herbivore->StatsDecay(deltaTime);
	}
	else {
		//Respawn timer
		timer += deltaTime;
		if (timer > respawnTimer) {
			m_herbivore->Respawn();
			timer = 0;
		}
	}
	if (!m_carnivore->IsDead()) { //carn isnt dead then
		//update this
		m_carnivore->Update(deltaTime);
		m_carnivore->StatsDecay(deltaTime);
	}

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
	//grass
	m_2dRenderer->setRenderColour(0, 1, 0); //green
	grassPatch->Draw(m_2dRenderer);
	//water
	m_2dRenderer->setRenderColour(0, 0, 1); //blue
	bodyOfWater->Draw(m_2dRenderer);
	//herbivores
	if (!m_herbivore->IsDead()) {
	m_2dRenderer->setRenderColour(1, 1, 1); //white
	m_2dRenderer->drawSprite(herb, m_herbivore->GetPosition().x, m_herbivore->GetPosition().y,50,50);
	}
	//carnivore
	if (!m_carnivore->IsDead()) {
		m_2dRenderer->setRenderColour(1, 1, 1); //white
		m_2dRenderer->drawSprite(carn, m_carnivore->GetPosition().x, m_carnivore->GetPosition().y, 50, 50);
	}
	

	// output some text, uses the last used colour
	//m_2dRenderer->drawText(m_font,"Hunger: Thirst: ", 0, 0);
	std::cout << "Hunger: " << m_carnivore->GetCurrentHunger() << "	Water: " << m_carnivore->GetCurrentThirst() << std::endl;
	// done drawing sprites
	m_2dRenderer->end();
}

