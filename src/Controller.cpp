#include "Controller.h"

Controller::Controller() {
	openWindow();
}

void Controller::openWindow(){

	Location location = m_board.getLocation();
	m_window.create(sf::VideoMode((location._row * P_SIZE)  ,(location._col + 1) * P_SIZE), "Tom&Jerry");
	while (m_window.isOpen()) {
		m_window.clear();
		m_board.draw(m_window);
		if (auto event = sf::Event{}; m_window.waitEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::MouseButtonReleased:
				location = m_board.getIconsLocation(event);
				m_board.setIcon(choosingIcon(location));
				break;
			}
		}
		m_window.display();
	}
}

IconsBar Controller::choosingIcon(const Location& loc) {
	if ((int)loc._row == 0) {
		switch ((int)loc._col)
		{
		case MOUSE: return MOUSE;
		case CAT: return CAT;
		case CHEESE: return CHEESE;
		case WALL: return WALL;
		case KEY: return KEY;
		case DOOR: return DOOR;
		case GIFT: return GIFT;
		case SAVE: return SAVE;
		case ERASE: return ERASE;
		case RESET: return RESET;
		default: break;
		}
	}
}
