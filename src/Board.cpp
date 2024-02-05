#include "Board.h"

//Board::Board()
//{
//}

Board::Board(sf::RenderWindow& window) {
	window.clear();
	window.display();
    SideTools side; side.setToolbar(); side.drawToolbar(window);

}
