#pragma once
#include "Vector2.h"
#include "Renderer.h"
using namespace std;

struct Particle {
	Vector2 position{0,0};
	Vector2 velocity{0,0};
	float lifespan = 0;

	Particle() = default;
	Particle(Vector2 postion, Vector2 velocity) : 
		position{ position }, 
		velocity{ velocity } 
	{}
	void Update(float dt);
	void Draw(Renderer renderer);

};
