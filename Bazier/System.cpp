#include "System.h"

void System::Init()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
	
	Window = SDL_CreateWindow("Bazier", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC);
	Event = new SDL_Event;

	m_Graphic = new Graphic;
	m_Graphic->Init();

#if (MODE == 2)

#if (SAMPLE == 0)
	DotList.push_back(new Dot(300, 500));
	DotList.push_back(new Dot(900, 200));
	DotList.push_back(new Dot(700, 600));
#endif

#elif (MODE == 3)

#if (SAMPLE == 0)
	DotList.push_back(new Dot(300, 400));
	DotList.push_back(new Dot(500, 200));
	DotList.push_back(new Dot(700, 600));
	DotList.push_back(new Dot(900, 300));
#elif (SAMPLE == 1)
	DotList.push_back(new Dot(300, 300));
	DotList.push_back(new Dot(800, 300));
	DotList.push_back(new Dot(300, 600));
	DotList.push_back(new Dot(800, 600));
#elif (SAMPLE == 2)
	DotList.push_back(new Dot(300, 300));
	DotList.push_back(new Dot(800, 600));
	DotList.push_back(new Dot(300, 600));
	DotList.push_back(new Dot(800, 300));
#elif (SAMPLE == 3)
	DotList.push_back(new Dot(300, 600));
	DotList.push_back(new Dot(800, 450));
	DotList.push_back(new Dot(300, 300));
	DotList.push_back(new Dot(550, 600));

#endif

#elif (MODE == 4)

#if (SAMPLE == 0)
	DotList.push_back(new Dot(300, 200));
	DotList.push_back(new Dot(500, 550));
	DotList.push_back(new Dot(800, 100));
	DotList.push_back(new Dot(850, 500));
	DotList.push_back(new Dot(1100, 600));
#elif (SAMPLE == 1)
	DotList.push_back(new Dot(100, 100));
	DotList.push_back(new Dot(1100, 100));
	DotList.push_back(new Dot(300, 700));
	DotList.push_back(new Dot(900, 600));
	DotList.push_back(new Dot(300, 400));
#elif (SAMPLE == 2)
	DotList.push_back(new Dot(640, 360));
	DotList.push_back(new Dot(100, 100));
	DotList.push_back(new Dot(1180, 100));
	DotList.push_back(new Dot(1180, 620));
	DotList.push_back(new Dot(100, 620));
#endif

#endif
}

void System::Run()
{
	while (!SystemQuit)
	{
		while (SDL_PollEvent(Event) != 0)
		{
			switch (Event->type)
			{
			case SDL_QUIT:
				SystemQuit = true;
				break;
			case SDL_KEYDOWN:
				switch (Event->key.keysym.sym)
				{
				case SDLK_SPACE:
					timeCurrent = !timeCurrent;
					break;
				case SDLK_r:
					t = 0.0f;
					DotTraceList.clear();
					break;
				}
			}
		}

		SDL_RenderClear(Renderer);
#if (MODE == 2)
		for (int i = 0; i < DotList.size(); i++)
			m_Graphic->DrawDot(Renderer, *DotList[i], { 0x00, 0x00, 0x00, 0xFF }, 5);

		for (int i = 0; i < DotList.size() - 1; i++)
			m_Graphic->DrawLine(Renderer, *DotList[i], *DotList[i + 1], {0x00, 0x00, 0xFF, 0xFF});

		Dot d1 = Dot(DotList[1]->GetX() * (t)+DotList[0]->GetX() * (1 - t), DotList[1]->GetY() * (t)+DotList[0]->GetY() * (1 - t));
		Dot d2 = Dot(DotList[2]->GetX() * (t)+DotList[1]->GetX() * (1 - t), DotList[2]->GetY() * (t)+DotList[1]->GetY() * (1 - t));
		Dot* d3 = new Dot(d2.GetX() * (t)+d1.GetX() * (1 - t), d2.GetY() * (t)+d1.GetY() * (1 - t));

		m_Graphic->DrawDot(Renderer, d1, { 0x00, 0x00, 0x00, 0xFF }, 3);
		m_Graphic->DrawDot(Renderer, d2, { 0x00, 0x00, 0x00, 0xFF }, 3);
		m_Graphic->DrawDot(Renderer, *d3, { 0xFF, 0x00, 0x00, 0xFF }, 3);

		DotTraceList.push_back(d3);
		m_Graphic->DrawLine(Renderer, d1, d2, {0x00, 0xFF, 0x00, 0xFF});

		for (int i = 0; i < DotTraceList.size(); i++)
			m_Graphic->DrawDot(Renderer, *DotTraceList[i], { 0xFF, 0x00, 0x00, 0xFF }, 1);
#elif (MODE == 3)
		for (int i = 0; i < DotList.size(); i++)
			m_Graphic->DrawDot(Renderer, *DotList[i], { 0x00, 0x00, 0x00, 0xFF }, 5);

		for (int i = 0; i < DotList.size() - 1; i++)
			m_Graphic->DrawLine(Renderer, *DotList[i], *DotList[i + 1], { 0x00, 0x00, 0xFF, 0xFF });

		Dot d1 = Dot(DotList[1]->GetX() * (t)+DotList[0]->GetX() * (1 - t), DotList[1]->GetY() * (t)+DotList[0]->GetY() * (1 - t));
		Dot d2 = Dot(DotList[2]->GetX() * (t)+DotList[1]->GetX() * (1 - t), DotList[2]->GetY() * (t)+DotList[1]->GetY() * (1 - t));
		Dot d3 = Dot(DotList[3]->GetX() * (t)+DotList[2]->GetX() * (1 - t), DotList[3]->GetY() * (t)+DotList[2]->GetY() * (1 - t));

		m_Graphic->DrawDot(Renderer, d1, { 0x00, 0x00, 0x00, 0xFF }, 3);
		m_Graphic->DrawDot(Renderer, d2, { 0x00, 0x00, 0x00, 0xFF }, 3);
		m_Graphic->DrawDot(Renderer, d3, { 0x00, 0x00, 0x00, 0xFF }, 3);

		m_Graphic->DrawLine(Renderer, d1, d2, { 0x00, 0xFF, 0x00, 0xFF });
		m_Graphic->DrawLine(Renderer, d2, d3, { 0x00, 0xFF, 0x00, 0xFF });

		Dot d4 = Dot(d2.GetX() * (t)+d1.GetX() * (1 - t), d2.GetY() * (t)+d1.GetY() * (1 - t));
		Dot d5 = Dot(d3.GetX() * (t)+d2.GetX() * (1 - t), d3.GetY() * (t)+d2.GetY() * (1 - t));

		m_Graphic->DrawDot(Renderer, d4, { 0x00, 0x00, 0x00, 0xFF }, 3);
		m_Graphic->DrawDot(Renderer, d5, { 0x00, 0x00, 0x00, 0xFF }, 3);

		m_Graphic->DrawLine(Renderer, d4, d5, { 0x8B, 0x00, 0xFF, 0xFF });

		Dot* d6 = new Dot(d5.GetX() * (t)+d4.GetX() * (1 - t), d5.GetY() * t + d4.GetY() * (1 - t));

		m_Graphic->DrawDot(Renderer, *d6, { 0xFF, 0x00, 0x00, 0xFF }, 3);

		DotTraceList.push_back(d6);

		for (int i = 0; i < DotTraceList.size(); i++)
			m_Graphic->DrawDot(Renderer, *DotTraceList[i], { 0xFF, 0x00, 0x00, 0xFF }, 1);
#elif (MODE == 4)
		for (int i = 0; i < DotList.size(); i++)
			m_Graphic->DrawDot(Renderer, *DotList[i], { 0x00, 0x00, 0x00, 0xFF }, 5);

		for (int i = 0; i < DotList.size() - 1; i++)
			m_Graphic->DrawLine(Renderer, *DotList[i], *DotList[i + 1], { 0x00, 0x00, 0xFF, 0xFF });

		Dot d1 = Dot(DotList[1]->GetX() * (t)+DotList[0]->GetX() * (1 - t), DotList[1]->GetY() * (t)+DotList[0]->GetY() * (1 - t));
		Dot d2 = Dot(DotList[2]->GetX() * (t)+DotList[1]->GetX() * (1 - t), DotList[2]->GetY() * (t)+DotList[1]->GetY() * (1 - t));
		Dot d3 = Dot(DotList[3]->GetX() * (t)+DotList[2]->GetX() * (1 - t), DotList[3]->GetY() * (t)+DotList[2]->GetY() * (1 - t));
		Dot d4 = Dot(DotList[4]->GetX() * (t)+DotList[3]->GetX() * (1 - t), DotList[4]->GetY() * (t)+DotList[3]->GetY() * (1 - t));

		m_Graphic->DrawDot(Renderer, d1, { 0x00, 0x00, 0x00, 0xFF }, 3);
		m_Graphic->DrawDot(Renderer, d2, { 0x00, 0x00, 0x00, 0xFF }, 3);
		m_Graphic->DrawDot(Renderer, d3, { 0x00, 0x00, 0x00, 0xFF }, 3);
		m_Graphic->DrawDot(Renderer, d4, { 0x00, 0x00, 0x00, 0xFF }, 3);

		m_Graphic->DrawLine(Renderer, d1, d2, { 0x00, 0xFF, 0x00, 0xFF });
		m_Graphic->DrawLine(Renderer, d2, d3, { 0x00, 0xFF, 0x00, 0xFF });
		m_Graphic->DrawLine(Renderer, d3, d4, { 0x00, 0xFF, 0x00, 0xFF });

		Dot d5 = Dot(d2.GetX() * (t)+d1.GetX() * (1 - t), d2.GetY() * (t)+d1.GetY() * (1 - t));
		Dot d6 = Dot(d3.GetX() * (t)+d2.GetX() * (1 - t), d3.GetY() * (t)+d2.GetY() * (1 - t));
		Dot d7 = Dot(d4.GetX() * (t)+d3.GetX() * (1 - t), d4.GetY() * (t)+d3.GetY() * (1 - t));

		m_Graphic->DrawDot(Renderer, d5, { 0x00, 0x00, 0x00, 0xFF }, 3);
		m_Graphic->DrawDot(Renderer, d6, { 0x00, 0x00, 0x00, 0xFF }, 3);
		m_Graphic->DrawDot(Renderer, d7, { 0x00, 0x00, 0x00, 0xFF }, 3);
		
		m_Graphic->DrawLine(Renderer, d5, d6, { 0x8B, 0x00, 0xFF, 0xFF });
		m_Graphic->DrawLine(Renderer, d6, d7, { 0x8B, 0x00, 0xFF, 0xFF });

		Dot d8 = Dot(d6.GetX() * (t)+d5.GetX() * (1 - t), d6.GetY() * (t)+d5.GetY() * (1 - t));
		Dot d9 = Dot(d7.GetX() * (t)+d6.GetX() * (1 - t), d7.GetY() * (t)+d6.GetY() * (1 - t));

		m_Graphic->DrawDot(Renderer, d8, { 0x00, 0x00, 0x00, 0xFF }, 3);
		m_Graphic->DrawDot(Renderer, d9, { 0x00, 0x00, 0x00, 0xFF }, 3);

		m_Graphic->DrawLine(Renderer, d8, d9, { 0xFF, 0xA9, 0x73, 0xFF });

		Dot* d10 = new Dot(d9.GetX() * (t)+d8.GetX() * (1 - t), d9.GetY() * t + d8.GetY() * (1 - t));

		m_Graphic->DrawDot(Renderer, *d10, { 0xFF, 0x00, 0x00, 0xFF }, 3);
		
		DotTraceList.push_back(d10);

		for (int i = 0; i < DotTraceList.size(); i++)
			m_Graphic->DrawDot(Renderer, *DotTraceList[i], { 0xFF, 0x00, 0x00, 0xFF }, 1);
#endif

		if (t <= 1 && timeCurrent)
			t += 0.001f;

		SDL_SetRenderDrawColor(Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderPresent(Renderer);
	}
}

void System::Clear()
{
	SDL_DestroyWindow(Window);
	SDL_DestroyRenderer(Renderer);
	delete Event;
	delete m_Graphic;

	for (int i = 0; i < DotList.size(); i++)
		delete DotList[i];

	for (int i = 0; i < DotTraceList.size(); i++)
		delete DotTraceList[i];
}