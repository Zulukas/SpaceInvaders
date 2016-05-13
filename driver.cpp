#include <iostream>
#include <new>
#include <string>
#include <unistd.h>

#include "gamewindow.hpp"
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

void mainloop() 
{
	while (gw->gameIsRunning())
	{
		gw->update();
		gw->draw();
	}
}

int main()
{
	try
	{
		gw = new GameWindow("Space Invaders", WIDTH, HEIGHT);

		mainloop();

		delete gw;
		
		gw = nullptr;
	}
	catch (const SDLError ex)
	{
		cerr << ex.message << endl;
		return ex.errorNum;
	}
	catch (bad_alloc& ba)
	{
		cerr << "Bad memory allocation: " << ba.what() << ". Terminating.\n";
		return 255;
	}

	return 0;
}