#include "Tile.h"

// Constructor to initialize the tile with a symbol
Tile::Tile(char sym) : m_symbol(sym) {}

// Get the symbol of the tile
char Tile::getSymbol() const {
    return m_symbol;
}

// Set the symbol of the tile
void Tile::setSymbol(char sym) {
    m_symbol = sym;
}
