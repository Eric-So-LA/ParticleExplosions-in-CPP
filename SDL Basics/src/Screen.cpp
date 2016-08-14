/*
 * Screen.cpp
 *
 *  Created on: Aug 7, 2016
 *      Author: ericso0303
 */

#include "Screen.h"

namespace explosions {
Screen::Screen() :
		m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL), m_buffer2(NULL) {

}
bool Screen::init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	m_window = SDL_CreateWindow("Particle Fire Explosion",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (m_window == NULL) {
		SDL_Quit();
		return false;
	}

	//you want rendering to be in sync with refresh

	//sheering is bad, it shows a horizontal line if you aren't in sync
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

	//2nd argument is based on how many bytes can represent one pixel
	//each bit represents 4 bytes, 3 of those bytes represents R G B.

	//
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (m_renderer == NULL) {
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	if (m_texture == NULL) {
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	//for each pixel we need 32 bits, or 4 bytes
	m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	m_buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	memset(m_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	return true;
}
void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
	if(x < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT || y < 0){
		return;
	}
	Uint32 color = 0;

	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<=8;
	color += 0xFF;

	m_buffer[(y * SCREEN_WIDTH) + x] = color;
}
void Screen::update() {
	//1st arg = texture, means texture to update
	//2nd arg = rect, the rectangle of textures to update or NULL if you want to update the whole texture
	//3rd arg, = pixels, the total pixel data, represented in your buffer
	//4th arg = pitch, the total number of pixels in a row.
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	//1st null means we want to use entire texture
	//2nd null means we want to use entire renderer
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	//this will present the renderer on the screen
	SDL_RenderPresent(m_renderer);

}
void Screen::boxBlur(){
	Uint32 *temp = m_buffer;
	m_buffer = m_buffer2;
	m_buffer2 = temp;

	for(int y = 0; y < SCREEN_HEIGHT; y++){
		for( int x = 0; x < SCREEN_WIDTH; x++){

			int redTotal = 0;
			int greenTotal = 0;
			int blueTotal = 0;
			for(int row = -1; row <= 1; row++){
				for(int col= -1; col <=1; col++ ){
					int currentX = x + col;
					int currentY = y + row;
					if(currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT){
						Uint32 color = m_buffer2[currentY * SCREEN_WIDTH + currentX];

						Uint8 red = color >> 24;
						Uint8 green = color >> 16;
						Uint8 blue = color >> 8;

						redTotal += red;
						greenTotal += green;
						blueTotal += blue;

					}
				}
			}

			Uint8 red = redTotal/9;
			Uint8 green = greenTotal/9;
			Uint8 blue = blueTotal/9;

			setPixel(x,y, red, green, blue);
		}
	}
}
bool Screen::processEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	}
	return true;
}
void Screen::close() {
	delete[] m_buffer;
	delete[] m_buffer2;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}
}
