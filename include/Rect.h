#pragma once

#include"Vec2.h"

class Rect{
public:
	float x, y, w, h;

public:
	Rect();
public:
	bool Contains(float x, float y);
public:
	Vec2 GetCenter();
};
