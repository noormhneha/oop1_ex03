#pragma once
// Amr shwiki , 212443485
// Anas dweik , 32236013

#include "Icon.h"

#include <iostream>

class Key : public Icon
{
public:
	// pacman c-tor
	Key(Toolbar_t color) { m_color = color, m_shape = KEY; }

	// draw pacman icon
	void draw(sf::RenderWindow& window, sf::Vector2f pos, sf::Sprite sprite)
	{
		sprite.setPosition(pos);
		window.draw(sprite);
	}


private:

};