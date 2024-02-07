#pragma once

struct Location {
	int _row;
	int _col;
};

struct Buttons {
	bool _save = false;
	bool _delete = false;
	bool _restart = false;
	bool _mouse = false;
	unsigned int _cats = 0;
	unsigned int  _keys = 0;
	unsigned int _doors = 0;
	unsigned int _gift = 0;
};
