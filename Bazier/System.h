#ifndef SYSTEMHEADER
#define SYSTEMHEADER

#include "main.h"
#include "Graphic.h"

class System {
public:
	System() {}
	~System() {}

	void Init();
	void Run();
	void Clear();
private:	
	SDL_Window* Window = nullptr;
	SDL_Renderer* Renderer = nullptr;
	SDL_Event* Event = nullptr;

	Graphic* m_Graphic = nullptr;

	std::vector<Dot*> DotList;
	std::vector<Dot*> DotTraceList;

	float t = 0.0f;

	bool SystemQuit = false;
	bool timeCurrent = true;
};

#endif
