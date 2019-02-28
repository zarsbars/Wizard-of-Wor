
#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Wall.h"
#include <vector>


bool boundCheck(sf::RectangleShape, std::vector <Wall>, double,double);

int main()
{
	double speed = .2;
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::RectangleShape player(sf::Vector2f(40, 40));
	//sf::RectangleShape wall(sf::Vector2f(100, 400));
	player.setPosition(220, 220);
	std::vector <Wall> walls;
	walls.resize(4);
	for (int x = 0; x < 4;x++)
	{
		walls[x].setRect(200,200,x);
	}
	//wall.setPosition(sf::Vector2f(window.getSize().x / 2 - wall.getSize().x / 2, window.getSize().y / 2 - wall.getSize().y / 2));

	player.setFillColor(sf::Color::Red);
	//wall.setFillColor(sf::Color::Blue);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			//if (event.type == sf::Event::KeyPressed)
			//{
			//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !boundCheck(player,wall,0,-speed))
			//		player.setPosition(sf::Vector2f(player.getPosition().x, player.getPosition().y - speed));
			//
			//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !boundCheck(player, wall, 0, speed))
			//		player.setPosition(sf::Vector2f(player.getPosition().x, player.getPosition().y + speed));

			//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !boundCheck(player, wall, -speed, 0))
			//		player.setPosition(sf::Vector2f(player.getPosition().x - speed, player.getPosition().y));

			//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !boundCheck(player, wall, speed, 0))
			//		player.setPosition(sf::Vector2f(player.getPosition().x + speed, player.getPosition().y));
			//}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !boundCheck(player, walls, 0, -speed))
			player.setPosition(sf::Vector2f(player.getPosition().x, player.getPosition().y - speed));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !boundCheck(player, walls, 0, speed))
			player.setPosition(sf::Vector2f(player.getPosition().x, player.getPosition().y + speed));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !boundCheck(player, walls, -speed, 0))
			player.setPosition(sf::Vector2f(player.getPosition().x - speed, player.getPosition().y));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !boundCheck(player, walls, speed, 0))
			player.setPosition(sf::Vector2f(player.getPosition().x + speed, player.getPosition().y));

		window.clear();
		window.draw(player);
		//window.draw(wall);
		for (int k = 0; k < walls.size(); k++)
		{
			window.draw(walls[k].Rect);
		}
		window.display();
	}

	return 0;
}

bool boundCheck(sf::RectangleShape player , std::vector <Wall> walls, double x , double y )
{
	bool isWall = false;

	player.setPosition(sf::Vector2f(player.getPosition().x + x, player.getPosition().y + y));
	
	for (int x1 = 0; x1 < walls.size(); x1++)
	{
		if (player.getGlobalBounds().intersects(walls[x1].Rect.getGlobalBounds()))
		{
			isWall = true;
			break;
		}
	}

	return isWall;
}