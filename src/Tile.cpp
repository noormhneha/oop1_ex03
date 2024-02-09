#include "Tile.h"

Tile::Tile(char sym) : m_symbol(sym) {}

char Tile::getSymbol() const {
    return m_symbol;
}

void Tile::setSymbol(char sym) {
    m_symbol = sym;
}