#pragma once

#include <fstream>
#include <iostream>
#include "Row.h"

// Symbols representing different elements on the board
const char MOUSE_CH = '%';
const char CAT_CH = '^';
const char DOOR_CH = 'D';
const char WALL_CH = '#';
const char KEY_CH = 'F';
const char CHEESE_CH = '*';
const char GIFT_CH = '$';
const char ROAD_CH = ' ';

// Struct representing the location of a tile on the board
struct Location {
    int _row;
    int _col;
};

class Utilities {
public:
    // Constructor
    Utilities();

    // Methods to get the number of rows and columns, and access the board data
    int getRow() const;
    int getCol() const;
    Row* getData() const;

private:
    // Private methods for reading data from file or user input, and filling the board data
    void readData();
    void readFromFile();
    void readFromUser();
    void information();
    void fillData();

    int m_row; // Number of rows on the board
    int m_col; // Number of columns on the board

    std::fstream m_file; // File stream for reading data from file

    Row* m_rows; // Pointer to an array of Row objects representing the board data
};
