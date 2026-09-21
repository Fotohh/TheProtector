#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

int main(int, char*[]) {

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		std::cerr << "Failed to init SDL Window: " << SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}
	
	SDL_Quit();

	return EXIT_SUCCESS;
}