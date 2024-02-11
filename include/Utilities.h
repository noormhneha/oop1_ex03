#pragma once

#include <fstream>
#include <iostream>

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

class Utilities {
public:
	Utilities();
    int getRow() const;
    int getCol() const;
    Row* getData() const;

private:
	void readData();
	void readFromFile();
	void readFromUser();
	void information();
	void fillData();

	int m_row;
	int m_col;

	std::fstream m_file;

	Row* m_rows;
};
