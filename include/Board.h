#pragma once

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "Icon.h"
#include "Row.h"
#include "Utilities.h"
#include "SideTools.h"

// Symbols 
const char MOUSE_CH = '%';
const char CAT_CH = '^';
const char DOOR_CH = 'D';
const char WALL_CH = '#';
const char KEY_CH = 'F';
const char CHEESE_CH = '*';
const char GIFT_CH = '$';
const char ROAD_CH = ' ';


class Board {
public:
	Board();

	Location getLocation() const;

	void buttonReleased(sf::Event event, sf::RenderWindow& window);

	void draw(sf::RenderWindow&);
	char convertIconToChar(const IconsBar&) const;
	IconsBar convertCharToIcon(char) const;


	
private:
	void readData();
	void readFromFile();
	void readFromUser();
	void fillData();

	void checkIconValidation(char, sf::Vector2i);
	void saveDeleteRestart(sf::Vector2i);
	void saveToFile();
	void resetMap();
	void deleteObject(sf::Vector2i);

	int m_row;
	int m_col;
	Row* m_rows;

	std::fstream m_file;

	SideTools m_sideTools;

	Icon m_icon; 
	IconsBar m_iconShape; // new shape
	char m_nextChar;

	Buttons m_buttons;
	Location m_mouseLocation;

	//Icon getIcon() const;
};