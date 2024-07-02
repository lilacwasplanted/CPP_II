#include <SDL.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../Engine/Renderer.h"
using namespace std;

int main(int argc, char* argv[])
{

	Renderer renderer;
	renderer.Initialize();
	renderer.ShutDown();
	renderer.CreateWindow("Game Engine", );



	//// Seed the random number generator
	//srand(static_cast<unsigned int>(time(0)));
	vector<Vector2> points;
	for (size_t i = 0; i < length; i++)
	{
		points.push_back(Vector2{ rand() % 800, rand() % 600 });
	}

	while (true)
	{	


		//Input
		 

		//Update
		Vector2 speed{ 0.1f,-0.1f };
		for (Vector2& point : points)
		{
			point = point.Add(Vector2{ 0.1f,-0.1f });
		}
		// Draw
		// clear screen
		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();
		
		//draw line
		renderer.SetColor(255, 255, 255, 0);
		renderer.DrawLine(300, 400, 400, 300);
		renderer.DrawLine(400, 300, 500, 400);
		renderer.DrawLine(500, 400, 300, 400);
		renderer.DrawLine(v1.x, v1.y, v2.x, v2.y);

	


		//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		//SDL_RenderClear(renderer);

		//// set draw color for the square (white)
		//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		//// define the square (x,   y,  w,   h)
		//SDL_Rect square = { 350, 250, 100, 100 };

		//// draw the square
		//SDL_RenderDrawRect(renderer, &square);

		//// show the screen
		//SDL_RenderPresent(renderer);


		//// clear screen
		//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		//SDL_RenderClear(renderer);


		//// draw random lines
		//for (int i = 0; i < 400; ++i) // Adjust the number of lines as needed
		//{
		//	// Generate random start and end points
		//	int x1 = rand() % 800;
		//	int y1 = rand() % 600;
		//	int x2 = rand() % 800;
		//	int y2 = rand() % 600;

		//	// Generate random color
		//	Uint8 r = rand() % 256;
		//	Uint8 g = rand() % 256;
		//	Uint8 b = rand() % 256;

		//	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
		//	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
		}

		//// Show the screen
		//SDL_RenderPresent(renderer);

		//// Delay to control the frame rate
		//SDL_Delay(100);
	renderer.EndFrame();
	}

	// Cleanup
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}



