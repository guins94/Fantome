#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef CAMFOLLOW_HEADER
#define CAMFOLLOW_HEADER

class CameraFollower : public Component{
  public:
    CameraFollower(GameObject* go);
  public:
    void Update(float dt);
  public:
    void Render();
  public:
    void Start();
  public:
    bool Is(std::string type);
};

#endif
