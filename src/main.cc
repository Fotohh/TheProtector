#include <iostream>

#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>

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

	SDL_Renderer *renderer = SDL_CreateRenderer(window, nullptr);

	if (renderer == nullptr) {
		std::cerr << "Failed to create SDL Renderer: " << SDL_GetError() << "\n";
		SDL_DestroyWindow(window);
		SDL_Quit();
		return EXIT_FAILURE;
	}

	bool running = true;

	SDL_Event event;

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
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
		SDL_RenderClear(renderer);

		//particle accelerator
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}
