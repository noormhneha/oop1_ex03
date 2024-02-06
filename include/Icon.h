#pragma once

#include "SideTools.h"

class Icon {
public:
	Icon() = default;

	void draw(sf::RenderWindow&, sf::Vector2f, sf::Sprite);
	sf::Vector2f getIconPressed(const sf::Event&) const;
	IconsBar getShape() const;
	
protected:
	IconsBar m_shape;
};