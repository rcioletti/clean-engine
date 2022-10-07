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

std::vector<CollisionComponent*> Game::collisions;

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

	MapManager::LoadMap("assets/clean.map", 16, 16);

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

	for (auto cc : collisions) 
	{
		Collision::AABB(player.getComponent<CollisionComponent>(), *cc);
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
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

void Game::AddTile(int id, int x, int y) 
{
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(x, y, 32, 32, id);
}
