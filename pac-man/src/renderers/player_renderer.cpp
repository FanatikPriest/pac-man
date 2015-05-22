#include "player_renderer.h"

PlayerRenderer::PlayerRenderer(const Player& player, SDL_Renderer* renderer) : _player(player)
{
	_renderer             = renderer;
	_display_center_point = false;
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

	render_center_point();
}

void PlayerRenderer::render_center_point()
{
	if (!_display_center_point){
		return;
	}

	SDL_SetRenderDrawColor(_renderer, 0xFF, 0x00, 0x00, 0xFF); // red

	Vector2f position = _player.get_position();

	int x = (int) position.getX();
	int y = (int) position.getY();

	SDL_Rect rect = { x, y, 1, 1 };

	SDL_RenderFillRect(_renderer, &rect);
}