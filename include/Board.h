#pragma once

#include <SFML/Graphics.hpp>

#include "Icon.h"
#include "Utilities.h"
#include "SideTools.h"

class Board {
public:
    // Constructor
    Board();

    // Method to get the location of the board
    Location getLocation() const;

    // Method to handle mouse button release events
    void buttonReleased(sf::Event event, sf::RenderWindow& window);

    // Method to draw the board on the window
    void draw(sf::RenderWindow&);

    // Methods to convert between icon and character representations
    char convertIconToChar(const IconsBar&) const;
    IconsBar convertCharToIcon(char) const;

private:
    // Private methods
    void checkIconValidation(sf::Vector2i);
    void saveRestart();
    void saveToFile();
    void resetMap();
    void deleteObject(sf::Vector2i);
    void setBackground();
    void changeBackground();

    // Private members
    Utilities m_utilities; // Utility class to manage board dimensions and data

    Icon m_icon; // Icon class for drawing icons on the board
    IconsBar m_iconShape; // The current shape of the icon being placed on the board
    char m_nextChar; // The next character to be placed on the board

    SideTools m_sideTools; // SideTools class for managing the toolbar

    sf::Texture m_backgroundTexture; // Texture for the background
    sf::Sprite m_backgroundSprite; // Sprite for the background
    std::string m_background = "Tom&Jerry3.png"; // Path to the background image

    int m_row; // Number of rows on the board
    int m_col; // Number of columns on the board

    Row* m_rows; // Array of rows representing the board

    bool m_thereIsMouse = false; // Flag to indicate if there's already a mouse on the board
    Location m_mouseLocation; // Location of the mouse on the board
};
