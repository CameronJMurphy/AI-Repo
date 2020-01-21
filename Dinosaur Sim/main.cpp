#include "Dinosaur_SimApp.h"
#include<time.h>

int main() {
	srand(time(0));

	// allocation
	auto app = new Dinosaur_SimApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}