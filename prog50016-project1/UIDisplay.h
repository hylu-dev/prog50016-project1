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

	void SetLives(int val) { lives = val; }

	void SetScore(int val) { score = val; }
	void IncrementScore() { score++; }

	void SetHighScore(int val) { highScore = val; }

	void Load();
};

#endif