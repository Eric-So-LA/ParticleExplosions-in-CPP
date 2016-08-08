//============================================================================
// Name        : SDL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#include "Screen.h"
using namespace std;
using namespace explosions;

int main() {

	Screen screen;

	if(screen.init() == false){
		cout << "Error in initializing.." << endl;
	}

	bool quit = false;
	SDL_Event event;

	while(true){
		//update position
		//draw particles
		//check for events
		screen.update();
		if(screen.processEvents()==false){
			break;
		}
	}

	screen.close();

	return 0;
}
