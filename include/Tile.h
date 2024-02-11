#pragma once

class Tile {
public:
    // Constructors
    Tile() = default; // Default constructor
    Tile(char); // Constructor with symbol parameter

    // Method to get the symbol of the tile
    char getSymbol() const;

    // Method to set the symbol of the tile
    void setSymbol(char);

private:
    char m_symbol; // Symbol representing the content of the tile
};
