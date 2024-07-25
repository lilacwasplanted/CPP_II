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
#include "GameData.h"
#include "SpaceGame.h"
#include <fmod.hpp>
using namespace std;


int main(int argc, char* argv[])
{
	g_engine.Initialize();
	SpaceGame* game = new SpaceGame(&g_engine);
	game->Initialize();

	g_engine.GetAudio()->AddSound("bass.wav");
	g_engine.GetAudio()->AddSound("snare.wav");
	g_engine.GetAudio()->AddSound("open-hat.wav");

	while (!g_engine.IsQuit()) {

		g_engine.Update();
		game->Update(g_engine.GetTime().GetDeltaTime());

		g_engine.GetRenderer().SetColor(0, 0, 0, 0);
		g_engine.GetRenderer().BeginFrame();

		game->Draw(g_engine.GetRenderer());

		g_engine.GetRenderer().EndFrame();

		//g_engine.GetInput()->Update();


		
		if (g_engine.GetInput()->GetKeyDown(SDL_SCANCODE_Q) && !g_engine.GetInput()->GetPrevKeyDown(SDL_SCANCODE_Q)) {
			g_engine.GetAudio()->PlaySound("bass.wav");
		}
		if (g_engine.GetInput()->GetKeyDown(SDL_SCANCODE_W) && !g_engine.GetInput()->GetPrevKeyDown(SDL_SCANCODE_W)) {
			g_engine.GetAudio()->PlaySound("snare.wav");
		}
		if (g_engine.GetInput()->GetKeyDown(SDL_SCANCODE_E) && !g_engine.GetInput()->GetPrevKeyDown(SDL_SCANCODE_E)) {
			g_engine.GetAudio()->PlaySound("open-hat.wav");
		}

	}
	return 0;
}

/*
	FMOD::System* audio;
	FMOD::System_Create(&audio);
	void* extradiverdata = nullptr;
	audio->init(32, FMOD_INIT_NORMAL, extradiverdata);


	FMOD::Sound* sound = nullptr;
	audio->createSound("test.wav", FMOD_DEFAULT, 0, &sound);

	audio->playSound(sound, 0, false, nullptr);

	//// Seed the random number generator
	vector<Vector2> points;
	vector<Particle> particles;
float offset = 0;

	
	bool quit = false;
	while (!g_engine.IsQuit())

	{
	

		//Input

		float thrust 

		//Update
		Vector2 mousePos = g_engine.GetInput()->GetMousePos();
		if (g_engine.GetInput()->GetMouseButtonDown(0)) {
			
			particles.push_back(Particle{mousePos, {randomOnUnitCircle() * randomf(100,200), randomf(-300,300)}, random() % 6 });
		}
		//Update
		scene->Update(g_engine.GetTime().GetDeltaTime())

		cout << "Mouse Position: (" << mousePos.x << ", " << mousePos.y << " )" << endl;
		
		if (g_engine.GetInput()->GetMouseButtonDown(0) && !input.GetPrevMouseButtonDown(0)){
			cout << "Mouse Pressed\n";
			points.push_back(mousePos);
		}
		if (g_engine.GetInput()->GetMouseButtonDown(0) && input.GetPrevMouseButtonDown(0)) {
			float distance = (points.back() - mousePos).Length();
			if (distance > 5) {points.push_back(mousePos);}
		}
		
		for (Particle& particle : particles) {
			particle.Update(g_engine.GetTime());
			if (particle.position.x > 800) particle.position.x = 0;
			if (particle.position.x < 0) particle.position.x = 800;
		}

		// Draw
		// clear screen
 // comment this out to have it draw a

		g_engine.GetRenderer()->SetColor(255, 255, 255, 0);
		float radius = 250;
		offset += (2 * time.GetDeltaTime());
		for (float angle = 0; angle < 360; angle += 360 / 30) {
			float x = Math::Cos(Math::DegToRad(angle + offset)) * Math::Sin((offset + angle) * 0.1f) * radius;
			float y = Math::Sin(Math::DegToRad(angle + offset)) * Math::Sin((offset + angle) * 0.1f) * radius;
			g_engine.GetRenderer()->SetColor(random(256), random(256), random(256), 0);
			g_engine.GetRenderer()->DrawRect(400 + x, 300 + y, 4.0f, 4.0f);
		}



		//draw particles
		g_engine.GetRenderer()->SetColor(rand() % 256, rand() % 256, rand() % 256, 0);

	for (Particle particle : particles) {
		particle.Draw(*g_engine.GetRenderer());

	}

	g_engine.GetRenderer()->EndFrame();
	}

	return 0;
}
*/