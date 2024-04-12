#include "TextRenderer.h"

TextRenderer::TextRenderer()
{
	_rect = new SDL_Rect();
	font = nullptr;
}

TextRenderer::TextRenderer(const char* newFont)
{
	_rect = new SDL_Rect();
	font = entity->scene->engine->assetWarehouse->GetFont(newFont);
}

void TextRenderer::Render(SDL_Renderer* renderer)
{
	if (font == nullptr || _rect == nullptr)
	{
		Debug::LogWarn("No font found for this textRenderer. This renderer will not display anything.", this);
		return;
	}

	// Alter the colour of the text to whatever the colour this renderer currently holds.
	SDL_SetTextureColorMod(font->glyphAtlas, colour.r, colour.g, colour.b);

	// Offsets the rendering rect so we can correctly place another character in the correct spot.
	int characterOffset = 0;

	// The character we are currently trying to render.
	int character;

	// The position of the glyph we are wanting to render.
	SDL_Rect* glyph;

	// Increments after rendering a character to tell the renderer to
	// move onto the next character.
	int i = 0;

	// We want to render the first character. So tell the renderer that.
	character = text[i++];

	while (character)
	{
		glyph = &font->glyphs[character];

		if(i != 1)
		{
			// Calculate spacing from the previous glyph width.
			characterOffset += _rect->w / 2;
		}

		_rect->w = (glyph->w * width * _transform->scale);
		_rect->h = (glyph->h * height * _transform->scale);

		_rect->x = roundf((_transform->GetX() * BAMT_WORLD_SCALE - _rect->w * 0.5f) * BAMT_WORLD_SCALE) / BAMT_WORLD_SCALE;
		_rect->y = roundf((_transform->GetY() * BAMT_WORLD_SCALE - _rect->h * 0.5f) * BAMT_WORLD_SCALE) / BAMT_WORLD_SCALE;

		// Calculate spacing from the current glyph width. This correctly spaces the next character.
		characterOffset += _rect->w / 2;

		_rect->x += characterOffset;

		SDL_RenderCopy(renderer, font->glyphAtlas, glyph, _rect);

		character = text[i++];
	}
}

void TextRenderer::SetFont(const char* newFont)
{
	font = entity->scene->engine->assetWarehouse->GetFont(newFont);
}

void TextRenderer::SetText(const char* newText)
{
	text = newText;
}