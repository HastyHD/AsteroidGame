#include "Collision.h"

Collision::Collision(sf::RectangleShape& body) :
body(body)
{

}

Collision::~Collision()
{
}

bool Collision::CheckCollision(Collision  other, float push)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	float intersectionX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectionY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectionX < 0.0f && intersectionY < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersectionX > intersectionY)
		{
			if (deltaX > 0.0f)
			{
				Move(intersectionX * (1.0f - push), 0.0f);
				other.Move(-intersectionX * push, 0.0f);
			}
			else
			{
				
					Move(-intersectionX * (1.0f - push), 0.0f);
					other.Move(intersectionX * push, 0.0f);
			}

			}
		}   

		
		else
		{
		 	if (deltaY > 0.0f)
			{
				Move(0.0f,intersectionY * (1.0f - push));
				other.Move(0.0f,-intersectionY * push);
			}
			else
			{
				
				Move(0.0f,-intersectionY * (1.0f - push));
				other.Move(0.0f,intersectionY * push);
			}
		return true;
	}

	return false;
}
