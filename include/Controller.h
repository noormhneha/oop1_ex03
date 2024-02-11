#pragma once

#include <thread>
#include "Board.h"

class Controller {
public:
    // Constructor
    Controller();

private:
    // Private method to open the window and handle events
    void openWindow();

    Board m_board; // Instance of the Board class to manage the game board
    sf::RenderWindow m_window; // SFML RenderWindow for displaying the game window
};
