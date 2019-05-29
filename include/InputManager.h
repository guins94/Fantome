
#include<unordered_map>

#define LEFT_ARROW_KEY  SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY  SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define ESCAPE_KEY  SDLK_ESCAPE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT

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
