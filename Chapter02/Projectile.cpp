#include "Projectile.h"
#include "AnimSpriteComponent.h"
#include "Game.h"

Projectile::Projectile(Game* game)
	:Actor(game)
	, mSpeed(0.0f)
{
	// Create an animated sprite component
	AnimSpriteComponent* asc = new AnimSpriteComponent(this);
	std::vector<SDL_Texture*> anims = {
		game->GetTexture("Assets/laser.png"),
	};
	asc->SetAnimTextures(anims);
}

void Projectile::UpdateActor(float deltaTime) 
{
	Actor::UpdateActor(deltaTime);
	// Update position based on speeds and delta time
	Vector2 pos = GetPosition();
	pos.x += mSpeed * deltaTime;
	SetPosition(pos);
}

void Projectile::ProcessKeyboard(const uint8_t* state)
{
	mSpeed = 0.0f;

	// space
	if (state[SDL_SCANCODE_SPACE])
	{
		mSpeed += 500.0f;
	}
}