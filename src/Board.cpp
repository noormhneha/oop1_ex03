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
	do {
		information();
		std::cout << "Insert number of rows: ";
		std::cin >> m_row;
		std::cout << "Insert number of cols: ";
		std::cin >> m_col;
	} while (m_row < 10 && m_col < 3);
}

void Board::information() {
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

void Board::fillData() {
	m_rows = new Row[m_row];
	for (size_t i = 0; i < m_row; i++) {
		for (int j = 0; j < m_col; j++) {
			Tile tile(' ');
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
	sf::Vector2i item;
	if (pos.x == 0) {
		m_iconShape = m_sideTools.getIcon(pos);
		if (m_iconShape != ERASE) {
			m_nextChar = convertIconToChar(m_iconShape);
			saveRestart();
		}
		else return; 
	}
	else {
		item = { (int)(std::floor(x / P_SIZE)), (int)(std::floor(y / P_SIZE)) };
		checkIconValidation(item);
	}

}


void Board::draw(sf::RenderWindow& window){
	m_sideTools.drawToolbar(window);

	for (size_t i = 1; i < m_row; i++) {
		for (size_t j = 0; j < m_col; j++) {
			IconsBar icon = convertCharToIcon(m_rows[i].at(j).getSymbol());
			if (icon != NON) {
				m_icon.draw(window, { (float)( i * P_SIZE ), (float)(j * P_SIZE) }, m_sideTools.getIconSprite(icon));
			}
		}
	}
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

void Board::checkIconValidation(sf::Vector2i place){
	if (m_iconShape != ERASE) {
		switch (m_nextChar) {
		case MOUSE_CH:
			if (m_buttons._mouse) { m_rows[m_mouseLocation._row].at(m_mouseLocation._col).setSymbol(' '); }
			else { m_buttons._mouse = true; }
			m_rows[place.x].at(place.y).setSymbol(m_nextChar);
			m_mouseLocation._row = place.x;
			m_mouseLocation._col = place.y;
			break;
		case CAT_CH: case CHEESE_CH: case WALL_CH: case GIFT_CH: case KEY_CH: case DOOR_CH:
			m_rows[place.x].at(place.y).setSymbol(m_nextChar);
			break;
		}
	}
	else { deleteObject(place); }
}

void Board::saveRestart() {
	switch (m_iconShape)
	{
	case SAVE:
		saveToFile();
		break;
	case RESET:
		resetMap();
		break;
	default:
		break;
	}
}

void Board::saveToFile() {
	std::ofstream outFile("Board.txt");

	if (!outFile) {
		std::cerr << "Cannot Open file!";
		exit(EXIT_FAILURE);
	}

	outFile << m_row << ' ' << m_col << '\n'; // Write cols and rows
	for (size_t i = 0; i < (*m_rows).size(); i++) {
		outFile << m_rows[i].getLine() << '\n ';
		//outFile << ;
	}

	outFile.close();
}

void Board::resetMap() {
	for (size_t i = 0; i < m_row; i++) {
		for (size_t j = 0; j < m_col; j++) {
			m_rows[i][j].setSymbol(' ');
		}
	}
}

void Board::deleteObject(sf::Vector2i place) {
	m_rows[place.x].at(place.y).setSymbol(' ');
}
