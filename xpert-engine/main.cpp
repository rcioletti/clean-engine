#include "Game.h"

Game * game = nullptr;

int main(int argc, const char * argv[]) {
	
	game = new Game();

	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();
	
	return 0;
}