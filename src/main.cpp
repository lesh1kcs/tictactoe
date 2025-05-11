#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include "objects/board.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800u, 600u)), "SFML Board");

    Board board(3, 3);
    board.setCell(1, 1, 'X');

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        board.render(window);
        window.display();
    }

    return 0;
}
