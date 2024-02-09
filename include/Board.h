#pragma once

#include <SFML/Graphics.hpp>

#include "Icon.h"
#include "Utilities.h"
#include "SideTools.h"

class Board : public Utilities {
public:
	Board();

	Location getLocation() const;

	void buttonReleased(sf::Event event, sf::RenderWindow& window);

	void draw(sf::RenderWindow&);
	char convertIconToChar(const IconsBar&) const;
	IconsBar convertCharToIcon(char) const;
private:
	void checkIconValidation(sf::Vector2i);
	void saveRestart();
	void saveToFile();
	void resetMap();
	void deleteObject(sf::Vector2i);

	Icon m_icon; 
	IconsBar m_iconShape; // new shape
	char m_nextChar;

	SideTools m_sideTools;
};