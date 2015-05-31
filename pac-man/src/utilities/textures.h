#pragma once

#include <SDL.h>
#include <SDL_image.h>

/*
Manages the textures used in the game.
*/
class Textures
{
public:
	static bool initialize(SDL_Renderer* renderer);
	static void unload_textures();

	static SDL_Texture* PLAYER_TEXTURE;
	static SDL_Texture* GHOST_TEXTURE;
	static SDL_Texture* GHOST_FRIGHTENED_TEXTURE;
	static SDL_Texture* GHOST_EATEN_TEXTURE;

private:
	static SDL_Texture* load_texture(const char* path, SDL_Renderer* renderer);
};