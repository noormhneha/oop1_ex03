
#include "Icon.h"

void Icon::draw(sf::RenderWindow& window, sf::Vector2f pos, sf::Sprite sprite) {
	sprite.setPosition(pos);
	window.draw(sprite);
}

Toolbar_t Icon::getShape() {
	return m_shape;
}