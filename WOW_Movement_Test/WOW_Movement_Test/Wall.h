#pragma once
#include <SFML/Graphics.hpp>
class Wall : public sf::RectangleShape
{
public:
	Wall();
	~Wall();
	void setRect(int, int, int);
	sf::RectangleShape Rect;
private:
	int x, y, rotation;


};

