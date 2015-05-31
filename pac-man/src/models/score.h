#pragma once

/*
The score is an integer. Provides methods for setting and incrementing the score.
*/
class Score
{
public:
	Score();
	Score(int score);

	void set(const int score);
	int  get() const;

	void add(int points);

private:
	int _score;
};

inline Score::Score() : Score(0) {}

inline Score::Score(int score)
{
	set(score);
}

inline void Score::set(const int score)
{
	_score = score;
}

inline int Score::get() const
{
	return _score;
}

inline void Score::add(int points = 1)
{
	_score += points;
}