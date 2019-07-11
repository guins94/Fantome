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
  #define SPACE_KEY SDLK_SPACE
  #define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT

  /* Menu Defines */
  #define MENU_EXIT_TIME 2.5 // Time (in seconds) it Takes to Quit the Menu
  #define MENU_OPTION_CHANGE_COOLDOWN 1 // Time (in seconds) Allowed to Change Options in The Menu

  /* Fantome Defines */
  #define CHAIN_TRAVEL_LIMIT 0.5  // Time (in seconds) it takes for Fantome to Travel Between Chains
  #define FANTOME_FLOAT_HEIGHT 10 // Fantome Distance to The Ground

  /* BoneFrog Defines */
  #define BONEFROG_HITPOINTS 1 // BoneFrog Hit Points
  #define BONEFROG_JUMP_SPEED 1050 // BoneFrog Speed When It Jumps
  #define BONEFROG_JUMP_COOLDOWN 3  // BoneFrog Jump CoolDown (in seconds)
  #define WILD_BONEFROG_MAX_WALK_DISTANCE 200 // Wild BoneFrog Maximum Walk Distance

  /* Chain Defines */
  #define PLAYING_TIMER_VALUE 1.5 // Time (in seconds) for the Playing Timer

  /* SoulStone Defines */
  #define NEARBY_SOULSTONE_DISTANCE 300 // Maximum Distance (in pixels) that Indicates Fantome is Nearby
  #define SOULSTONE_SOUND_LOOP 5 // Time (in seconds) Between SoulStone Sound Effects

  /* DeathGhost Defines */
  #define DEATH_GHOST_VISION_RANGE 500 // Maximum Distance (in pixels) that DeathGhost Can See
  #define DEATH_GHOST_PRESENCE 250 // Maximum Distance (in pixels) that DeathGhost Feels Fantome Presence
  #define DEATH_GHOST_ATTACK_RANGE 100 //Maximum Distance (in pixels) that DeathGhost Starts Charging its Attack

  /* HolyLight Defines */
  #define HOLYLIGHT_SOUND_COOLDOWN 6 // Time (in seconds) Between Holylight SFX
  #define HOLYLIGHT_SFX_MIN_DISTANCE 500 // Minimum Distance (in pixels) To Start Playing the HolyLight SFX
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

#include "DeathGhostSight.h"

#include "BonePile.h"

#include "HolyLight.h"

#include "ChainHead.h"

#include "ChainTail.h"

#include "Chain.h"

#include "SoulStone.h"

#include "Blade.h"

#include "CheckPoint.h"

#include "TileMapCollider.h"

#include "TeleportationOrb.h"

#include "Exit.h"

#include "InitialStone.h"
