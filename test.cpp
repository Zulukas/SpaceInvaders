#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <iostream>

// #include "tetris.h"

using namespace std;

#define width 480
#define height 640

void end(SDL_Window*& window, SDL_Renderer*& renderer)
{
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;
}

void loop(SDL_Window* w, SDL_Renderer* r)
{
	SDL_SetRenderDrawColor(r, 0, 0, 0, 0);
	SDL_RenderClear(r);

	SDL_Rect rect;
	rect.x = 51;
	rect.y = 51;
	rect.w = 23;
	rect.h = 23;

	SDL_SetRenderDrawColor(r, 0, 255, 0, 0);
	SDL_RenderFillRect(r, &rect);

	rect.x = 76;

	SDL_RenderFillRect(r, &rect);

                      // x1  y1      x2  y2 
	SDL_RenderDrawLine(r, 0, 50,  width, 50);
	SDL_RenderDrawLine(r, 0, 100, width, 100);
	SDL_RenderDrawLine(r, 0, 150, width, 150);
	SDL_RenderDrawLine(r, 0, 200, width, 200);

	SDL_RenderDrawLine(r, 50,  0, 50, height);
	SDL_RenderDrawLine(r, 100, 0, 100, height);
	SDL_RenderDrawLine(r, 150, 0, 150, height);
	SDL_RenderDrawLine(r, 200, 0, 200, height);

	aacircleColor(r, 125, 125, 75, 0xFF0000FF);

	SDL_RenderPresent(r);

	SDL_Delay(2000);
}

int main()
{
	SDL_Window *window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

	if (window == nullptr)
	{
		cout << "SL_CreateWindow Error: " << SDL_GetError() << endl;
		return 1;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr)
	{
		cout << "SDL_CreateRenderer: " << SDL_GetError() << endl;
		SDL_DestroyWindow(window);
		return 2;
	}

	// Tetris tetris;

	loop(window, renderer);

	end(window, renderer);
}