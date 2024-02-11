#include "Controller.h"

Controller::Controller() {
	openWindow();
}

void Controller::openWindow(){
	Location location = m_board.getLocation();
	m_window.create(sf::VideoMode(location._col * P_SIZE  ,location._row * P_SIZE), "Tom&Jerry");
	while (m_window.isOpen()) {
		m_window.clear();
		m_board.draw(m_window);
		if (auto event = sf::Event{}; m_window.waitEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::MouseButtonReleased:
				m_board.buttonReleased(event, m_window);
				break;
			}
		}
		m_window.display();
	}
}
