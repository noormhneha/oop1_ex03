#include "Icon.h"

void Icon::draw(sf::RenderWindow& window, sf::Vector2f pos, sf::Sprite sprite) {
	sprite.setPosition(pos);
	window.draw(sprite);
}

IconsBar Icon::getShape() const{
	return m_shape;
}