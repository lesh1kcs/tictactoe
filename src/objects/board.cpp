#include "board.hpp"
#include <SFML/Graphics.hpp>

Board::Board(unsigned int rows, unsigned int cols)
    : rows(rows), cols(cols), grid(rows, std::vector<char>(cols, ' ')) {}

void Board::setCell(unsigned int row, unsigned int col, char value) {
    if (row < rows && col < cols) { // Corrected condition
        grid[row][col] = value;
    }
}

char Board::getCell(unsigned int row, unsigned int col) const {
    if (row < rows && col < cols) {
        return grid[row][col];
    }
    return ' ';
}

void Board::render(sf::RenderWindow& window) const {
    const float cellSize = 100.0f;
    const float boardWidth = cols * cellSize;
    const float boardHeight = rows * cellSize;

    // Calculate the offset to center the board
    const float offsetX = (window.getSize().x - boardWidth) / 2.0f;
    const float offsetY = (window.getSize().y - boardHeight) / 2.0f;

    for (unsigned int row = 0; row < rows; ++row) {
        for (unsigned int col = 0; col < cols; ++col) {
            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
            cell.setPosition(sf::Vector2f(col * cellSize + offsetX, row * cellSize + offsetY));
            cell.setFillColor(grid[row][col] == 'X' ? sf::Color::Red : sf::Color::White);
            cell.setOutlineColor(sf::Color::Black);
            cell.setOutlineThickness(1.0f);
            window.draw(cell);
        }
    }
}