#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

int main(int, char*[]) {

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		std::cerr << "Failed to init SDL Video: " << SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}

	SDL_Window* window = SDL_CreateWindow("The Protector", 1920, 1080, SDL_WINDOW_RESIZABLE);

	if (window == nullptr) {
		std::cerr << "Failed to create SDL Window: " << SDL_GetError() << "\n";
		SDL_Quit();
		return EXIT_FAILURE;
	}

	bool running = true;

	SDL_Event event;

	while (running) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_EVENT_QUIT: 
					running = false;
					break;
				default:
					break;
			}
		}
	}
	
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}
