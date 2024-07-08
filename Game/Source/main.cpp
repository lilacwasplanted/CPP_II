#include <SDL.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Renderer.h"
#include "Input.h"
#include "Particle.h"
#include "Random.h"
#include "E_Time.h"
#include "MathUtils.h"

using namespace std;


int main(int argc, char* argv[])
{

	Math::Abs<int>(-10);
	Math::Abs<float>(-12.0f);
	Math::Abs<double>(-12.0);

	Renderer renderer;
	renderer.Initialize();
	renderer.ShutDown();
	renderer.CreateWindow("Game Engine", 800, 600);

	Input input;
	input.Initialize();

	Time time;


	//// Seed the random number generator
	vector<Vector2> points;
	vector<Particle> particles;

	//for (int i = 0; i < 0; i++)
	//{
	//	particles.push_back(Particle{ {rand() % 800, rand() % 800}, {randomf(100,300),0.0f} });
	//	}
	float offset = 0;
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
		if (input.GetMouseButtonDown(0)) {
			
			particles.push_back(Particle{ mousePos, {randomOnUnitCircle() * randomf(100,200), randomf(-300,300)}, random() % 6 });
		}
		
		cout << "Mouse Position: (" << mousePos.x << ", " << mousePos.y << " )" << endl;
		
		if (input.GetMouseButtonDown(0) && !input.GetPrevMouseButtonDown(0)){
			cout << "Mouse Pressed\n";
			points.push_back(mousePos);
		}
		if (input.GetMouseButtonDown(0) && input.GetPrevMouseButtonDown(0)) {
			float distance = (points.back() - mousePos).Length();
			if (distance > 5) {points.push_back(mousePos);}
		}
		
		for (Particle& particle : particles) {
			particle.Update(time.GetDeltaTime());
			if (particle.position.x > 800) particle.position.x = 0;
			if (particle.position.x < 0) particle.position.x = 800;
		}

		// Draw
		// clear screen
		renderer.SetColor(0,0,0, 0);
		renderer.BeginFrame(); // comment this out to have it draw a

		renderer.SetColor(255, 255, 255, 0);
		float radius = 250;
		offset += (2 * time.GetDeltaTime());
		for (float angle = 0; angle < 360; angle += 360 / 30) {
			float x = Math::Cos(Math::DegToRad(angle + offset)) * Math::Sin((offset + angle) * 0.1f) * radius;
			float y = Math::Sin(Math::DegToRad(angle + offset)) * Math::Sin((offset + angle) * 0.1f) * radius;
			renderer.SetColor(random(256), random(256), random(256), 0);
			renderer.DrawRect(400 + x, 300 + y, 4.0f, 4.0f);
		}



		//draw particles
		renderer.SetColor(rand() % 256, rand() % 256, rand() % 256, 0);

	for (Particle particle : particles) {
		particle.Draw(renderer);

	}

	renderer.EndFrame();
	}

	renderer.ShutDown();
	SDL_Quit();
	return 0;
}