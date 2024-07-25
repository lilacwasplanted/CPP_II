#include "Player.h"
#include "Engine.h"
#include <iostream>

void Player::Update(float dt) {

	float thrust = 0;

	if (g_engine.GetInput()->GetKeyDown(SDL_SCANCODE_UP)) thrust = 400;
	if (g_engine.GetInput()->GetKeyDown(SDL_SCANCODE_DOWN))  thrust = -400;

	//if(g_engine.GetInput()->GetKeyDown(SDL_SCANCODE_LEFT)) transform -= Math::
	//if(g_engine.GetInput()->GetKeyDown(SDL_SCANCODE_RIGHT))
}

void Player::OnCollision(Actor* actor)
{
	if (actor->GetTag() == "Enemy") {
		std::cout << "collision\n";
		m_destroyed = true;

	}
	if (actor->GetTag() == "Health") {}
}