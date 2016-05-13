#include "gamewindow.hpp"

// #define DEBUG

// #ifdef DEBUG

// #include <iostream>
// using namespace std;

// #endif

// #define TEXTFONT "font.ttf"

// GameWindow::GameWindow(const char* windowName, Uint16 width, Uint16 height) throw (const SDLError) : tb(nullptr)
// {
// 	this->windowName = (char*)windowName;
// 	this->width = width;
// 	this->height = height;

// 	manager = new FPSmanager;
// 	SDL_initFramerate(manager);
// 	SDL_setFramerate(manager, FRAMERATE);

// 	gameRunning = true;

// 	if (SDL_Init(SDL_INIT_VIDEO) != 0)
// 	{
// 		throw SDLError("SDL_Init Error: " + string(SDL_GetError()), 1);
// 	}

// 	window = SDL_CreateWindow((char*)windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

// 	if (window == nullptr)
// 	{
// 		throw SDLError("SDL_CreateWindow Error: " + string(SDL_GetError()), 2);
// 	}

// 	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

// 	if (renderer == nullptr)
// 	{
// 		throw SDLError("SDL_CreateRenderer Error: " + string(SDL_GetError()), 3);
// 	}

// 	TTF_Init();

// 	// fpsDisplay = new TextObject(
// 	// 	renderer, 
// 	// 	"Hello", 
// 	// 	24, 
// 	// 	"/usr/share/fonts/truetype/liberation/LiberationMono-Regular.ttf",
// 	// 	WHITE,
// 	// 	Point(),
// 	// 	50,
// 		// 50);

// 	tb = new Textbox(renderer, 400, 200, 25, 25);
// }

// GameWindow::~GameWindow()
// {
// 	if (tb != nullptr)
// 		delete tb;
// 	if (manager != nullptr)
// 		delete manager;
// 	// delete fpsDisplay;
// 	SDL_DestroyRenderer(renderer);
// 	SDL_DestroyWindow(window);
// 	SDL_Quit();
// }

// void GameWindow::draw()
// {
// 	tb->draw();

// 	TTF_Font* Sans = TTF_OpenFont("/usr/share/fonts/truetype/ubuntu-font-family/Ubuntu-R.ttf", 10); //this opens a font style and sets a size
// 	// TTF_Font* Sans = TTF_OpenFont("Tahoma.ttf", 10); //this opens a font style and sets a size

// 	if (Sans == nullptr)
// 	{
// 		cerr << "TTF_OpenFont: " << SDL_GetError() << endl;
// 		exit(6);
// 	}

// 	SDL_Color White = {255, 255, 255};  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color

// 	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "My text! this is really longer than it should be for this particular case...", White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

// 	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture

// 	SDL_Rect Message_rect; //create a rect
// 	Message_rect.x = 0;  //controls the rect's x coordinate 
// 	Message_rect.y = 0; // controls the rect's y coordinte
// 	Message_rect.w = 550; // controls the width of the rect
// 	Message_rect.h = 25; // controls the height of the rect

// //Mind you that (0,0) is on the top left of the window/screen, think a rect as the text's box, that way it would be very simple to understance

// //Now since it's a texture, you have to put RenderCopy in your game loop area, the area where the whole code executes

// 	SDL_RenderCopy(renderer, Message, NULL, &Message_rect); 
// 	SDL_RenderPresent(renderer);

// 	// //Draw the game
// 	// SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);
// 	// SDL_RenderClear(this->renderer);

// 	// SDL_SetRenderDrawColor(this->renderer, 0, 255, 0, 0);
// 	// SDL_RenderDrawLine(this->renderer, 50, 250, 250, 250);

// 	// fpsDisplay->draw();

// 	// SDL_RenderPresent(this->renderer);

// 	// //Enforce the framerate
// 	// #ifdef DEBUG
// 	// cout << manager->framecount % 10 << endl;
// 	// #endif
// 	SDL_framerateDelay(this->manager);
// }

// void GameWindow::update()
// {
// 	//Check for user input first
// 	while(SDL_PollEvent(&event))
// 	{
// 		if (event.type == SDL_QUIT)
// 		{
// 			gameRunning = false;
// 		}
// 	}

// 	#ifdef DEBUG
// 	bool keyPressed = false;
// 	#endif

// 	if (kbHandler.leftPressed())
// 	{
// 		#ifdef DEBUG
// 		cout << "Left key pressed ";
// 		keyPressed = true;
// 		#endif
// 	}
// 	if (kbHandler.rightPressed())
// 	{
// 		#ifdef DEBUG
// 		cout << "Right key pressed ";
// 		keyPressed = true;
// 		#endif
// 	}
// 	if (kbHandler.spacePressed())
// 	{
// 		#ifdef DEBUG
// 		cout << "Space bar pressed ";
// 		keyPressed = true;
// 		#endif
// 	}

// 	#ifdef DEBUG
// 	if (keyPressed)
// 	{
// 		cout << endl;
// 	}
// 	#endif

// 	//Update game objects


// }