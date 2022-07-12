#ifndef DOTHEADER
#define DOTHEADER

#include "main.h"

class Dot {
public:
	Dot(int x, int y) : _x(x), _y(y) {}
	Dot(float x, float y) : _x((int)x), _y((int)y) {}
	~Dot() {}

	int GetX() { return _x; }
	int GetY() { return _y; }
	
private:
	int _x = NULL;
	int _y = NULL;
};

#endif
