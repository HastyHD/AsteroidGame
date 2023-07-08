#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape player(sf::Vector2f(100.f, 100.f));
    player.setPosition(206, 206);
    sf::Texture playerTexture;
    playerTexture.loadFromFile("C:/Users/dylan/OneDrive/Pictures/Screenshot 2023-03-20 150247.png");
    player.setTexture(&playerTexture);

    while (window.isOpen())
    {
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

    window.clear();
    window.draw(player);
    window.display();
    }
        return 0;
    
}