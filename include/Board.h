#pragma once

#include <SFML/Graphics.hpp>

#include "Icon.h"
#include "Utilities.h"
#include "SideTools.h"

class Board {
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
	void setBackground();
	void changeBackground();

    Utilities m_utilities;

	Icon m_icon; 
	IconsBar m_iconShape; // new shape
	char m_nextChar;

	SideTools m_sideTools;

	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;
    std::string m_background = "Tom&Jerry3.png";

    int m_row;
    int m_col;

    Row* m_rows;

    bool m_thereIsMouse = false;
    Location m_mouseLocation;
};