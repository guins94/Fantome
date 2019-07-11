#include "FantomeState.h"

FantomeState::FantomeState(){
    /* Initializing State Variables */
    this->quitRequested = false;
    this->started = false;

    /* Playing Stage Music */
    this->backgroundMusic.Open("assets/audio/FantomeBackGroundMusic.ogg");
    this->backgroundMusic.Play(-1);

    /* Adicionando imagens de fundo */
    //GameObject* backgroundScreen1 = new GameObject();
    //CameraFollower* cameraFollower = new CameraFollower(backgroundScreen1);
    //backgroundScreen1->box.x = 0;
    //backgroundScreen1->box.y = 0;
    //backgroundScreen1->AddComponent(cameraFollower);
    //this->objectArray.emplace_back(backgroundScreen1);

    GameObject* backgroundScreen1 = new GameObject();
    backgroundScreen1->box.x = 0;
    backgroundScreen1->box.y = 0;
    ParallaxScrolling* parallaxScrolling1 = new ParallaxScrolling(backgroundScreen1, 0.1, "assets/img/bg/finalBG1.png");
    backgroundScreen1->AddComponent(parallaxScrolling1);
    this->objectArray.emplace_back(backgroundScreen1);

    GameObject* backgroundScreen2 = new GameObject();
    backgroundScreen2->box.x = 0;
    backgroundScreen2->box.y = 0;
    ParallaxScrolling* parallaxScrolling2 = new ParallaxScrolling(backgroundScreen2, 0.2, "assets/img/bg/finalBG2.png");
    backgroundScreen2->AddComponent(parallaxScrolling2);
    this->objectArray.emplace_back(backgroundScreen2);

    GameObject* backgroundScreen3 = new GameObject();
    backgroundScreen3->box.x = 0;
    backgroundScreen3->box.y = 0;
    ParallaxScrolling* parallaxScrolling3 = new ParallaxScrolling(backgroundScreen3, 0.3, "assets/img/bg/finalBG3.png");
    backgroundScreen3->AddComponent(parallaxScrolling3);
    this->objectArray.emplace_back(backgroundScreen3);

    /*GameObject* backgroundScreen5 = new GameObject();
    backgroundScreen5->box.x = 0;
    backgroundScreen5->box.y = 0;
    ParallaxScrolling* parallaxScrolling5 = new ParallaxScrolling(backgroundScreen5, 1.1, "assets/img/bg/bg_final_5_light.png");
    this->objectArray.emplace_back(backgroundScreen5);*/

    /* O GameObject goGround representa o chão do jogo */
    GameObject* Tilemap = new GameObject();
    Tilemap->box.w = 0;
    Tilemap->box.h = 5;
    Tilemap->box.x = 0;
    Tilemap->box.y = 0;
    TileSet* TileSET = new TileSet(316,137, "assets/img/floor_tileset.png");
    TileMap* map = new TileMap(Tilemap, "assets/fan_map/tileMap.txt", TileSET, true);

    /* Adicionando componentes */
    Tilemap->AddComponent(map);
    this->objectArray.emplace_back(Tilemap);

  GameObject* goGround = new GameObject();
   goGround->box.w = 0;
   goGround->box.h = 5;
   goGround->box.x = 0;
   goGround->box.y = 0;
   TileSet* groundSet = new TileSet(314, 143, "assets/img/floor_tileset1.png");
   TileMapCollider* groundMap = new TileMapCollider(goGround, "assets/fan_map/tileMapCollider.txt", groundSet, true);
   Ground* ground = new Ground(goGround);

   /* Adicionando componentes */
   goGround->AddComponent(groundMap);
   goGround->AddComponent(ground);
   this->objectArray.emplace_back(goGround);

    GameObject* grave = new GameObject();
    grave->box.w = 130;
    grave->box.h = 135;
    grave->box.x = 3000;
    grave->box.y = 100;
    Grave* grave_component = new Grave(grave);
    grave->GameObject::AddComponent(grave_component);
    Sprite* gravesprite = new Sprite(grave);
    gravesprite->Open("assets/img/tomb_1.png");
    gravesprite->SetClip(0,0, gravesprite->GetHeight(),gravesprite->GetWidth());
    grave->GameObject::AddComponent(gravesprite);
    Collider* grave_collider = new Collider(grave, Vec2(1,1),Vec2(0,-100));
    grave->GameObject::AddComponent(grave_collider);
    this->objectArray.emplace_back(grave);

    GameObject* grave2 = new GameObject();
    grave2->box.w = 130;
    grave2->box.h = 135;
    grave2->box.x = 1700;
    grave2->box.y = 380;
    Grave* grave_component2 = new Grave(grave2);
    grave2->GameObject::AddComponent(grave_component2);
    Sprite* gravesprite2 = new Sprite(grave2);
    gravesprite2->Open("assets/img/tomb_1.png");
    gravesprite2->SetClip(0,0, gravesprite2->Sprite::GetHeight(),gravesprite2->Sprite::GetWidth());
    grave2->GameObject::AddComponent(gravesprite2);
    Collider* grave_collider2 = new Collider(grave2, Vec2(1,1),Vec2(0,-100));
    grave2->GameObject::AddComponent(grave_collider2);
    this->objectArray.emplace_back(grave2);

    GameObject* grave3 = new GameObject();
    grave3->box.w = 130;
    grave3->box.h = 135;
    grave3->box.x = 1700;
    grave3->box.y = 180;
    Grave* grave_component3 = new Grave(grave3);
    grave3->GameObject::AddComponent(grave_component3);
    Sprite* gravesprite3 = new Sprite(grave3);
    gravesprite3->Open("assets/img/tomb_1.png");
    gravesprite3->SetClip(0,0, gravesprite3->Sprite::GetHeight(),gravesprite3->Sprite::GetWidth());
    grave2->GameObject::AddComponent(gravesprite3);
    Collider* grave_collider3 = new Collider(grave3, Vec2(1,1),Vec2(0,-100));
    grave3->GameObject::AddComponent(grave_collider3);
    this->objectArray.emplace_back(grave3);

  /*  GameObject* grave4 = new GameObject();
    grave4->box.w = 130;
    grave4->box.h = 135;
    grave4->box.x = 600;
    grave4->box.y = 480;
    Grave* grave_component4 = new Grave(grave4);
    grave4->GameObject::AddComponent(grave_component4);
    Sprite* gravesprite4 = new Sprite(grave4);
    gravesprite4->Open("assets/img/tomb_1.png");
    gravesprite4->SetClip(0,0, gravesprite4->Sprite::GetHeight(),gravesprite4->Sprite::GetWidth());
    grave4->GameObject::AddComponent(gravesprite4);
    Collider* grave_collider4 = new Collider(grave4, Vec2(1,1),Vec2(0,-100));
    grave4->GameObject::AddComponent(grave_collider4);
    this->objectArray.emplace_back(grave4);*/

    GameObject* grave5 = new GameObject();
    grave5->box.w = 130;
    grave5->box.h = 135;
    grave5->box.x = 5700;
    grave5->box.y = 700;
    Grave* grave_component5 = new Grave(grave5);
    grave5->GameObject::AddComponent(grave_component5);
    Sprite* gravesprite5 = new Sprite(grave5);
    gravesprite5->Open("assets/img/tomb_1.png");
    gravesprite5->SetClip(0,0, gravesprite5->Sprite::GetHeight(),gravesprite5->Sprite::GetWidth());
    grave5->GameObject::AddComponent(gravesprite5);
    Vec2 graveScale5 = Vec2(0,-100);
    Collider* grave_collider5 = new Collider(grave5, Vec2(1,1), Vec2(1,1));
    grave5->GameObject::AddComponent(grave_collider5);
    this->objectArray.emplace_back(grave5);

    GameObject* boneFrog = new GameObject();
    boneFrog->box.w = 100;
    boneFrog->box.h = 30;
    boneFrog->box.x = 1000;
    boneFrog->box.y = 350;
    BoneFrog* boneFrog_component = new BoneFrog(boneFrog);
    boneFrog->GameObject::AddComponent(boneFrog_component);
    this->objectArray.emplace_back(boneFrog);

    /*GameObject* deathGhost = new GameObject();
    deathGhost->box.x = 800;
    deathGhost->box.y = 500;
    DeathGhost* deathGhost_component = new DeathGhost(deathGhost,0);
    deathGhost->AddComponent(deathGhost_component);
    Collider* deathGhost_collider = new Collider(deathGhost, Vec2(1,1), Vec2(0,0));
    deathGhost->AddComponent(deathGhost_collider);
    this->objectArray.emplace_back(deathGhost);

    GameObject* deathGhostSightGo = new GameObject;
    DeathGhostSight* deathGhostSight = new DeathGhostSight(deathGhostSightGo, deathGhost, deathGhost->box.w, deathGhost->box.h);
    deathGhostSightGo->AddComponent(deathGhostSight);
    this->objectArray.emplace_back(deathGhostSightGo);*/

    GameObject* deathGhost2 = new GameObject();
    deathGhost2->box.w = 173;
    deathGhost2->box.h = 158;
    deathGhost2->box.x = 3400;
    deathGhost2->box.y = 1100;
    DeathGhost* deathGhost_component2 = new DeathGhost(deathGhost2,0);
    deathGhost2->GameObject::AddComponent(deathGhost_component2);
    Collider* deathGhost_collider2 = new Collider(deathGhost2, Vec2(1,1), Vec2(0,0));
    deathGhost2->GameObject::AddComponent(deathGhost_collider2);
    this->objectArray.emplace_back(deathGhost2);

    GameObject* bonePileGo = new GameObject();
    bonePileGo->box.w = 50;
    bonePileGo->box.h = 5;
    bonePileGo->box.x = 2600;
    bonePileGo->box.y = 500;
    BonePile* bonePile_component = new BonePile(bonePileGo, 200);
    bonePileGo->AddComponent(bonePile_component);
    Collider* BonePile_collider = new Collider(bonePileGo, Vec2(1,1), Vec2(0,0));
    Vec2 offset_bonepile = Vec2(0,-60);
    BonePile_collider->SetOffset(offset_bonepile);
    bonePileGo->AddComponent(BonePile_collider);
    this->objectArray.emplace_back(bonePileGo);

    /* Adding ChainHead (Beginning) */
    /*GameObject* goChainHead = new GameObject();
    goChainHead->box.x = 500 - goChainHead->box.w/2;
    goChainHead->box.y = 450 - goChainHead->box.h/2;
    ChainHead* chainHead = new ChainHead(goChainHead, 5, 0);
    goChainHead->AddComponent(chainHead);
    this->objectArray.emplace_back(goChainHead);

    /* Adding ChainTail (End)*/
    /*GameObject* goChainTail = new GameObject();
    ChainTail* chainTail = new ChainTail(goChainTail, goChainHead, chainHead->GetAngle());
    goChainTail->AddComponent(chainTail);
    goChainTail->box.x = chainHead->GetLastChainPosition().x + chainHead->GetChainWidth();
    goChainTail->box.y = chainHead->GetLastChainPosition().y - goChainTail->box.h/2;
    this->objectArray.emplace_back(goChainTail);

    GameObject* holyLightGo = new GameObject();
    holyLightGo->box.w = 500;
    holyLightGo->box.h = 2000;
    holyLightGo->box.x = 4300;
    holyLightGo->box.y = 700;
    HolyLight* holyLight = new HolyLight(holyLightGo,100,100,1);
    holyLightGo->AddComponent(holyLight);
    Collider* holyLightCollider = new Collider(holyLightGo, Vec2(1,1), Vec2(0,0));
    holyLightGo->GameObject::AddComponent(holyLightCollider);
    this->objectArray.emplace_back(holyLightGo);*/

    /* Adding SoulStone */ //TODO: fiz MIX HALT CHANNEL SEGFAULT
    /*GameObject* soulStoneGo = new GameObject();
    soulStoneGo->box.x = 300;
    soulStoneGo->box.y = 500;
    SoulStone* soulStoneComponent = new SoulStone(soulStoneGo);
    soulStoneGo->AddComponent(soulStoneComponent);
    this->objectArray.emplace_back(soulStoneGo);*/

    GameObject* teleportationOrb1 = new GameObject();
    teleportationOrb1->box.w = 100;
    teleportationOrb1->box.h = 100;
    teleportationOrb1->box.x = 5200;
    teleportationOrb1->box.y = 1100;
    TeleportationOrb* teleportationOrb1_component = new TeleportationOrb(teleportationOrb1,1);
    teleportationOrb1->GameObject::AddComponent(teleportationOrb1_component);
    Collider* teleportationOrb1_collider = new Collider(teleportationOrb1, Vec2(1,1), Vec2(1,1));
    teleportationOrb1->GameObject::AddComponent(teleportationOrb1_collider);
    this->objectArray.emplace_back(teleportationOrb1);

    GameObject* teleportationOrb2 = new GameObject();
    teleportationOrb2->box.w = 100;
    teleportationOrb2->box.h = 100;
    teleportationOrb2->box.x = 7400;
    teleportationOrb2->box.y = 300;
    TeleportationOrb* teleportationOrb2_component = new TeleportationOrb(teleportationOrb2,2);
    teleportationOrb2->GameObject::AddComponent(teleportationOrb2_component);
    Collider* teleportationOrb2_collider = new Collider(teleportationOrb2, Vec2(1,1), Vec2(1,1));
    teleportationOrb2->GameObject::AddComponent(teleportationOrb2_collider);
    this->objectArray.emplace_back(teleportationOrb2);

    /* Adding Game CheckPoints */
    GameObject* checkPointGo = new GameObject();
    checkPointGo->box.x = 150;
    checkPointGo->box.y = 500;
    CheckPoint* checkPoint = new CheckPoint(checkPointGo, 0);
    checkPointGo->AddComponent(checkPoint);
    this->objectArray.emplace_back(checkPointGo);

    GameObject* checkPointGo2 = new GameObject();
    checkPointGo2->box.x = 3500;
    checkPointGo2->box.y = 70;
    CheckPoint* checkPoint2 = new CheckPoint(checkPointGo2, 1);
    checkPointGo2->AddComponent(checkPoint2);
    this->objectArray.emplace_back(checkPointGo2);

    GameObject* checkPointGo3 = new GameObject();
    checkPointGo3->box.x = 6400;
    checkPointGo3->box.y = 500;
    CheckPoint* checkPoint3 = new CheckPoint(checkPointGo3, 1);
    checkPointGo3->AddComponent(checkPoint3);
    this->objectArray.emplace_back(checkPointGo3);

    /*GameObject* initial = new GameObject();
    initial->box.w = 100;
    initial->box.h = 100;
    initial->box.x = 300;
    initial->box.y = 500;
    Sprite* initialsprite = new Sprite(initial);
    initialsprite->Open("assets/img/tomb_1.png");
    initial->GameObject::AddComponent(initialsprite);
    InitialStone* initial_component = new InitialStone(initial);
    initial->GameObject::AddComponent(initial_component);
    Collider* initial_collider = new Collider(initial, Vec2(0,0), Vec2(1,1));
    initial->GameObject::AddComponent(initial_collider);
    this->objectArray.emplace_back(initial);*/

    /* Adding Fantome Object */
    GameObject* goFantome = new GameObject();
    goFantome->box.x = 300;
    goFantome->box.y = 280;

    Fantome* fantome = new Fantome(goFantome);
    goFantome->GameObject::AddComponent(fantome);

    Collider* fantomeCollider = new Collider(goFantome, Vec2(1,1), Vec2(0,0));
    goFantome->AddComponent(fantomeCollider);

    this->objectArray.emplace_back(goFantome);

    this->fantomeExist = true;

    /* Seguindo Fantome */
    Camera::Follow(goFantome);
    //Camera::Follow(initial);

    /* Adding Particles & Light Effects */
    GameObject* particlesGo = new GameObject();
    CameraFollower* cameraFollower = new CameraFollower(particlesGo);
    particlesGo->AddComponent(cameraFollower);
    Sprite* particleSprite = new Sprite(particlesGo, "assets/img/bg/particles.png", 16, 0.2, 0);
    particlesGo->AddComponent(particleSprite);
    Sprite* lightSprite = new Sprite(particlesGo, "assets/img/bg/light.png", 27, 0.1, 0);
    particlesGo->AddComponent(lightSprite);
    this->objectArray.emplace_back(particlesGo);
}

FantomeState::~FantomeState(){
	this->objectArray.clear();
}

bool FantomeState::QuitRequested(){
    return this->quitRequested;
}

void FantomeState::LoadAssets()
{
  /* TODO: Pre-Load Used Assets */
}


void FantomeState::Render(){
  for(int x = 0; x<=this->objectArray.size() - 1; x++){
    objectArray[x]->Render();
  }
}

void FantomeState::AddObject(int mouseX, int mouseY){
}

void FantomeState::Start(){

  for(int i = 0;i <= this->objectArray.size() -1; i++){
    //std::cout << "start em StageState \n"<< std::endl;
    this->objectArray[i]->Start();
  }
  this->started = true;
}

std::weak_ptr<GameObject> FantomeState::AddObject(GameObject* go){

  //std::shared_ptr< GameObject > gameObject = std::make_shared<GameObject>();
  auto gameObject = std::shared_ptr<GameObject>(go);
  this->objectArray.emplace_back(gameObject);
  std::weak_ptr <GameObject > pointer = gameObject;
  //std::cout << "Entrando em ADDOBJECT\n" << std::endl;
  if(this->started == true){
    //std::cout << "add object StageState\n" << std::endl;
    go->Start();
    //std::cout << "testando started\n" << std::endl;
    //std::weak_ptr <GameObject > pointer = this->GetObjectPtr(go);
    //return pointer;
  }
  return pointer;

  //return std::weak_ptr<GameObject>();
}

std::weak_ptr<GameObject> FantomeState::GetObjectPtr(GameObject* go){
  for(int x = 0; x<=this->objectArray.size() - 1; x++){
    if(this->objectArray[x].get() == go){
      std::weak_ptr <GameObject > pointer = this->objectArray[x];//std::make_shared<GameObject>();
      return pointer;
    }
  }
  return std::weak_ptr<GameObject>();
}

void FantomeState::Update()
{
  /* Retrieving Input Manager & Game Instances*/
  Game* game = Game::GetInstance();
  InputManager* inputManager = InputManager::GetInstance();

  /* Retrieving Game Delta Time */
  float dt = game->GetDeltaTime();

  /* If ESCAPE is pressed, Exit Fantome */
  if(!inputManager->KeyRelease(ESCAPE_KEY))
  {
    std::cout << "FANTOME POP REQUEST" << '\n';
    this->popRequested = true;
  }

  /* If The Player Tries to Close The Window, Exit Game */
  if(inputManager->QuitRequested())
  {
    std::cout << "FANTOME QUIT REQUEST" << '\n';
    this->quitRequested = true;
  }

  /* Calling Camera Update */
  Camera::Update(dt);

  for(int f = 0; f<=this->objectArray.size() - 1; f++){
    Fantome* fantome = (Fantome*)this->objectArray[f]->GetComponent("Fantome");
    if(fantome != nullptr){
      PlayerPosition.x = this->objectArray[f]->box.x;
      PlayerPosition.y = this->objectArray[f]->box.y;
    }
  }

  //std::cout << "PlayerPosition" <<PlayerPosition.x<<"    - "<<PlayerPosition.y << '\n';

  Collider* collider_object;
  Collider* second_object;
  float angleOfA, angleOfB;
  for(int i = 0; i<=this->objectArray.size() - 1; i++){
    for(int j = 0;j<=this->objectArray.size() - 1; j++){
      if(i<j){
        collider_object = (Collider*)this->objectArray[i]->GetComponent("Collider");
        second_object = (Collider*)this->objectArray[j]->GetComponent("Collider");
        angleOfA = GameData::DegToRad(this->objectArray[i]->angleDeg);
        angleOfB = GameData::DegToRad(this->objectArray[j]->angleDeg);
        if(collider_object && second_object){
          if(Collision::IsColliding(collider_object->box, second_object->box, angleOfA, angleOfB)){
            this->objectArray[j]->NotifyCollision(*this->objectArray[i]);
            this->objectArray[i]->NotifyCollision(*this->objectArray[j]);
            collider_object = nullptr;
            second_object = nullptr;
          }
        }
      }
    }
  }

  for(int x = 0; x<=this->objectArray.size() - 1; x++){
    objectArray[x]->Update(dt);
  }

	std::vector<std::shared_ptr<GameObject>>::reverse_iterator iti = this->objectArray.rbegin();
	for(; iti!=this->objectArray.rend(); iti++){
	   if((*iti)->IsDead() == true){
			(*iti)->RemoveComponent((*iti)->GetComponent("Component"));
      this->objectArray.erase(std::next(iti).base());
		}
	}
}

bool FantomeState::WillCollideWithGround(Rect& objectBox, float angleRad)
{
    for(int i = 0; i <= this->objectArray.size() - 1; i++)
    {
      Collider* secondObject = (Collider*) this->objectArray[i]->GetComponent("Collider");
      Ground* groundComponent = (Ground*) this->objectArray[i]->GetComponent("Ground");
      float secondAngle = GameData::DegToRad(this->objectArray[i]->angleDeg);
      if(secondObject && groundComponent)
        if(Collision::IsColliding(objectBox, secondObject->box, angleRad, secondAngle))
          return true;
    }
    return false;
}

bool FantomeState::WillCollideWithGrave(Rect& objectBox, float angleRad)
{
    for(int i = 0; i <= this->objectArray.size() - 1; i++)
    {
      Collider* secondObject = (Collider*) this->objectArray[i]->GetComponent("Collider");
      Grave* groundComponent = (Grave*) this->objectArray[i]->GetComponent("Grave");
      float secondAngle = GameData::DegToRad(this->objectArray[i]->angleDeg);
      if(secondObject && groundComponent)
        if(Collision::IsColliding(objectBox, secondObject->box, angleRad, secondAngle))
          return true;
    }
    return false;
}

void FantomeState::StartArray()
{

}

void FantomeState::UpdateArray(float dt)
{

}

void FantomeState::RenderArray()
{

}

bool FantomeState::PopRequested()
{

}

void FantomeState::Pause()
{

}

void FantomeState::Resume()
{

}
