#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef FIREPLACE_HEADER
#define FIREPLACE_HEADER

class FirePlace : public Component{
  private:
    Vec2 speed = Vec2(0,0);
    Vec2 respawnPosition = Vec2(300,290);
    bool falling;
    Timer* restTimer;
    GameObject* player;
    Sound* fireSound;
    int checkID;
  public:
    FirePlace(GameObject* associated,int checkID);
  public:
    ~FirePlace();
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
