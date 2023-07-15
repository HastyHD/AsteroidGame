#include "Player.h"

Player::Player(sf::Texture* texture, float switchTime, float speed)
{
	this->speed = speed;

	faceRight = true;

    body.setSize(sf::Vector2f(100.f, 100.f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(206, 206);
    body.setTexture(texture);
}

Player::~Player()
{
}

void Player::Update(float DeltaTime)
{
    sf::Vector2f movement(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        movement.x -= speed * DeltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movement.x += speed * DeltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        movement.y -= speed * DeltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        movement.y += speed * DeltaTime;

    //Animation movement

    body.move(movement);
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}
