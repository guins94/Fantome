#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef INPUT_HEADER
#define INPUT_HEADER

class InputManager{
  private:
    bool mouseStageState[6];
    int mouseUpdate[6];
    std::unordered_map<int, bool> keyStageState;
    std::unordered_map<int, int> keyUpdate;
    bool quitRequested;
    int updateCounter;
    int mouseX;
    int mouseY;

  private:
    InputManager();
    //~InputManager();
  public:
    void Update();
  public:
    bool KeyPress(int key);
  public:
    bool KeyRelease(int key);
  public:
    bool IsKeyDown(int key);
  public:
    bool MousePress(int button);
  public:
    bool MouseRelease(int button);
  public:
    bool IsMouseDown(int button);
  public:
    int GetMouseX();
  public:
    int GetMouseY();
  public:
    bool QuitRequested();
  public:
    static InputManager* GetInstance();
};

#endif
