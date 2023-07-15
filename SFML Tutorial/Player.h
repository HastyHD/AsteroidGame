#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Player
{
  public:
	  Player(sf::Texture* texture, float switchTime, float speed);
	  ~Player();

	  void Update(float DeltaTime);
	  void Draw(sf::RenderWindow& window);

private:
	sf::RectangleShape body;
	float speed;
	bool faceRight;

};
