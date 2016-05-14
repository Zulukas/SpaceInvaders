#include <iostream>
#include <new>
#include <string>
#include <unistd.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "gamewindow.hpp"
#include "textobject.hpp"
#include "keyboardhandler.hpp"
// #include "point.hpp"
// #include "velocity.hpp"

using namespace std;

const Uint16 WIDTH = 640;
const Uint16 HEIGHT = 480;

GameWindow* gw = nullptr;

void errorQuit(const string msg, const int errorNum)
{
	cout << msg << SDL_GetError() << endl;
	SDL_Quit();
	exit(errorNum);
}

void mainLoop() 
{
	while (gw->gameIsRunning())
	{
		gw->update();
		gw->draw();
	}
}

int main()
{
	// SDL_Window* window;
	// SDL_Renderer* renderer;

	// if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	// {
	// 	cerr << __LINE__ << " SDL_Init Error: " << SDL_GetError() << endl;
	// 	exit(1);
	// }

	// window = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

	// if (window == nullptr)
	// {
	// 	cerr << __LINE__ << " SDL_CreateWindow Error: " << SDL_GetError() << endl;
	// 	exit(2);
	// }

	// renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	// cout << "Renderer: " << renderer << endl;

	// if (renderer == nullptr)
	// {
	// 	cerr << __LINE__ << " SDL_CreateRenderer Error: " << SDL_GetError() << endl;
	// 	exit(3);
	// }

	// SDL_RenderSetLogicalSize(renderer, WIDTH, HEIGHT);
	// SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	// if (TTF_Init() == -1)
	// {
	// 	cerr << __LINE__ << " TFF_Init Error: " << SDL_GetError() << endl;
	// 	exit(4);
	// }

	gw = new GameWindow("Space Invaders", WIDTH, HEIGHT);

	mainLoop();

	delete gw;

	return 0;
}