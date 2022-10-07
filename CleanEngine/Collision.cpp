#include "Collision.h"
#include "CollisionComponent.h"

bool Collision::AABB(const SDL_Rect& recA, const SDL_Rect& recB)
{
	if (
		recA.x + recA.w >= recB.x &&
		recB.x + recB.w >= recA.x &&
		recA.y + recA.h >= recB.y &&
		recB.y + recB.h >= recA.y
		)
	{
		return true;
	}

	return false;
}

bool Collision::AABB(const CollisionComponent& colA, const CollisionComponent& colB)
{
	if (AABB(colA.collision, colB.collision))
	{
		std::cout << colA.tag << " Hit: " << colB.tag << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}