#pragma once

#include "GameTools.h"


class Icon {
public:
	void draw(sf::RenderWindow&, sf::Vector2f, sf::Sprite);
	Toolbar_t getShape();
	
protected:
	Toolbar_t m_shape;
	Toolbar_t m_color;
};