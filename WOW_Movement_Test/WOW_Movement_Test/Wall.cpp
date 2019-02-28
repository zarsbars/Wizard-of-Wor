#include "pch.h"
#include "Wall.h"


Wall::Wall()
{
}


Wall::~Wall()
{
}

void Wall::setRect(int tempX, int tempY, int tempRotation)
{
	x = tempX;
	y = tempY;
	rotation = tempRotation;

	Rect.setSize(sf::Vector2f(10, 200));
	Rect.setOrigin(Rect.getSize().y / 2, Rect.getSize().y / 2);
	Rect.rotate(90 * rotation);
	Rect.setFillColor(sf::Color::Green);
	Rect.setPosition(x, y);
}
