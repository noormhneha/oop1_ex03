#include "Controller.h"

// Constructor for Controller class
Controller::Controller() {
    openWindow(); // Open the window upon construction
}

// Function to open the window and handle user interactions
void Controller::openWindow() {
    // Get the dimensions of the board
    Location location = m_board.getLocation();
    // Create the window with appropriate dimensions
    m_window.create(sf::VideoMode(location._col * P_SIZE, location._row * P_SIZE), "Tom&Jerry");

    // Main event loop
    while (m_window.isOpen()) {
        // Clear the window
        m_window.clear();

        // Draw the board on the window
        m_board.draw(m_window);

        // Event handling loop
        if (auto event = sf::Event{}; m_window.waitEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    // Close the window if 'X' button is clicked
                    m_window.close();
                    break;
                case sf::Event::MouseButtonReleased:
                    // Handle mouse button release events
                    m_board.buttonReleased(event, m_window);
                    break;
            }
        }

        // Display the updated window
        m_window.display();
    }
}
