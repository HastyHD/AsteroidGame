#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"
class Obstacle
{   
public:
	Obstacle(sf::Texture* texture,sf::Vector2f size,sf::Vector2f position);
	~Obstacle();

	
	void Update(float DeltaTime);
	void Draw(sf::RenderWindow& window);
	Collision  GetCollision() { return Collision(body); }

	sf::Vector2f GetPosition() { return body.getPosition(); }

private:

   sf::RectangleShape body;

};

