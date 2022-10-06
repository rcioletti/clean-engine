#pragma once

#include <string>
#include "SDL.H"
#include "Components.h"

class CollisionComponent : public Component
{
public:

	SDL_Rect colllision;
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
	}

	void update() override
	{
		colllision.x = static_cast<int>(transform->position.x);
		colllision.y = static_cast<int>(transform->position.y);
		colllision.w = transform->width * transform->scale;
		colllision.h = transform->height * transform->scale;
	}
};