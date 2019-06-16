#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef VEC2_HEADER
#define VEC2_HEADER

class Vec2{
	public:
	float x, y;

	public:
    Vec2 operator+(const Vec2 rhs) const {
       return Vec2(x + rhs.x, y + rhs.y);
    }

    Vec2 operator-(const Vec2 rhs) const {
       return Vec2(x - rhs.x, y - rhs.y);
    }

    Vec2 operator*(const float rhs) const {
       return Vec2(x * rhs, y * rhs);
    }

	public:
		Vec2();
		Vec2(float x, float y);
	public:
		Vec2 GetRotated(float angle);
	public:
		void Speed(float x, float y, int mouseX, int mouseY);

};

#endif
