#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "MapManager.h"

GameObject * player;
GameObject * player2;
MapManager* map;

SDL_Renderer* Game::renderer = nullptr;

void Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen) 
{
	int flags = 0;

	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SubSystem Initialized!..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) 
		{
			std::cout << "Window created!..." << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) 
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created!..." << std::endl;
		}
		isRunning = true;

	}
	else {
		isRunning = false;
	}

	player = new GameObject("assets/player.png", 0, 0);
	player2 = new GameObject("assets/player2.png", 50, 50);
	map = new MapManager();
}

void Game::handleEvents() 
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

void Game::update() 
{
	player->Update();
	player2->Update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	player->Render();
	player2->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean() 
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned!..." << std::endl;

}

Game::Game()
{
}


Game::~Game()
{
}
