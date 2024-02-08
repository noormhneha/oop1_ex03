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
	sf::Vector2i item = { (int)(std::floor(x / P_SIZE)), (int)(std::floor(y / P_SIZE)) };
	if (pos.x == 0) {
		m_iconShape = m_sideTools.getIcon(pos, m_buttons);
		m_nextChar = convertIconToChar(m_iconShape); 
		saveDeleteRestart(item);
		// need to check save restart or delete
	}
	else {
		checkIconValidation(m_nextChar, item);
	}

}



void Board::draw(sf::RenderWindow& window){
	m_sideTools.drawToolbar(window);

	for (size_t i = 1; i < m_row; i++) {
		for (size_t j = 0; j < m_col; j++) {
			IconsBar icon = convertCharToIcon(m_rows[i].at(j).getSymbol());
			if (icon != NON) {
				//if ()
				m_icon.draw(window, { (float)( i * P_SIZE ), (float)(j * P_SIZE) }, m_sideTools.getIconSprite(icon));
			}
		}
	}
	// draw all the => shap in row 
}

char Board::convertIconToChar(const IconsBar& icon) const {
	switch (icon)
	{
	case MOUSE: return MOUSE_CH;
	case CAT: return CAT_CH;
	case CHEESE: return CHEESE_CH;
	case WALL: return WALL_CH;
	case KEY: return KEY_CH;
	case DOOR: return DOOR_CH;
	case GIFT: return GIFT_CH;
	default: return NULL;
	}
	
}

IconsBar Board::convertCharToIcon(char c) const {
	switch (c) {
	case MOUSE_CH: return MOUSE;
	case CAT_CH: return CAT;
	case CHEESE_CH: return CHEESE;
	case WALL_CH: return WALL;
	case KEY_CH: return KEY;
	case DOOR_CH: return DOOR;
	case GIFT_CH: return GIFT;
	default: return NON;
	}
}

void Board::checkIconValidation(char c, sf::Vector2i place){
	switch (c) {
	case MOUSE_CH:
		if (m_buttons._mouse) { m_rows[m_mouseLocation._row].at(m_mouseLocation._col).setSymbol(' '); }
		else { m_buttons._mouse = true; }
		m_rows[place.x].at(place.y).setSymbol(c);
		m_mouseLocation._row = place.x;
		m_mouseLocation._col = place.y;
		break;
	case CAT_CH: case CHEESE_CH: case WALL_CH: case GIFT_CH: case KEY_CH:
		m_rows[place.x].at(place.y).setSymbol(c);
		break;
	}
}

void Board::saveDeleteRestart(sf::Vector2i place) {
	switch (m_iconShape)
	{
	case SAVE:
		saveToFile();
		break;
	case ERASE:
		deleteObject(place);
		break;
	case RESET:
		resetMap();
		break;
	default:
		break;
	}
}

void Board::saveToFile() {
	std::fstream outFile("Board.txt");

	if (!outFile) {
		std::cerr << "Cannot Open file!";
		exit(EXIT_FAILURE);
	}

	for (size_t i = 0; i < m_row; i++) {
		for (size_t j = 0; j < m_col; j++) {
			outFile << m_rows[i][j].getSymbol();
		}
		outFile << '\n';
	}

	outFile.close();
}

void Board::resetMap() {
	for (size_t i = 0; i < m_row; i++) {
		for (int j = 0; j < m_col; j++) {
			m_rows[i][j].setSymbol(' ');
		}
	}
}

void Board::deleteObject(sf::Vector2i place) {
	m_rows[place.x].at(place.y).setSymbol(' ');
}
