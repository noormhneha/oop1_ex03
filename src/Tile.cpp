#include "Tile.h"

Tile::Tile(int val, char sym) : m_value(val), m_symbol(sym) {}

int Tile::getValue() const {
    return m_value;
}

void Tile::setValue(int val) {
    m_value = val;
}

char Tile::getSymbol() const {
    return m_symbol;
}

void Tile::setSymbol(char sym) {
    m_symbol = sym;
}