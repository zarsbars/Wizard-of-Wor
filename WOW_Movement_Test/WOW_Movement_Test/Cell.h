#pragma once
#include "Wall.h"

class Cell
{
public:
	Cell();
	~Cell();
	void setCell(bool[4],int,int,int);

private:
	int x, y, rotation;
	std::vector <Wall> walls;
	bool activatedWalls[4];
};

