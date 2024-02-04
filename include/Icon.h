#pragma once
// Amr shwiki , 212443485
// Anas dweik , 32236013

#include "GameTools.h"


class Icon {
public:
	void draw(sf::RenderWindow&, sf::Vector2f, sf::Sprite);
	Toolbar_t getShape();
	
protected:
	Toolbar_t m_shape;
	Toolbar_t m_color;
};