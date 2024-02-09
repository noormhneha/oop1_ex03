#pragma once

class Tile {
public:
	Tile() = default;
	Tile(char);

	char getSymbol() const;
	void setSymbol(char);

private:
	char m_symbol;
};