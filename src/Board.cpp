#include "Board.h"

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
	return { m_row, m_col };
}


void Board::buttonReleased(sf::Event event, sf::RenderWindow& window)
{
	int x = event.mouseButton.x;
	int y = event.mouseButton.y;

	sf::Vector2f pos((float)(x - (x % P_SIZE)), (float)(y - (y % P_SIZE)));

	if (pos.x == 0) {
		m_iconShape = m_sideTools.getIcon(pos, m_save, m_delete, m_restart);
		m_nextChar = convertIconToChar(m_iconShape); 
		//will chack the save and delete and restart button
	}
	else {
		// switch case that send the char and pose to Row(useing n_nextChar)
	}

}

void Board::draw(sf::RenderWindow& window){
	m_sideTools.drawToolbar(window);

	// draw all the => shap in row 
}

char Board::convertIconToChar(const IconsBar& icon)
{
	switch (icon)
	{
	case MOUSE: return MOUSE_CH;
	case CAT: return CAT_CH;
	case CHEESE: return CHEESE_CH;
	case WALL: return WALL_CH;
	case KEY: return KEY_CH;
	case DOOR: return DOOR_CH;
	case GIFT: return GIFT_CH;
	default:
		break;
	}
	return NULL;
}

