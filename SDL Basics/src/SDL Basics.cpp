//============================================================================
// Name        : SDL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"
#include "Screen.h"
using namespace std;
using namespace explosions;

int main() {

	srand(time(NULL));
	Screen screen;

	if(screen.init() == false){
		cout << "Error in initializing.." << endl;
	}

	bool quit = false;
	Swarm swarm;
	while(true){

		const Particle * const pParticles = swarm.getParticles();
		screen.clear();
		swarm.update();
		for(int i = 0; i < Swarm::NPARTICLES; i++){
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1)*(Screen::SCREEN_WIDTH/2);
			int y = (particle.m_y + 1)*(Screen::SCREEN_HEIGHT/2);

			screen.setPixel(x, y, 255, 255, 255);
		}
		//update position
		//draw particles
		//returns number of milliseconds since program started;


//		int elapsed = SDL_GetTicks();
//		unsigned char red = (unsigned char)((1 + cos(elapsed * 0.0002)) * 128);
//		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
//		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.003)) * 128);
//
//
//		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++){
//			for(int x = 0; x < Screen::SCREEN_WIDTH;x++){
//				screen.setPixel(x, y , red, green, blue);
//			}
//		}
		//check for events
		screen.update();
		if(screen.processEvents()==false){
			break;
		}
	}

	screen.close();

	return 0;
}
