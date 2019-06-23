#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef GAMEDATA_HEADER
#define GAMEDATA_HEADER

class GameData{
  public:
    static unsigned counter;
    static Vec2 fantomeSpeed;
    static Vec2 boneFrogSpeed;
    static Vec2 DeathGhostSpeed;
    static float followLimit;

    static GameObject* ctrlObject;

    static float DegToRad(int deg){
      return(deg*(PI/180));
    }

    static int RadToDeg(float rad){
      return(rad*(180/PI));
    }
};

#endif
