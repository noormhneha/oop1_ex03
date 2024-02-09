#pragma once

#include "Tile.h"
#include <string>

class Row {
public:
	explicit Row(int size = 0, const Tile& tl = Tile());

	Row(const Row& other);
	Row& operator=(const Row& other);

	const Tile& at(int) const;
	Tile& at(int);
	const Tile& operator[](int) const;
	Tile& operator[](int);

	void push_back(const Tile&);
	void increaseSize();
	int size() const;
	bool empty() const;
	const Tile& begin() const;
	Tile& begin();
	const Tile& end() const;
	Tile& end();
	std::string getLine();

	~Row();

private:
	int m_size;
	int m_rows = 0;
	bool m_isEmpty;

	Tile* m_data;

	void copyData(Tile*, const Tile*);
	void arrResize();
};