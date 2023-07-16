#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Obstacle.h"

static const float VIEW_HEIGHT = 512.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
    sf::View view(sf::Vector2f(200.0f, 100.0f), sf::Vector2f(512.0f, 512.0f));
    sf::Texture playerTexture;
    playerTexture.loadFromFile("C:/Users/dylan/OneDrive/Pictures/Screenshot 2023-03-20 150247.png");

    Player player(&playerTexture, 0.3f, 100.0f);

    Obstacle obstacle1(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));
    Obstacle obstacle2(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));


    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
       
  
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                ResizeView(window, view);
                break;
            }

            
        }
    
    player.Update(deltaTime);

    obstacle1.GetCollision().CheckCollision(player.GetCollision(), 0.0f);
    obstacle2.GetCollision().CheckCollision(player.GetCollision(), 1.0f);

    //view.setCenter(player.GetPosition());
    
    
    window.clear(sf::Color(150,150,150));
    window.setView(view);
    player.Draw(window);
    obstacle1.Draw(window);
    obstacle2.Draw(window);
    window.display();
    } 
        return 0;
    
}