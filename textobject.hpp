#ifndef TEXTOBJECT_HPP
#define TEXTOBJECT_HPP

#include "graphicsobject.hpp"

#include <SDL2/SDL_ttf.h>

#include <string>
using std::string;

class TextObject : public GraphicsObject
{
private:
	string text;
	int fontSize;
	string fontLocation;

	int msgWidth, msgHeight;

	TTF_Font* textFont;
	SDL_Surface* messageSurface;
	SDL_Texture* message;
	SDL_Rect messageRectangle;

	bool hasChanged;

	void updateTextFont() { textFont = TTF_OpenFont(fontLocation.c_str(), fontSize); }

public:
	TextObject(SDL_Renderer* renderer, 
		const string text, 
		const int size, 
		const string font, 
		const SDL_Color color,
		const Point& p,
		const int msgWidth,
		const int msgHeight)
	{
		// GraphicsObject(renderer, color, p);
		this->renderer = renderer;
		this->text = text;
		this->fontSize = size;
		this->fontLocation = font;
		this->color = {255, 0, 0, 0};
		this->p = p;
		this->msgWidth = msgWidth;
		this->msgHeight = msgHeight;

		updateTextFont();

		messageRectangle.x = p.getX();
		messageRectangle.y = p.getY();
		messageRectangle.w = this->msgWidth;
		messageRectangle.h = this->msgHeight;
		
		messageSurface = TTF_RenderText_Solid(textFont, text.c_str(), color);

		hasChanged = false;
	}

	void draw()
	{
		SDL_RenderCopy(renderer, message, NULL, &messageRectangle);
	}

	void update() 
	{
		if (hasChanged)
		{
			updateTextFont();
			messageSurface = TTF_RenderText_Solid(textFont, text.c_str(), color);		
			hasChanged = false;	
		}
	}

	void setText(const string& text) 
	{ 
		this->text = text; 
		hasChanged = true; 
	}
	
	void setFontSize(const int size) 
	{ 
		this->fontSize = size; 
		updateTextFont(); 
		hasChanged = true; 
	}
	
	void setFont(const string& loc) 
	{ 
		this->fontLocation = loc; 
		updateTextFont(); 
		hasChanged = true; 
	}
	
	void setColor(const SDL_Color& color) 
	{ 
		this->color = color; 
		hasChanged = true; 
	}
	
	void setPoint(const Point& p) 
	{ 
		this->p = p; 
		hasChanged = true; 
	}

	void setRectangeWidthAndHeight(const int width, const int height)
	{
		this->msgWidth = width; 
		this->msgHeight = height;
		hasChanged = true;
	}

};

#endif