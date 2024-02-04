#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

using std::vector;

// icon names
enum Toolbar_t { MOUSE, CAT, CHEESE, WALL, KEY, DOOR, GIFT, SAVE, ERASE, RESET, NONE };

const int NUM_OF_ICONS = 10; // number of icons
const unsigned int P_SIZE = 40; // pixel size

class SideTools
{
public:
	SideTools();

	void setToolbar();
	void drawToolbar(sf::RenderWindow& window);

private:
	sf::Vector2f m_positions[NUM_OF_ICONS];
	sf::Texture m_pTexture[NUM_OF_ICONS];
	sf::Sprite m_sprite[NUM_OF_ICONS];
};
