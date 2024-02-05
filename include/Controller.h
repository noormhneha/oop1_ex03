#pragma once

#include <thread>

#include "Board.h"
#include "Row.h"

class Controller {
public:
	Controller();
	~Controller();

private:
	void readData();
    void readFromFile();
    void readFromUser();

	void fillData();

	void openWindow();

	int m_row;
	int m_col;
	Row* m_rows;

    std::fstream m_file;

	sf::RenderWindow m_window;
};