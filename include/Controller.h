#pragma once

#include <thread>

#include "Board.h"


class Controller {
public:
	Controller();

private:
	void openWindow();
	IconsBar choosingIcon(const sf::Vector2f&);
	Board m_board;
	sf::RenderWindow m_window;
};