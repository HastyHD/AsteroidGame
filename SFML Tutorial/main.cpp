#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
    sf::CircleShape shape(100.f);
    sf::RectangleShape player(sf::Vector2f(100.f, 100.f));
    player.setFillColor(sf::Color::Red);
    shape.setFillColor(sf::Color::Green);

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
            case sf::Event::Resized:

                //std::cout << "New window width:" << event.size.width << " New window height:" << event.size.height << std::endl;
                printf("New window width: %i\nNew window height: %i\n", event.size.width, event.size.height);
                break;
            case sf::Event::TextEntered:
            {
                if (event.text.unicode < 128)

                    printf("%c", event.text.unicode);


            }
            case sf::Event::KeyPressed:
            {
                if (event.key.code == sf::Keyboard::Enter)

                    printf("\n");
                if (event.key.code == sf::Keyboard::Delete)
                    window.close();
            }
            }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                player.setPosition((float)mousePosition.x-50.f,static_cast<float>(mousePosition.y-50.f));
            }
           
        }

        window.clear();
        window.draw(player);
   
        window.display();
    }

    return 0;
}