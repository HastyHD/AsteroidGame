#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
    sf::CircleShape shape(100.f);
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

            }
           
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}