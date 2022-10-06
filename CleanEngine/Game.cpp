#include "Game.h"
#include "TextureManager.h"
#include "MapManager.h"
#include "Components.h"
#include "Vector2D.h"
#include "Collision.h"

MapManager* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

auto& player(manager.addEntity());
auto& wall(manager.addEntity());

void Game::init(const char * title, int width, int height, bool fullscreen) 
{
	int flags = 0;

	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SubSystem Initialized!..." << std::endl;

		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
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
	map = new MapManager();

	player.addComponent<TransformComponent>(0,0);
	player.addComponent<SpriteComponent>("assets/player.png");
	player.addComponent<KeyboardController>();
	player.addComponent<CollisionComponent>("player");

	wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
	wall.addComponent<SpriteComponent>("assets/dirt.png");
	wall.addComponent<CollisionComponent>("wall");
}

void Game::handleEvents() 
{
	
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
	manager.refresh();
	manager.update();

	if (Collision::AABB(player.getComponent<CollisionComponent>().colllision, wall.getComponent<CollisionComponent>().colllision))
	{
		std::cout << "Wall Hit!" << std::endl;
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	manager.draw();
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
