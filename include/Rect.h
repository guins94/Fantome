#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef RECT_HEADER
#define RECT_HEADER

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

#endif
