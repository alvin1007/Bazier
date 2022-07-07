#include "Graphic.h"

void Graphic::Init()
{
	return;
}

void Graphic::DrawDot(SDL_Renderer* Renderer, Dot d, SDL_Color c, int _radius)
{
	SDL_SetRenderDrawColor(Renderer, c.r, c.g, c.b, c.a);

    const int diameter = _radius * 2;

    float x = (float)_radius - 1;
    float y = 0;
    float tx = 1;
    float ty = 1;
    float error = tx - diameter;

    while (x >= y) {
        SDL_RenderDrawLineF(Renderer, d.GetX() + x, d.GetY() - y, d.GetX() + x, d.GetY() + y);
        SDL_RenderDrawLineF(Renderer, d.GetX() - x, d.GetY() - y, d.GetX() - x, d.GetY() + y);
        SDL_RenderDrawLineF(Renderer, d.GetX() + y, d.GetY() - x, d.GetX() + y, d.GetY() + x);
        SDL_RenderDrawLineF(Renderer, d.GetX() - y, d.GetY() - x, d.GetX() - y, d.GetY() + x);

        if (error <= 0) {
            ++y;
            error += ty;
            ty += 2;
        }
        else if (error > 0) {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

void Graphic::DrawLine(SDL_Renderer* Renderer, Dot d1, Dot d2, SDL_Color c)
{
	SDL_SetRenderDrawColor(Renderer, c.r, c.g, c.b, c.a);
	SDL_RenderDrawLine(Renderer, d1.GetX(), d1.GetY(), d2.GetX(), d2.GetY());
}