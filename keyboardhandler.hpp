#ifndef KEYBOARDHANDLER_HPP
#define KEYBOARDHANDLER_HPP

#include <SDL2/SDL.h>

class KeyboardHandler
{
private:
	const Uint8* state;

public:
	KeyboardHandler() : state(SDL_GetKeyboardState(nullptr)) {}

	bool leftPressed()  const { return state[SDL_SCANCODE_LEFT]; }
	bool rightPressed() const { return state[SDL_SCANCODE_RIGHT]; }
	bool upPressed()    const { return state[SDL_SCANCODE_UP]; }
	bool downPressed()  const { return state[SDL_SCANCODE_DOWN]; }
	bool spacePressed() const { return state[SDL_SCANCODE_SPACE]; }
};

#endif