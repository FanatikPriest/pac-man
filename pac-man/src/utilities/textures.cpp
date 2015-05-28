#include "textures.h"

SDL_Texture* Textures::PLAYER_TEXTURE           = NULL;
SDL_Texture* Textures::GHOST_TEXTURE            = NULL;
SDL_Texture* Textures::GHOST_FRIGHTENED_TEXTURE = NULL;
SDL_Texture* Textures::GHOST_EATEN_TEXTURE      = NULL;

bool Textures::initialize(SDL_Renderer* renderer)
{
	int imgFlags = IMG_INIT_PNG;

	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		return false;
	}

	PLAYER_TEXTURE           = load_texture("data/pac-man.png", renderer);
	GHOST_TEXTURE            = load_texture("data/ghost.png", renderer);
	GHOST_FRIGHTENED_TEXTURE = load_texture("data/ghost_frightened.png", renderer);
	GHOST_EATEN_TEXTURE      = load_texture("data/ghost_eaten.png", renderer);

	return PLAYER_TEXTURE != NULL && GHOST_TEXTURE != NULL;
}

void Textures::unload_textures()
{
	SDL_DestroyTexture(GHOST_EATEN_TEXTURE);
	SDL_DestroyTexture(GHOST_FRIGHTENED_TEXTURE);
	SDL_DestroyTexture(GHOST_TEXTURE);
	SDL_DestroyTexture(PLAYER_TEXTURE);
}

SDL_Texture* Textures::load_texture(const char* path, SDL_Renderer* renderer)
{
	SDL_Surface* surface = IMG_Load(path);

	if (surface == NULL)
	{
		return NULL;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	if (texture == NULL)
	{
		return NULL;
	}

	SDL_FreeSurface(surface);

	return texture;
}