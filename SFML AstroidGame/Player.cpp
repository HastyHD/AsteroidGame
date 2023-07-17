#include "Player.h"

Player::Player(sf::Texture* texture, float switchTime, float speed, float jumpHeight)
{
	this->speed = speed;
    this->jumpHeight = jumpHeight;
    this->canJump = canJump;

	faceRight = true;
    

    body.setSize(sf::Vector2f(100.f, 90.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(206, 206);
    body.setTexture(texture);
}

Player::~Player()
{
}

void Player::Update(float DeltaTime)
{
    body.setSize(sf::Vector2f(100.f, 90.0f));
    body.setOrigin(body.getSize() / 2.0f);
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
    {
        body.setSize(sf::Vector2f(100.f, 50.0f));
        body.setOrigin(body.getSize() / 2.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        body.setPosition(206, 340);
        

    
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
        velocity.y -= 17.0f/60.0f;
    }
    else if (direction.x > 0.0f)
    {
        //collision on the right
        velocity.x = 0.0f;
        velocity.y -= 17.0f/60.0f;
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
        velocity.x *= 100.0f;
    }
}
