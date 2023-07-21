#pragma once
#include "Actor.h"

class Projectile : public Actor
{
public:
	Projectile(class Game* game);
	void UpdateActor(float deltaTime) override;
	void ProcessKeyboard(const uint8_t* state);
	float GetSpeed() const { return mSpeed; }	

private:
	float mSpeed;
};