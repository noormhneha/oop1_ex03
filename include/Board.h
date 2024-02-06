#pragma once

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "SideTools.h"
#include "Icon.h"
#include "Row.h"


// Symbols 
//const char MOUSE = '%';
//const char CAT = '^';
//const char DOOR = 'D';
//const char WALL = '#';
//const char KEY = 'F';
//const char CHEESE = '*';
//const char GIFT = '$';
//const char ROAD = ' ';

struct Location {
	float _row;
	float _col;
};

class Board {
public:
	//Board(sf::RenderWindow&);
	Board();

	Location getLocation() const;
	Location getIconsLocation(const sf::Event&) const;

	void setIcon(IconsBar);

	void draw(sf::RenderWindow&);
	
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
	IconsBar m_iconShapes; // shape
	Icon m_icons;
};