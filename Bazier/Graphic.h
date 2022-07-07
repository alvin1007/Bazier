#ifndef GRAPHICHEADER
#define GRAPHICHEADER

#include "main.h"
#include "Dot.h"

class Graphic {
public:
	Graphic() {}
	~Graphic() {}

	void Init();
	void DrawDot(SDL_Renderer* Renderer, Dot d, SDL_Color c, int _radius);
	void DrawLine(SDL_Renderer* Renderer, Dot d1, Dot d2, SDL_Color c);
};

#endif
