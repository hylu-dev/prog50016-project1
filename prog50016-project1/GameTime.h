#pragma once

#ifndef _GAME_TIME_H_
#define _GAME_TIME_H_

#include <chrono>
#include <random>

class GameTime
{
public:
	inline static GameTime& Get() {
		if (instance == nullptr) {
			instance = new GameTime();
		}
		return *instance;
	}

	inline void Destroy() {
		if (instance != nullptr) {
			delete instance;
			instance = nullptr;
		}
	}

	void Update();

	float DeltaTime() { return deltaTime.count(); };
	float TotalTime() { return totalTime.count(); };
	unsigned int FrameCount() { return frameCount; };
	float Rand() { return dis(rng); };

private:
	inline void Initialize();

private:
	int frameCount = 0;
	std::chrono::duration<float> deltaTime = std::chrono::duration<float>(0.0f);
	std::chrono::duration<float> totalTime = std::chrono::duration<float>(0.0f);
	std::chrono::time_point<std::chrono::system_clock> beginTime;
	std::chrono::time_point<std::chrono::system_clock> endTime;

	std::random_device rd;
	std::mt19937 rng = std::mt19937(rd());
	std::uniform_real_distribution<float> dis = std::uniform_real_distribution<float>(0, 1);;

	static GameTime* instance;
private:
	explicit GameTime() = default;
	~GameTime() = default;
	inline explicit GameTime(GameTime const&) = delete;
	inline GameTime& operator=(GameTime const&) = delete;
};

#endif