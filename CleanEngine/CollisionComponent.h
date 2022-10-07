#pragma once

#include <string>
#include "SDL.H"
#include "Components.h"

class CollisionComponent : public Component
{
public:

	SDL_Rect collision;
	std::string tag;

	TransformComponent* transform;

	CollisionComponent(std::string t)
	{
		tag = t;
	}

	void init() override
	{
		if (!entity->hasComponent<TransformComponent>())
		{
			entity->hasComponent<TransformComponent>();
		}
		transform = &entity->getComponent<TransformComponent>();

		Game::collisions.push_back(this);
	}

	void update() override
	{
		collision.x = static_cast<int>(transform->position.x);
		collision.y = static_cast<int>(transform->position.y);
		collision.w = transform->width * transform->scale;
		collision.h = transform->height * transform->scale;
	}
};