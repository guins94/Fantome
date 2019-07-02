#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef CHECKPOINT_HEADER
#define CHECKPOINT_HEADER

class CheckPoint : public Component{
  private:
    Vec2 speed;
    Vec2 respawnPosition = Vec2(300,290);
    bool falling;
    Timer* restTimer;
    GameObject* player;
    Sound* fireSound;
    int checkID;
  public:
    CheckPoint(GameObject* associated, int checkID);
  public:
    ~CheckPoint();
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
