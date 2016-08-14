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


	Swarm swarm;
	while(true){

		int elapsed = SDL_GetTicks();
		const Particle * const pParticles = swarm.getParticles();

		swarm.update(elapsed);
		for(int i = 0; i < Swarm::NPARTICLES; i++){
			Particle particle = pParticles[i];
			const int calculation = Screen::SCREEN_WIDTH/2;
			int x = (particle.m_x + 1)*(calculation);
			int y = (particle.m_y)*(calculation) + Screen::SCREEN_HEIGHT/2;
			unsigned char red = (unsigned char)((1 + cos(elapsed * 0.0006)) * 128);
			unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
			unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.003)) * 128);
			screen.setPixel(x, y, red, green, blue);
		}
		//update position
		//draw particles
		//returns number of milliseconds since program started;


//		int elapsed = SDL_GetTicks();

//
//
//		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++){
//			for(int x = 0; x < Screen::SCREEN_WIDTH;x++){
//				screen.setPixel(x, y , red, green, blue);
//			}
//		}
		//check for events
		//box blur
		screen.boxBlur();
		screen.update();
		if(screen.processEvents()==false){
			break;
		}
	}

	screen.close();

	return 0;
}
