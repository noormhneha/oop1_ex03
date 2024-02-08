#pragma once

#include <thread>

#include "Board.h"


class Controller {
public:
	Controller();

private:
	void openWindow();
	Board m_board;
	sf::RenderWindow m_window;
};