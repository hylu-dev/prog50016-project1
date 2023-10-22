#pragma once

#ifndef _UI_DISPLAY_
#define _UI_DISPLAY_

class UIDisplay {
private:
	int lives = 0;
	int score = 0;
	int highScore = 0;

public:
	UIDisplay() = default;
	~UIDisplay() = default;

	void Update();

	int GetScore() { return score; }

	int GetHighScore() { return highScore; }

	void SetLives(int val) { lives = val; }

	void ResetScore() { score = 0; }

	void SetScore(int val) { score = val; }

	void SetHighScore(int val) { highScore = val; }

	void IncrementScore(int val = 1);

	void Load();
};

#endif