#include "player_renderer.h"

PlayerRenderer::PlayerRenderer(const Player& player, SDL_Renderer* renderer) : _player(player)
{
	_renderer = renderer;
}

void PlayerRenderer::render()
{
	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0x00, 0xFF); // yellow

	Vector2f position = _player.get_position();
	Size     size     = _player.get_size();

	int x = (int) (position.getX() - size.width / 2);
	int y = (int) (position.getY() - size.height / 2);

	SDL_Rect rect = { x, y, (int) size.width, (int) size.height };

	SDL_RenderFillRect(_renderer, &rect);
}