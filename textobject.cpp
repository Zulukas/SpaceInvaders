#include "textobject.hpp"

//PUBLIC MEMBER METHODS

TextObject::TextObject(SDL_Renderer* r, const string& text, int fontSize, const Point& p)
{
	this->renderer = r;
	cout << "TextObject Renderer: " << this->renderer << endl;
	this->fontLocation = DEFAULT_FONT_LOCATION;
	this->fontSize = fontSize;
	this->p = p;
	this->text = text;

	texture = nullptr;

	updateFont();
	createTextTexture();
}

TextObject::~TextObject()
{
	if (texture != nullptr)
		SDL_DestroyTexture(texture);
}

void TextObject::draw()
{
	SDL_RenderCopy(renderer, texture, nullptr, &rect);
	SDL_RenderPresent(renderer);
}

void TextObject::setPoint(const Point& p)
{
	this->p = p;
	createTextTexture();
}

void TextObject::setFontSize(const int fontSize)
{
	this->fontSize = fontSize;
	createTextTexture();
}

void TextObject::setText(const string& text)
{
	this->text = text;
	createTextTexture();
}

void TextObject::setFont(const string& fontLocation)
{
	this->fontLocation = fontLocation;
	createTextTexture();
}

void TextObject::setColor(const SDL_Color& color)
{
	this->color = color;
	createTextTexture();
}

// PRIVATE MEMBER METHODS //

void TextObject::updateFont()
{
	font = TTF_OpenFont(fontLocation.c_str(), fontSize);

	if (font == nullptr)
	{
		cerr << __LINE__ << " TTF_OpenFont Error: " << SDL_GetError() << endl;
		exit(5);
	}
}

SDL_Texture* TextObject::surfaceToTexture(SDL_Surface* surface)
{
	SDL_Texture *text = SDL_CreateTextureFromSurface(renderer, surface);;
	SDL_FreeSurface(surface);

	return text;
}

void TextObject::createTextTexture()
{
	if (texture != nullptr)
		SDL_DestroyTexture(texture);

	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
	texture = surfaceToTexture(surface);

	SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
	rect.x = p.getX();
	rect.y = p.getY();
}