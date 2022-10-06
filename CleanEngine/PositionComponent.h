#pragma once

#include "Components.h"


class PositionComponent : public Component
{
private:
	int xpos;
	int ypos;

public:
	int x() { return xpos; }
	int y() { return ypos; }

	PositionComponent()
	{
		xpos = 0;
		ypos = 0;
	}

	PositionComponent(int x, int y)
	{
		xpos = x;
		ypos = y;
	}

	void update() override
	{
		xpos++;
		ypos++;
	}

	void setPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
};