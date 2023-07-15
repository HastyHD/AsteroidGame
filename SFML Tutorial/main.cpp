#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(512.0f, 512.0f));
    sf::Texture playerTexture;
    playerTexture.loadFromFile("C:/Users/dylan/OneDrive/Pictures/Screenshot 2023-03-20 150247.png");

    Player player(&playerTexture, 0.3f, 100.0f);

    float deltaTime = 0.0f;
    sf::Clock clock;
    printf("hello");
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
            }

            
        }
        player.Update(deltaTime);
    window.clear(sf::Color(150,150,150));
    window.setView(view);
    player.Draw(window);
    window.display();
    } 
        return 0;
    
}