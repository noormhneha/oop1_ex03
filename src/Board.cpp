#include "Board.h"

// Constructor for Board class
Board::Board() {
    // Initialize rows and columns based on data from utilities
    m_row = m_utilities.getRow();
    m_col = m_utilities.getCol();
    // Initialize the 2D vector to store the board data
    m_rows = m_utilities.getData();
    // Set the background of the board
    setBackground();
    // Set up the toolbar on the side of the board
    m_sideTools.setToolbar();
}

// Get the current location of an object on the board
Location Board::getLocation() const {
    return { m_row, m_col };
}

// Set the background of the board
void Board::setBackground() {
    // Load background texture from file
    m_backgroundTexture.loadFromFile(m_background);
    // Scale the background sprite to fit the board dimensions
    m_backgroundSprite.setScale((float)(m_col * P_SIZE) / m_backgroundTexture.getSize().x,
                                (float)(m_row * P_SIZE) / m_backgroundTexture.getSize().y);
    m_backgroundSprite.setTexture(m_backgroundTexture);
}

// Change the background of the board
void Board::changeBackground() {
    // Cycle through different backgrounds
    if (m_background == "Tom&Jerry1.png"){
        m_background = "Tom&Jerry2.png";
    } else if (m_background == "Tom&Jerry2.png") {
        m_background = "Tom&Jerry3.png";
    } else {
        m_background = "Tom&Jerry1.png";
    }
    // Update the background
    setBackground();
}

// Handle mouse button release event
void Board::buttonReleased(sf::Event event, sf::RenderWindow& window) {
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    // Get the position of the mouse click
    sf::Vector2f pos((float)(x - (x % P_SIZE)), (float)(y - (y % P_SIZE)));
    sf::Vector2i item;
    if (pos.x == 0) {
        // If clicked on the toolbar, get the icon
        m_iconShape = m_sideTools.getIcon(pos);
        if (m_iconShape != ERASE && m_iconShape != BACKGROUND) {
            // Convert the icon to character and save the change
            m_nextChar = convertIconToChar(m_iconShape);
            saveRestart();
        }
        else if (m_iconShape == BACKGROUND){
            // Change the background if background button is clicked
            changeBackground();
        }
        else return;
    }
    else {
        // If clicked on the board, get the position and check icon validation
        item = { (int)(std::floor(x / P_SIZE)), (int)(std::floor(y / P_SIZE)) };
        checkIconValidation(item);
    }
}

// Draw the board and its contents
void Board::draw(sf::RenderWindow& window){
    // Draw the background
    window.draw(m_backgroundSprite);
    // Draw the toolbar
    m_sideTools.drawToolbar(window);

    // Draw each object on the board
    for (int i = 0; i < m_row; i++) {
        for (int j = 0; j < m_col; j++) {
            IconsBar icon = convertCharToIcon(m_rows[j].at(i).getSymbol());
            if (icon != NON) {
                m_icon.draw(window, { (float)( j * P_SIZE ), (float)(i * P_SIZE) }, m_sideTools.getIconSprite(icon));
            }
        }
    }
}

// Convert icon to character representation
char Board::convertIconToChar(const IconsBar& icon) const {
    switch (icon) {
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

// Convert character to icon representation
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

// Check if placing the icon at a location is valid
void Board::checkIconValidation(sf::Vector2i place){
    if (m_iconShape != ERASE) {
        switch (m_nextChar) {
            case MOUSE_CH:
                // Handle special case for mouse
                if (m_thereIsMouse) { m_rows[m_mouseLocation._row].at(m_mouseLocation._col).setSymbol(' '); }
                else { m_thereIsMouse = true; }
                m_rows[place.x].at(place.y).setSymbol(m_nextChar);
                m_mouseLocation._row = place.x;
                m_mouseLocation._col = place.y;
                break;
                // Handle other cases for icons
            case CAT_CH: case CHEESE_CH: case WALL_CH: case GIFT_CH: case KEY_CH: case DOOR_CH:
                m_rows[place.x].at(place.y).setSymbol(m_nextChar);
                break;
        }
    }
    else { deleteObject(place); }
}

// Save or restart based on icon selected
void Board::saveRestart() {
    switch (m_iconShape) {
        case SAVE:
            saveToFile();
            exit(EXIT_SUCCESS);
        case RESET:
            resetMap();
            break;
        default:
            break;
    }
}

// Save current board configuration to a file
void Board::saveToFile() {
    std::ofstream outFile("Board.txt");
    if (!outFile) {
        std::cerr << "Cannot Open file!";
        exit(EXIT_FAILURE);
    }
    outFile << m_row << ' ' << m_col << "\n\n"; // Write cols and rows

    for (size_t i = 0; i < m_row; i++) {
        for (size_t j = 1; j < m_col; j++) {
            outFile << m_rows[j].at(i).getSymbol();
        }
        outFile << std::endl;
    }

    outFile.close();
}

// Reset the board to initial state
void Board::resetMap() {
    for (int i = 0; i < m_col; i++) {
        for (int j = 0; j < m_row; j++) {
            m_rows[i][j].setSymbol(' ');
        }
    }
}

// Delete object at specified location
void Board::deleteObject(sf::Vector2i place) {
    m_rows[place.x].at(place.y).setSymbol(' ');
}
