#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collision.h"

class Player
{
  public:
	  Player(sf::Texture* texture, float switchTime, float speed, float jumpHeight);
	  ~Player();

	  void Update(float DeltaTime);
	  void Draw(sf::RenderWindow& window);
	  void OnCollision(sf::Vector2f direction);

	  sf::Vector2f GetPosition() { return body.getPosition(); }
	  Collision GetCollision() { return Collision(body); }

private:
	sf::RectangleShape body;
	float speed;
	bool faceRight;
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
};

