#include "Controller.h"

Controller::Controller() : m_col(0), m_row(0) {
	readData();
	fillData();

}

void Controller::readData() {
	std::cout << "Insert number of rows: ";
	std::cin >> m_row;
	std::cout << "Insert number of cols: ";
	std::cin >> m_col;
}

void Controller::fillData() {
	m_rows = new Row[m_row];
	for (size_t i = 0; i < m_row; i++) {
		for (int j = 0; j < m_col; j++) {
			Tile tile(j, ' ');
			m_rows[i].push_back(tile);
		}
	}
}

Controller::~Controller() {}