#ifndef SDL_LIB
#define SDL_LIB
  #include "SDL2/SDL.h"
  #include "SDL2/SDL_ttf.h"
  #include "SDL2/SDL_image.h"
  #include "SDL2/SDL_mixer.h"
  #include <iostream>
  #include <fstream>
  #include <string>
  #include <vector>
  #include <memory>
  #include <map>
  #include <random>
  #include <queue>
  #include <algorithm>
  #include <cmath>
  #include <stack>
  #include <unordered_map>
  #include <iomanip>
#endif

#ifndef DEFINE
  #define TITLE "Fantome Version 1"
  #define WIDTH 1024
  #define HEIGHT 600

  /* Constants */
  #define PI 3.1415926535897
  #define GRAVITY_ACC 50          // Gravity Acceleration
  #define GRAVITY_MIN_LIMIT 300   // Minimum Gravity
  #define GRAVITY_MAX_LIMIT 1000  // Maximum Gravity

  /* InputManager Defines */
  #define LEFT_ARROW_KEY SDLK_LEFT
  #define RIGHT_ARROW_KEY SDLK_RIGHT
  #define UP_ARROW_KEY SDLK_UP
  #define DOWN_ARROW_KEY SDLK_DOWN
  #define ESCAPE_KEY SDLK_ESCAPE
  #define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT

  /* Fantome Defines */
  #define CHAIN_TRAVEL_LIMIT 0.5  // Time (in seconds) it takes for Fantome to Travel Between Chains
  #define FANTOME_FLOAT_HEIGHT 10 // Fantome Distance to The Ground

  /* BoneFrog Defines */
  #define BONEFROG_JUMP_SPEED 1050 // BoneFrog Speed When It Jumps
  #define BONEFROG_JUMP_COOLDOWN 3  // BoneFrog Jump CoolDown (in seconds)

  /* Chain Defines */
  #define PLAYING_TIMER_VALUE 1.5 // Time (in seconds) for the Playing Timer

#endif

#include "Vec2.h"

#include "Rect.h"

#include "Music.h"

#include "Component.h"

#include "GameObject.h"

#include "Sound.h"

#include "Timer.h"

#include "Sprite.h"

#include "State.h"

#include "ParallaxScrolling.h"

#include "Surface.h"

#include "Possession.h"

#include "Grave.h"

#include "Fantome.h"

#include "Collision.h"

#include "FantomeState.h"

#include "Camera.h"

#include "CameraFollower.h"

#include "Collider.h"

#include "Game.h"

#include "InputManager.h"

#include "Resources.h"

#include "TileSet.h"

#include "TileMap.h"

#include "StageState.h"

#include "TitleState.h"

#include "Text.h"

#include "EndState.h"

#include "Ground.h"

#include "GameData.h"

#include "BoneFrog.h"

#include "DeathGhost.h"

#include "BonePile.h"

#include "HolyLight.h"

#include "ChainHead.h"

#include "ChainTail.h"

#include "Chain.h"

#include "Fire.h"

#include "Blade.h"

#include "CheckPoint.h"
