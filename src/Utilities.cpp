#include "Utilities.h"

// Constructor to initialize board dimensions and read data
Utilities::Utilities() : m_col(0), m_row(0) {
    readData(); // Read data from file or user input
    fillData(); // Fill data for the board
}

// Read data from file or user input
void Utilities::readData() {
    m_file.open("Board.txt");
    // Check if the file is open
    m_file.is_open() ? readFromFile() : readFromUser();
}

// Read data from file
void Utilities::readFromFile() {
    m_file >> m_row >> m_col; // Read row and column from file
}

// Read data from user input
void Utilities::readFromUser() {
    do {
        information(); // Display information to the user
        // Prompt user for number of rows and columns
        std::cout << "Insert number of rows: ";
        std::cin >> m_row;
        std::cout << "Insert number of cols: ";
        std::cin >> m_col;
    } while (m_row < 11 && m_col < 3); // Ensure minimum dimensions
}

// Display information to the user
void Utilities::information() {
    system("cls"); // Clear the console screen
    std::fstream info("information.txt");
    if (info.is_open()) {
        std::string line;
        // Read and print each line from the information file
        while (std::getline(info, line)) {
            std::cout << line << std::endl;
        }
        std::cout << std::endl;
        info.close(); // Close the file
    } else {
        std::cerr << "Unable to open file!" << std::endl;
        exit(EXIT_FAILURE); // Exit the program if unable to open file
    }
}

// Fill data for the board
void Utilities::fillData() {
    m_rows = new Row[m_col]; // Allocate memory for rows
    // Fill each row with empty tiles
    for (size_t i = 0; i < m_col; i++) {
        for (size_t j = 0; j < m_row; j++) {
            Tile tile(' '); // Create a tile with empty symbol
            m_rows[i].push_back(tile); // Add the tile to the row
        }
        m_rows->increaseSize(); // Increase size of the row
    }
}

// Get the number of rows
int Utilities::getRow() const {
    return m_row;
}

// Get the number of columns
int Utilities::getCol() const {
    return m_col;
}

// Get the data (rows) of the board
Row* Utilities::getData() const {
    return m_rows;
}
