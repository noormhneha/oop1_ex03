#include "Icon.h"

void Icon::draw(sf::RenderWindow& window, sf::Vector2f pos, sf::Sprite sprite) {
	sprite.setPosition(pos);
	window.draw(sprite);
}

sf::Vector2f Icon::getIconPressed(const sf::Event& pressedEvent) const {
	return { pressedEvent.mouseButton.x , pressedEvent.mouseButton.y };
}

IconsBar Icon::getShape() const{
	return m_shape;
}