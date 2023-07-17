#include "Player.h"

Player::Player(sf::Texture* texture, float switchTime, float speed, float jumpHeight)
{
	this->speed = speed;
    this->jumpHeight = jumpHeight;

	faceRight = true;

    body.setSize(sf::Vector2f(100.f, 100.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(206, 206);
    body.setTexture(texture);
}

Player::~Player()
{
}

void Player::Update(float DeltaTime)
{
    velocity.x *= 0.5f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        velocity.x -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        velocity.x += speed;
  
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
    {
        canJump = false;
        velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
    }

    velocity.y += 981.0f * DeltaTime;
        
    //Animation movement

    body.move(velocity * DeltaTime);
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction)
{
    if (direction.x < 0.0f)
    {
        //collision on the left
        velocity.x = 0.0f;
    }
    else if (direction.x > 0.0f)
    {
        //collision on the right
        velocity.x = 0.0f;
    }
    else if (direction.y < 0.0f)
    {
        //collision on the bottom
        velocity.y = 0.0f;
        canJump = true;
    }
    else if (direction.y > 0.0f)
    {
        //collision on the top
        velocity.y = 0.0f;
    }
}
