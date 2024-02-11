#pragma once

#include "SideTools.h"

class Icon {
public:
    Icon() = default; // Default constructor

    // Method to draw the icon on the window at a specific position
    void draw(sf::RenderWindow&, sf::Vector2f, sf::Sprite);

    // Method to get the shape of the icon
    IconsBar getShape() const;

protected:
    IconsBar m_shape; // Shape of the icon
};
