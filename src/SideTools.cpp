#include "SideTools.h"

SideTools::SideTools()
{
	for (size_t i = 0; i < NUM_OF_ICONS; i++)
		m_positions[i] = sf::Vector2f(0, i * (float)P_SIZE);
}

void SideTools::setToolbar()
{
}

void SideTools::drawToolbar(sf::RenderWindow& window)
{
	for (size_t i = 0; i < NUM_OF_ICONS; i++)
		window.draw(m_sprite[i]);
}
