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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            {
                player.move(-1.f, 0.f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            {
                player.move(1.f, 0.f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            {
                player.move(0.f, -1.f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
                player.move(0.0f, 1.f);
            }
           
        }

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}