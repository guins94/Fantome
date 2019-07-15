#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef GAMEDATA_HEADER
#define GAMEDATA_HEADER

class GameData
{
  public:
    static Vec2 fantomeSpeed;
    static Vec2 boneFrogSpeed;
    static Vec2 DeathGhostSpeed;

    static float followLimit;

    /* Controls Game Conditions */
    /* TODO */
    static GameObject* player;

    /* Converts Degrees to Radians */
    static float DegToRad(int deg)
    {
      return(deg*(PI/180));
    }

    /* Converts Radians to Degrees */
    static int RadToDeg(float rad)
    {
      return(rad*(180/PI));
    }
};

#endif
