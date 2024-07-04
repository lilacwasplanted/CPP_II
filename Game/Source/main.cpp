#include <SDL.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Renderer.h"
#include "Input.h"
#include "Particle.h"
#include "Random.h"
#include "E_Time.h"
using namespace std;

int main(int argc, char* argv[])
{

	Renderer renderer;
	renderer.Initialize();
	renderer.ShutDown();
	renderer.CreateWindow("Game Engine", 800, 600);

	Input input;
	input.Initialize();

	Time time;


	//// Seed the random number generator
	vector<Vector2> points;
/*
	vector<Particle> particles;
	for (int i = 0; i < 0; i++)
	{
		particles.push_back(Particle{ {rand() % 800, rand() % 800}, {randomf(100,300),0.0f} });
	}
*/
	bool quit = false;
	while (!quit)

	{
		time.Tick();

		//Input
		input.Update();
		if (input.GetKeyDown(SDL_SCANCODE_ESCAPE))
		{
			quit = true;

		}

		//Update
		Vector2 mousePos = input.GetMousePos();
		//if (input.GetMouseButtonDown(0)) {
		//	particles.push_back(Particle{ mousePos, { randomf(-300,300), randomf(-300,300) } });
		//}

		
		cout << mousePos.x << " " << mousePos.y <<endl;
		if (input.GetMouseButtonDown(0) && !input.GetPrevMouseButtonDown(0))
		{
			cout << "Mouse Pressed\n";
			points.push_back(mousePos);
		}
		if (input.GetMouseButtonDown(0) && input.GetPrevMouseButtonDown(0)) {
			float distance = (points.back() - mousePos).Length();
			if (distance > 5) {points.push_back(mousePos);}
		}
		
		//for (Particle& particle : particles) {
		//	particle.Update(time.GetDeltaTime());
		//	if (particle.position.x > 800) particle.position.x = 0;
		//	if (particle.position.x < 0) particle.position.x = 800;
		//}

		// Draw
		// clear screen
		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();

		//draw line
		renderer.SetColor(255, 255, 255, 0);
	//for (Particle particle : particles) {
	//	particle.Draw(renderer);
	//}
		for (int i = 0; points.size() > 10 && i < points.size() - 1; i++) {
			renderer.SetColor(rand() % 256, rand() % 256, rand() % 256, 0);
			renderer.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
		}

	renderer.EndFrame();

	}

	renderer.ShutDown();
	SDL_Quit();
	return 0;
}






