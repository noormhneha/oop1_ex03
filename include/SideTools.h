#pragma once

#include <SFML/Graphics.hpp> // Include SFML graphics library
#include "Utilities.h"

// Enumeration representing different icons on the toolbar
enum IconsBar { MOUSE, CAT, CHEESE, WALL, KEY, DOOR, GIFT, SAVE, ERASE, RESET, BACKGROUND, NON };

const int NUM_OF_ICONS = 11; // Number of icons
const unsigned int P_SIZE = 40; // Pixel size for icons

class SideTools {
public:
    // Constructor
    SideTools();

    // Method to set up the toolbar
    void setToolbar();

    // Method to draw the toolbar on the window
    void drawToolbar(sf::RenderWindow& window);

    // Methods to get the name and icon based on a given position
    IconsBar getNameOfIcon(sf::Vector2f);
    IconsBar getIcon(sf::Vector2f);

    // Method to get the sprite of an icon
    sf::Sprite getIconSprite(int) const;

private:
    sf::Vector2f m_positions[NUM_OF_ICONS]; // Array of positions for icons
    sf::Texture m_pTexture[NUM_OF_ICONS]; // Array of textures for icons
    sf::Sprite m_sprite[NUM_OF_ICONS]; // Array of sprites for icons
};
