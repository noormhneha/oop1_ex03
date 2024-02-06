#include "Board.h"

//Board::Board()
//{
//}

//Board::Board(sf::RenderWindow& window) {
//
//
//}

Board::Board() : m_col(0), m_row(0) {
	readData();
	fillData();
	m_sideTools.setToolbar();
	
}

void Board::readData() {
	m_file.open("Board.txt");
	m_file.is_open() ? readFromFile() : readFromUser();
}

void Board::readFromFile() {
	m_file >> m_row >> m_col;
}

void Board::readFromUser() {
	std::cout << "Insert number of rows: ";
	std::cin >> m_row;
	std::cout << "Insert number of cols: ";
	std::cin >> m_col;
}

void Board::fillData() {
	m_rows = new Row[m_row];
	for (size_t i = 0; i < m_row; i++) {
		for (int j = 0; j < m_col; j++) {
			Tile tile(j, ' ');
			m_rows[i].push_back(tile);
		}
	}
}

Location Board::getLocation() const {
	return { (float)m_row, (float)m_col };
}

Location Board::getIconsLocation(const sf::Event& pressedEvent) const {
	sf::Vector2f loc = m_icons.getIconPressed(pressedEvent);
	return { loc.x , loc.y };
}

void Board::setIcon(IconsBar shape) {
	m_iconShapes = shape;
}

void Board::draw(sf::RenderWindow& window){
	m_sideTools.drawToolbar(window);
}

