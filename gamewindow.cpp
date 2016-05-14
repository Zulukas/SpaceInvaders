#include "gamewindow.hpp"

#define DEBUG

#ifdef DEBUG

#include <iostream>
using namespace std;

#endif

#define TEXTFONT "font.ttf"

GameWindow::GameWindow(const char* windowName, Uint16 width, Uint16 height) throw (const SDLError)
{
	this->windowName = (char*)windowName;
	this->width = width;
	this->height = height;

	manager = new FPSmanager;
	SDL_initFramerate(manager);
	SDL_setFramerate(manager, FRAMERATE);

	gameRunning = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		cerr << __LINE__ << " SDL_Init Error: " << SDL_GetError() << endl;
		exit(1);
	}

	window = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

	if (window == nullptr)
	{
		cerr << __LINE__ << " SDL_CreateWindow Error: " << SDL_GetError() << endl;
		exit(2);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	cout << "Renderer: " << renderer << endl;

	if (renderer == nullptr)
	{
		cerr << __LINE__ << " SDL_CreateRenderer Error: " << SDL_GetError() << endl;
		exit(3);
	}

	SDL_RenderSetLogicalSize(renderer, width, height);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	if (TTF_Init() == -1)
	{
		cerr << __LINE__ << " TFF_Init Error: " << SDL_GetError() << endl;
		exit(4);
	}

	gfxObjects.push_back(new TextObject(renderer, "Space Invaders!", 16, Point(1, 1)));
	gfxObjects.push_back(new LineObject(renderer, Point(0, 20), Point(width, 20)));
	gfxObjects.push_back(new Bullet(renderer, Point(320, 480)));
}

GameWindow::~GameWindow()
{
	if (manager != nullptr)
		delete manager;

	for (int i = 0; i < gfxObjects.size(); i++)
	{
		if (gfxObjects[i] != nullptr)
		{
			delete gfxObjects[i];
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void GameWindow::draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	for (int i = 0; i < gfxObjects.size(); i++)
	{
		if (gfxObjects[i] == nullptr)
			continue;

		gfxObjects[i]->draw();
	}

	SDL_RenderPresent(renderer);

	SDL_framerateDelay(this->manager);
	
}

void GameWindow::update()
{
	//Check for user input first
	while(SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			gameRunning = false;
		}
	}

	#ifdef DEBUG
	bool keyPressed = false;
	#endif

	if (kbHandler.leftPressed())
	{
		#ifdef DEBUG
		cout << "Left key pressed ";
		keyPressed = true;
		#endif
	}
	if (kbHandler.rightPressed())
	{
		#ifdef DEBUG
		cout << "Right key pressed ";
		keyPressed = true;
		#endif
	}
	if (kbHandler.spacePressed())
	{
		#ifdef DEBUG
		cout << "Space bar pressed ";
		keyPressed = true;
		#endif
	}

	#ifdef DEBUG
	if (keyPressed)
	{
		cout << endl;
	}
	#endif

	//Update game objects
	for (int i = 0; i < gfxObjects.size(); i++)
	{
		if (gfxObjects[i] == nullptr)
			continue;

		if (gfxObjects[i]->outOfBounds(Point(0, 30), Point(640, 480)))
		{
			cout << "DELETING\n";
			delete gfxObjects[i];
			gfxObjects[i] = nullptr;
			continue;
		}

		gfxObjects[i]->update();
	}

}