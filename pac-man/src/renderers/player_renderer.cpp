#include "player_renderer.h"
#include "score_renderer.h"

#include "../utilities/directions.h"
#include "../utilities/textures.h"

PlayerRenderer::PlayerRenderer(const Player& player, SDL_Renderer* renderer)
	: MovingObjectRenderer(player, renderer), _player(player)
{}

void PlayerRenderer::render()
{
	GameObjectRenderer::render();

	render_score();
}

SDL_Texture* PlayerRenderer::get_texture()
{
	return Textures::PLAYER_TEXTURE;
}

void PlayerRenderer::render_score()
{
	ScoreRenderer(_player._score, _renderer).render();
}

double PlayerRenderer::get_rotation_angle()
{
	Vector2f direction = _player.get_direction();

	if (direction == Directions::RIGHT)
	{
		return 0.0f;
	}
	else if (direction == Directions::DOWN)
	{
		return 90.0f;
	}
	else if (direction == Directions::LEFT)
	{
		return 180.0f;
	}
	else if (direction == Directions::UP)
	{
		return 270.0f;
	}

	return 0.0f;
}