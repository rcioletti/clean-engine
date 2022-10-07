#pragma once
#include "SDL.h"
#undef main
#include "SDL_image.h"
#include <iostream>
#include <vector>

class CollisionComponent;

class Game
{
public:
	Game();
	~Game();

	void init(const char * title, int width, int height, bool fullscreen);
	
	void update();
	void render();
	void clean();

	static SDL_Renderer* renderer;
	static SDL_Event event;
	static std::vector<CollisionComponent*> collisions;

	void handleEvents();
	bool running() { return isRunning; };

private:
	int cnt = 0;
	bool isRunning;
	SDL_Window * window;
};

