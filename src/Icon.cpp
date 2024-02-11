#include "Icon.h"

// Draw the icon on the window at the specified position
void Icon::draw(sf::RenderWindow& window, sf::Vector2f pos, sf::Sprite sprite) {
    sprite.setPosition(pos); // Set the position of the sprite
    window.draw(sprite); // Draw the sprite on the window
}

// Get the shape of the icon
IconsBar Icon::getShape() const {
    return m_shape; // Return the shape of the icon
}
