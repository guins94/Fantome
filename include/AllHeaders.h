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
  #define TITLE "danillo_140135839"
  #define WIDTH 1024
  #define HEIGHT 600

  #define PI 3.1415926535897
  #define UP_LIMIT 500
  #define COOLDOWN 3
  #define PROPORTION 0.2

  #define LEFT_ARROW_KEY SDLK_LEFT
  #define RIGHT_ARROW_KEY SDLK_RIGHT
  #define UP_ARROW_KEY SDLK_UP
  #define DOWN_ARROW_KEY SDLK_DOWN
  #define ESCAPE_KEY SDLK_ESCAPE
  #define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT
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

#include "Bullet.h"

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

#include "Chains.h"

#include "DeathGhost.h"

#include"BonePile.h"
