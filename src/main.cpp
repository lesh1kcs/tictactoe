#include <SFML/Graphics.hpp>
#include "scenes/menu.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Tic-Tac-Toe");

    while (window.isOpen()) { // while the window is open
        // check for events
        while (const std::optional event = window.pollEvent())
        {
            // Exit if the window is closed
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.display();
    }
}
