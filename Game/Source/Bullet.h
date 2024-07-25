#pragma once
#include "Actor.h"
class Bullet : public Actor
{
public:
	Bullet() = default;

	virtual void OnCollision(Actor* actor);
private:
	float m_speed = 0;
};

