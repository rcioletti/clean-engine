#pragma once
#include <SDL.h>
#undef main
#include <iostream>

class Game
{
public:
	Game();
	~Game();

	void init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void update();
	void render();
	void clean();

	void handleEvents();
	bool running() { return isRunning; };

private:

	bool isRunning;
	SDL_Window * window;
	SDL_Renderer * renderer;
};

