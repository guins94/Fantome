#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef CAMERA_HEADER
#define CAMERA_HEADER

class Camera{
  private:
    static GameObject* focus;
  public:
    static Vec2 pos;
    static Vec2 speed;
  public:
    static void Follow(GameObject* newFocus);
  public:
    static void Unfollow();
  public:
    static void Update(float dt);
};

#endif
