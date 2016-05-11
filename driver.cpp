#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

using namespace std;

#define WIDTH 640
#define HEIGHT 480

void errorQuit(const string msg, const int errorNum)
{
	cout << msg << SDL_GetError() << endl;
	SDL_Quit();
	exit(errorNum);
}

int main()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		cout << "SDL_Init Error: " << SDL_GetError() << endl;
		return 1;
	}

	SDL_Window *window = SDL_CreateWindow("Space Invaders", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

	if (window == nullptr)
	{
		errorQuit("SDL_CreateWindow Error: ", 2);
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr)
	{
		errorQuit("SDL_CreateRenderer Error: ", 3);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}