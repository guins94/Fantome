#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef POSSESSION_HEADER
#define POSSESSION_HEADER

enum Direction {LEFT=1, RIGHT =0, UP = 2,DOWN = 3};

class Possession : public Component{
  private:
    Vec2 speed = Vec2(0,0);
    bool falling;
    int nMinions;
    int nMovements;
    int direction;
    int hp;
    Timer* restTimer;
    GameObject* player;
  public:
    Possession(GameObject* associated, int direction);
  public:
    ~Possession();
  public:
    void Start();
  public:
    void Update(float dt);
  public:
    void Render();
  public:
    bool Is (std::string type);
  public:
    void NotifyCollision(GameObject& other);

};

#endif
