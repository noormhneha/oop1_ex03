#include "Utilities.h"

Utilities::Utilities() : m_col(0), m_row(0) {
	readData();
	fillData();
}

void Utilities::readData() {
	m_file.open("Board.txt");
	m_file.is_open() ? readFromFile() : readFromUser();
}

void Utilities::readFromFile() {
	m_file >> m_row >> m_col;
}

void Utilities::readFromUser() {
	do {
		information();
		std::cout << "Insert number of rows: ";
		std::cin >> m_row;
		std::cout << "Insert number of cols: ";
		std::cin >> m_col;
	} while (m_row < 11 && m_col < 3);
}

void Utilities::information() {
	system("cls");
	std::fstream info("information.txt");
	if (info.is_open()) {
		std::string line;
		while (std::getline(info, line)) {
			std::cout << line << std::endl;
		}
		std::cout << std::endl;
		info.close();
	}
	else {
		std::cerr << "Unable to open file!" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void Utilities::fillData() {
	m_rows = new Row[m_col];
	for (size_t i = 0; i < m_col; i++) {
		for (size_t j = 0; j < m_row; j++) {
			Tile tile(' ');
			m_rows[i].push_back(tile);
		}
		m_rows->increaseSize();
	}
}

int Utilities::getRow() const{
    return m_row;
}

int Utilities::getCol() const {
    return m_col;
}

Row* Utilities::getData() const {
    return m_rows;
}