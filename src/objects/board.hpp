#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Board {
public:
    Board(unsigned int rows, unsigned int cols);
    void setCell(unsigned int row, unsigned int col, char value);
    char getCell(unsigned int row, unsigned int col) const;
    void render(sf::RenderWindow& window) const;
private:
    unsigned int rows;
    unsigned int cols;
    std::vector<std::vector<char>> grid;
};



#endif //BOARD_HPP
