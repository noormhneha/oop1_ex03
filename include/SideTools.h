#pragma once
#include <SFML\Graphics.hpp>
#include "Utilities.h"


enum IconsBar { MOUSE, CAT, CHEESE, WALL, KEY, DOOR, GIFT, SAVE, ERASE, RESET, NON};

const int NUM_OF_ICONS = 10; // number of icons
const unsigned int P_SIZE = 40; // pixel size

class SideTools
{
public:
	SideTools();

	void setToolbar();
	void drawToolbar(sf::RenderWindow& window);

	IconsBar getNameOfIcon(sf::Vector2f);
	IconsBar getIcon(sf::Vector2f, Buttons&);

	sf::Sprite getIconSprite(int) const;
private:
	sf::Vector2f m_positions[NUM_OF_ICONS];
	sf::Texture m_pTexture[NUM_OF_ICONS];
	sf::Sprite m_sprite[NUM_OF_ICONS];
};
