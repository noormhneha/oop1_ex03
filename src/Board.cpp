#include "Board.h"

Board::Board() {
    m_row = m_utilities.getRow();
    m_col = m_utilities.getCol();
    m_rows = m_utilities.getData();
	setBackground();
	m_sideTools.setToolbar();
}

Location Board::getLocation() const {
	return { m_row, m_col };
}

void Board::setBackground() {
	m_backgroundTexture.loadFromFile(m_background);
	m_backgroundSprite.setScale((float)(m_row * P_SIZE) / m_backgroundTexture.getSize().x, (float)(m_col * P_SIZE) / m_backgroundTexture.getSize().y);
	m_backgroundSprite.setTexture(m_backgroundTexture);
}

void Board::changeBackground() {
    if (m_background == "Tom&Jerry1.png"){
        m_background = "Tom&Jerry2.png";
    } else if (m_background == "Tom&Jerry2.png") {
        m_background = "Tom&Jerry3.png";
    } else {
        m_background = "Tom&Jerry1.png";
    }
    setBackground();
}

void Board::buttonReleased(sf::Event event, sf::RenderWindow& window) {
	int x = event.mouseButton.x;
	int y = event.mouseButton.y;

	sf::Vector2f pos((float)(x - (x % P_SIZE)), (float)(y - (y % P_SIZE)));
	sf::Vector2i item;
	if (pos.x == 0) {
		m_iconShape = m_sideTools.getIcon(pos);
		if (m_iconShape != ERASE && m_iconShape != BACKGROUND) {
			m_nextChar = convertIconToChar(m_iconShape);
			saveRestart();
		}
		else if (m_iconShape == BACKGROUND){
            changeBackground();
        }
        else return;
	}
	else {
		item = { (int)(std::floor(x / P_SIZE)), (int)(std::floor(y / P_SIZE)) };
		checkIconValidation(item);
	}
}


void Board::draw(sf::RenderWindow& window){
	window.draw(m_backgroundSprite);
	m_sideTools.drawToolbar(window);

	for (int i = 1; i < m_row; i++) {
		for (int j = 0; j < m_col; j++) {
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
			if (m_thereIsMouse) { m_rows[m_mouseLocation._row].at(m_mouseLocation._col).setSymbol(' '); }
			else { m_thereIsMouse = true; }
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
		resetMap();
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
		outFile << m_rows[i].getLine() << '\n';
	}
	outFile.close();
}

void Board::resetMap() {
	for (int i = 0; i < m_row; i++) {
		for (int j = 0; j < m_col; j++) {
			m_rows[i][j].setSymbol(' ');
		}
	}
}

void Board::deleteObject(sf::Vector2i place) {
	m_rows[place.x].at(place.y).setSymbol(' ');
}
