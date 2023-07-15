#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collision.h"

class Player
{
  public:
	  Player(sf::Texture* texture, float switchTime, float speed);
	  ~Player();

	  void Update(float DeltaTime);
	  void Draw(sf::RenderWindow& window);

	  sf::Vector2f GetPosition() { return body.getPosition(); }
	  Collision GetCollision() { return Collision(body); }

private:
	sf::RectangleShape body;
	float speed;
	bool faceRight;

};

