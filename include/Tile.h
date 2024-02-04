#pragma once

class Tile {
public:
	Tile() = default;
	Tile(int, char);
	
	int getValue() const;
	void setValue(int);

	char getSymbol() const;
	void setSymbol(char);

private:
	int m_value;
	char m_symbol;
};