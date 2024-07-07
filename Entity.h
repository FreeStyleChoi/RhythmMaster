#pragma once

#include "main.h"
#include "Vector.h"

class Entity
{
public:
	SDL_Rect rect = { 0 };
	Vector speed = { 0 };
	bool onScreen = false;
};

