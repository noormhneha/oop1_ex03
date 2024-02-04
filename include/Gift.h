#pragma once
// Amr shwiki , 212443485
// Anas dweik , 32236013

#include "Icon.h"

#include <iostream>

class Gift : public Icon
{
public:
	// pacman c-tor
	Gift(Toolbar_t color) { m_color = color, m_shape = GIFT; }

	// draw pacman icon
	void draw(sf::RenderWindow& window, sf::Vector2f pos, sf::Sprite sprite)
	{
		sprite.setPosition(pos);
		window.draw(sprite);
	}


private:

};