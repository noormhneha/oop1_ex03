#pragma once

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "SideTools.h"
#include "Icon.h"
#include "Row.h"


// Symbols 
const char MOUSE_CH = '%';
const char CAT_CH = '^';
const char DOOR_CH = 'D';
const char WALL_CH = '#';
const char KEY_CH = 'F';
const char CHEESE_CH = '*';
const char GIFT_CH = '$';
const char ROAD_CH = ' ';

struct Location {
	int _row;
	int _col;
};

class Board {
public:
	Board();

	Location getLocation() const;

	void buttonReleased(sf::Event event, sf::RenderWindow& window);

	void draw(sf::RenderWindow&);
	char convertIconToChar(const IconsBar&);
	
private:
	void readData();
	void readFromFile();
	void readFromUser();
	void fillData();


	int m_row;
	int m_col;
	Row* m_rows;

	std::fstream m_file;

	SideTools m_sideTools;

	IconsBar m_iconShape; // new shape
	char m_nextChar;

	bool m_save = false;
	bool m_delete = false;
	bool m_restart = false;
	

};