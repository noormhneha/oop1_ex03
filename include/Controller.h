#pragma once

#include <iostream>

#include "Row.h"

class Controller {
public:
	Controller();
	~Controller();

private:
	void readData();
	void fillData();

	int m_row;
	int m_col;
	Row* m_rows;
};