#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef ENDSTATE_HEADER
#define ENDSTATE_HEADER

class EndState: public State{
private:
  Sprite* bg;
  bool started;
  Music backgroundMusic;
  std::vector< std::shared_ptr<GameObject>> objectArray;
private:
  void StartArray();
  void UpdateArray(float dt);
  void RenderArray();
  void Input();
public:
  EndState();
public:
  ~EndState();
public:
  bool QuitRequested();
public:
  void LoadAssets();
public:
  void Update();
public:
  void Render();
public:
  void Start();
public:
  void AddObject(int mouseX,int mouseY);
public:
  std::weak_ptr< GameObject > AddObject(GameObject* go);
public:
  std::weak_ptr< GameObject > GetObjectPtr(GameObject* go);
public:
  bool PopRequested();
public:
  void Pause ();
public:
  void Resume ();
};

#endif
