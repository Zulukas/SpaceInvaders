

#include <iostream>
#include <new>
#include <string>
#include <unistd.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// #include "gamewindow.hpp"
#include "textobject.hpp"
#include "keyboardhandler.hpp"
// #include "point.hpp"
// #include "velocity.hpp"

using namespace std;

const Uint16 WIDTH = 640;
const Uint16 HEIGHT = 480;

// GameWindow* gw = nullptr;

void errorQuit(const string msg, const int errorNum)
{
	cout << msg << SDL_GetError() << endl;
	SDL_Quit();
	exit(errorNum);
}

void mainloop() 
{
	// while (gw->gameIsRunning())
	// {
	// 	gw->update();
	// 	gw->draw();
	// }
}

int main()
{
	SDL_Window* window;
	SDL_Renderer* renderer;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		cerr << "SDL_Init Error: " << SDL_GetError() << endl;
		exit(1);
	}

	window = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

	if (window == nullptr)
	{
		cerr << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
		exit(2);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr)
	{
		cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
		exit(3);
	}

	if (TTF_Init() == -1)
	{
		cerr << "TFF_Init Error: " << SDL_GetError() << endl;
		exit(4);
	}

	TextObject* textObj = new TextObject(&*renderer, "Hello World", 16, Point(0,0));
	textObj->draw();

	sleep(2);

	delete textObj;

	return 0;
}