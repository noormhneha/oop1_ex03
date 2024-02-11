#include "Row.h"

// Constructor with size and default tile
Row::Row(int size, const Tile& tl) : m_size(size), m_isEmpty(true) {
    m_data = new Tile[size]; // Allocate memory for the row
}

// Copy constructor
Row::Row(const Row& other) : m_size(other.m_size), m_isEmpty(other.m_isEmpty) {
    m_data = new Tile[m_size]; // Allocate memory for the row
    // Copy data from other row
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = other.m_data[i];
    }
}

// Assignment operator
Row& Row::operator=(const Row& other) {
    if (this != &other) {
        delete[] m_data; // Delete existing data
        m_size = other.m_size;
        m_isEmpty = other.m_isEmpty;
        m_data = new Tile[m_size]; // Allocate memory for the row
        // Copy data from other row
        for (int i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }
    return *this;
}

// Access tile at index (const version)
const Tile& Row::at(int index) const {
    return m_data[index];
}

// Access tile at index
Tile& Row::at(int index) {
    return m_data[index];
}

// Access tile at index using []
const Tile& Row::operator[](int index) const {
    return m_data[index];
}

// Access tile at index using []
Tile& Row::operator[](int index) {
    return m_data[index];
}

// Add a tile to the end of the row
void Row::push_back(const Tile& val) {
    m_isEmpty = false; // Row is not empty anymore
    arrResize(); // Resize array to accommodate the new tile
    m_data[m_size] = val; // Add tile to the end
    m_size++; // Increment size
}

// Increase row size
void Row::increaseSize() {
    m_rows++; // Increment row count
}

// Get the size of the row
int Row::size() const {
    return m_rows; // Return row count
}

// Check if the row is empty
bool Row::empty() const {
    return m_isEmpty;
}

// Get iterator to beginning of the row (const version)
const Tile& Row::begin() const {
    return (*this).at(0);
}

// Get iterator to beginning of the row
Tile& Row::begin() {
    return (*this).at(0);
}

// Get iterator to end of the row (const version)
const Tile& Row::end() const {
    return (*this).at(m_size - 1);
}

// Get iterator to end of the row
Tile& Row::end() {
    return (*this).at(m_size - 1);
}

// Resize the array to accommodate more elements
void Row::arrResize() {
    auto arr = new Tile[m_size + 1]; // Allocate new array with increased size
    copyData(arr, m_data); // Copy data to new array
    delete[] m_data; // Delete old array
    m_data = arr; // Update data pointer
}

// Copy data from one array to another
void Row::copyData(Tile* arr1, const Tile* arr2) {
    for (size_t i = 0; i < m_size; i++) {
        arr1[i] = arr2[i];
    }
}

// Get the characters of the row as a string
std::string Row::getLine() {
    std::string line;
    for (int i = 1; i < m_rows; i++) {
        line += m_data[i].getSymbol(); // Get symbol of each tile and append to line
    }
    return line; // Return the resulting string
}

// Destructor
Row::~Row() {
    delete[] m_data; // Deallocate memory for the row
}
