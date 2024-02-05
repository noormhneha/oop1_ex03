#pragma once

#include <SFML/Graphics.hpp>

#include "SideTools.h"
#include <iostream>


// Symbols 
//const char MOUSE = '%';
//const char CAT = '^';
//const char DOOR = 'D';
//const char WALL = '#';
//const char KEY = 'F';
//const char CHEESE = '*';
//const char GIFT = '$';
//const char ROAD = ' ';

class Board {
public:
	Board(sf::RenderWindow&);
	
private:
	SideTools m_sideTools;
	IconsBar m_icons; // shape

};