#pragma once

#ifndef _INPUTHANDLER_H_
#define _INPUTHANDLER_H_

#include "SDL.h"
#include <map>

enum InputKey {
	LEFT,
	RIGHT,
	UP,
	DOWN,
	FIRE
};

class InputHandler
{
private:
	std::map<InputKey, bool> inputMap;

public:
	InputHandler();

	void Update(bool* quit);

	bool GetKeyState(InputKey input);

	void SetKeyState(InputKey input, bool state);
};

#endif