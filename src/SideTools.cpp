#include "SideTools.h"
#include <iostream>
#include <fstream>

// Constructor to initialize toolbar positions
SideTools::SideTools() {
    for (size_t i = 0; i < NUM_OF_ICONS; i++) {
        m_positions[i] = sf::Vector2f(0, i * (float)P_SIZE);
    }
}

// Set up the toolbar by reading icon names from a file
void SideTools::setToolbar() {
    std::ifstream inputFile("Names.txt");

    // Check if the file is successfully opened
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file 'Names.txt'" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    int i = 0;

    // Read and load each line as a texture for the icons
    while (std::getline(inputFile, line)) {
        m_pTexture[IconsBar(i)].loadFromFile(line);
        m_sprite[i].setTexture(m_pTexture[i]);

        // Scale the sprite to fit the toolbar size
        m_sprite[i].setScale(sf::Vector2f(((float)P_SIZE / m_sprite[i].getGlobalBounds().width),
                                          ((float)P_SIZE / m_sprite[i].getGlobalBounds().height)));
        // Position the sprite on the toolbar
        m_sprite[i].setPosition(m_positions[i]);
        i++;
    }
    // Close the file
    inputFile.close();
}

// Draw the toolbar on the window
void SideTools::drawToolbar(sf::RenderWindow& window) {
    for (size_t i = 0; i < NUM_OF_ICONS; i++) {
        window.draw(m_sprite[i]);
    }
}

// Helper function to get the name of an icon based on its position
IconsBar SideTools::getNameOfIcon(sf::Vector2f vec) {
    for (size_t i = 0; i < NUM_OF_ICONS; i++) {
        if (m_positions[i] == vec)
            return (IconsBar)i;
    }
    return (IconsBar)0;
}

// Get the icon based on its position
IconsBar SideTools::getIcon(sf::Vector2f pos) {
    return getNameOfIcon(pos);
}

// Get the sprite of a specific icon
sf::Sprite SideTools::getIconSprite(int i) const {
    return m_sprite[i];
}
