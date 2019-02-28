#include "pch.h"
#include "Cell.h"


Cell::Cell()
{
}


Cell::~Cell()
{
}

void Cell::setCell(bool wallVal[4], int tempX,int tempY,int tempRotation)
{
	int size = 0;
	x = tempX;
	y = tempY;
	rotation = tempRotation;
	for (int k = 0; k < 4; k++)
	{
		activatedWalls[k] = wallVal[k];
		if (wallVal[k] == true)
			size++;
	}
	walls.resize(size);
	
	for (int k = 0; k < walls.size(); k++)
	{
		walls[k].setRect(x, y, rotation);
	}
}
