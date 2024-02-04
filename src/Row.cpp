#include "Row.h"

Row::Row(int size, const Tile& tl) : m_size(size), m_isEmpty(true) {
	m_data = new Tile[size];
}

Row::Row(const Row& other) : m_size(other.m_size), m_isEmpty(other.m_isEmpty) {
	m_data = new Tile[m_size];
	for (int i = 0; i < m_size; ++i) {
		m_data[i] = other.m_data[i];
	}
}

Row& Row::operator=(const Row& other) {
	if (this != &other) {
		delete[] m_data;
		m_size = other.m_size;
		m_isEmpty = other.m_isEmpty;
		m_data = new Tile[m_size];
		copyData(m_data, other.m_data);
	}
	return *this;
}


const Tile& Row::at(int index) const {
	return m_data[index];
}

Tile& Row::at(int index) {
	return m_data[index];
}

const Tile& Row::operator[](int index) const {
	return m_data[index];
}

Tile& Row::operator[](int index) {
	return m_data[index];
}

void Row::push_back(const Tile& val) {
	m_isEmpty = false;
	arrResize();
	m_data[m_size] = val;
	m_size++;
}

int Row::size() const {
	return m_size;
}

bool Row::empty() const {
	return m_isEmpty;
}

const Tile& Row::begin() const {
	return (*this).at(0);
}

Tile& Row::begin() {
	return (*this).at(0);
}

const Tile& Row::end() const {
	return (*this).at(m_size - 1);
}

Tile& Row::end() {
	return (*this).at(m_size - 1);
}

void Row::arrResize() {
	auto arr = new Tile[m_size + 1];
	copyData(arr, m_data);
	delete[] m_data;
	m_data = arr;
}

void Row::copyData(Tile* arr1, const Tile* arr2) {
	for (size_t i = 0; i < m_size; i++) {
		arr1[i] = arr2[i];
	}
}

Row::~Row() {
	delete[] m_data;
}
