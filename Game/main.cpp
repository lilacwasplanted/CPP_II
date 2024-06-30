#include <SDL.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char* argv[])
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
		return 1;
	}

	// create window
	// returns pointer to window if successful or nullptr if failed
	SDL_Window* window = SDL_CreateWindow("Game Engine",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600,
		SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		std::cerr << "Error creating SDL window: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	// create renderer
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	// Seed the random number generator
	srand(static_cast<unsigned int>(time(0)));


	while (true)
	{

		// clear screen
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		// set draw color for the square (white)
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		// define the square (x,   y,  w,   h)
		SDL_Rect square = { 350, 250, 100, 100 };

		// draw the square
		SDL_RenderDrawRect(renderer, &square);

		// show the screen
		SDL_RenderPresent(renderer);


		// clear screen
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);


		// draw random lines
		for (int i = 0; i < 400; ++i) // Adjust the number of lines as needed
		{
			// Generate random start and end points
			int x1 = rand() % 800;
			int y1 = rand() % 600;
			int x2 = rand() % 800;
			int y2 = rand() % 600;

			// Generate random color
			Uint8 r = rand() % 256;
			Uint8 g = rand() % 256;
			Uint8 b = rand() % 256;

			SDL_SetRenderDrawColor(renderer, r, g, b, 255);
			SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
		}

		// Show the screen
		SDL_RenderPresent(renderer);

		// Delay to control the frame rate
		SDL_Delay(100);
	}

	// Cleanup
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}



