#include "GameTime.h"

GameTime* GameTime::instance = nullptr;

void GameTime::Initialize() {
	beginTime = std::chrono::system_clock().now();
	endTime = std::chrono::system_clock().now();
	deltaTime = std::chrono::duration<float>(0);
	totalTime = std::chrono::duration<float>(0);
	frameCount = 0;
}

void GameTime::Update() {
	endTime = std::chrono::system_clock().now();
	deltaTime = endTime - beginTime;
	beginTime = endTime;
	totalTime += deltaTime;
	frameCount++;
}