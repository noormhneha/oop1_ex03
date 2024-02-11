#pragma once

#include "Tile.h" // Include the Tile class header
#include <string> // Include the <string> header for string manipulation

class Row {
public:
    // Constructors
    explicit Row(int size = 0, const Tile& tl = Tile()); // Default and parameterized constructor

    Row(const Row& other); // Copy constructor
    Row& operator=(const Row& other); // Copy assignment operator

    // Accessors for individual tiles
    const Tile& at(int) const; // Access tile at a specific index (const version)
    Tile& at(int); // Access tile at a specific index
    const Tile& operator[](int) const; // Access tile using array subscript operator (const version)
    Tile& operator[](int); // Access tile using array subscript operator

    // Methods for managing the row
    void push_back(const Tile&); // Add a tile to the end of the row
    void increaseSize(); // Increase the size of the row
    int size() const; // Get the size of the row
    bool empty() const; // Check if the row is empty
    const Tile& begin() const; // Get the first tile in the row (const version)
    Tile& begin(); // Get the first tile in the row
    const Tile& end() const; // Get the last tile in the row (const version)
    Tile& end(); // Get the last tile in the row
    std::string getLine(); // Get a string representation of the row

    // Destructor
    ~Row();

private:
    int m_size; // Size of the row
    int m_rows = 0; // Number of rows (potentially redundant)
    bool m_isEmpty; // Flag indicating if the row is empty

    Tile* m_data; // Pointer to an array of tiles

    // Private helper methods
    void copyData(Tile*, const Tile*); // Copy data from one array to another
    void arrResize(); // Resize the array of tiles
};
