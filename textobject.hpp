#ifndef TEXTOBJECT_HPP
#define TEXTOBJECT_HPP

#include "graphicsobject.hpp"
#include "point.hpp"

#include <SDL2/SDL_ttf.h>
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::cerr;
using std::endl;

#define DEFAULT_FONT_SIZE 16
#define DEFAULT_FONT_LOCATION "/usr/share/fonts/truetype/ubuntu-font-family/Ubuntu-R.ttf"
#define DEFAULT_TEXT "Set Me"

class TextObject : public GraphicsObject
{
private:
	string text;
	string fontLocation;
	int fontSize;

	TTF_Font* font;

	SDL_Texture* texture;
	SDL_Rect rect;

	//Helper function to update the font.
	void updateFont();

	//Convert a surface to a texture, freeing the surface in the meantime.
	SDL_Texture* surfaceToTexture(SDL_Surface* surface);

	//Generate a texture from a surface and auto fill its width and height to look pretty
	void createTextTexture();

public:
	TextObject(SDL_Renderer* r, const string& text, int fontSize, const Point& p);
	~TextObject();

	void setFont(const string& fontLocation);
	void setFontSize(const int fontSize);
	void setPoint(const Point& p);
	void setText(const string& text);
	void setColor(const SDL_Color& color);

	string getText() const { return text; }
	int getFontSize() const { return fontSize; }

	void draw();
	void update() {}

};

#endif