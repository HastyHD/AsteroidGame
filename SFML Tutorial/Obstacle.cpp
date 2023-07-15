#include "Obstacle.h"


Obstacle::Obstacle(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	body.setTexture(texture);
	body.setOrigin(size / 2.0f);
	body.setSize(size);
	body.setPosition(position);
}

Obstacle::~Obstacle()
{
}

void Obstacle::Update(float DeltaTime)
{
}

void Obstacle::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
