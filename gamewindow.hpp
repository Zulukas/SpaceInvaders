#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

// #include <SDL2/SDL.h>
// #include <SDL2/SDL2_gfxPrimitives.h>
// #include <SDL2/SDL2_framerate.h>
// #include <SDL2/SDL_ttf.h>
// #include <iostream>
// #include <string>
// using std::cout;
// using std::endl;
// using std::string;

// #include "keyboardhandler.hpp"
// #include "graphicsobject.hpp"
// #include "textobject.hpp"
// // #include "textbox.hpp"
// #include "point.hpp"

// #define FRAMERATE 10
// #define FONTLOCATION "/usr/shared/fonts/truetype/liberation/LiberationMono-Regular.ttf"

// class SDLError
// {
// public:
// 	const string message;
// 	const int errorNum;

// 	SDLError(const string msg, const int errNum) : message(msg), errorNum(errNum) {}
// };

// class GameWindow
// {
// private:
// 	SDL_Window* window;
// 	SDL_Renderer* renderer;

// 	SDL_Event event;
// 	FPSmanager *manager;
// 	KeyboardHandler kbHandler;

// 	Uint16 width, height;
// 	char* windowName;

// 	bool gameRunning;

// 	// GraphicsObject* fpsDisplay;
// 	Textbox *tb;

// public: 
// 	GameWindow(const char* windowName, 
// 		Uint16 width, 
// 		Uint16 height) throw (const SDLError);
// 	~GameWindow();

// 	void draw();
// 	void update();

// 	bool gameIsRunning() const { return gameRunning; }
// };

#endif