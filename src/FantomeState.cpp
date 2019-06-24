#include "FantomeState.h"

FantomeState::FantomeState(){
    /* Inicializando variáveis de estado */
    this->quitRequested = false;
    this->started = false;

    /* Adicionando música */
    this->backgroundMusic.Open("assets/fan_audio/FantomeBackGroundMusic.ogg");
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
    ParallaxScrolling* parallaxScrolling1 = new ParallaxScrolling(backgroundScreen1, 0.1, "assets/fan_img/bg_final_1.png", "assets/fan_map/backgroundMap.txt");
    backgroundScreen1->AddComponent(parallaxScrolling1);
    this->objectArray.emplace_back(backgroundScreen1);

    GameObject* backgroundScreen2 = new GameObject();
    backgroundScreen2->box.x = 0;
    backgroundScreen2->box.y = 0;
    ParallaxScrolling* parallaxScrolling2 = new ParallaxScrolling(backgroundScreen2, 0.2, "assets/fan_img/bg_final_2.png", "assets/fan_map/backgroundMap.txt");
    backgroundScreen2->AddComponent(parallaxScrolling2);
    this->objectArray.emplace_back(backgroundScreen2);

    GameObject* backgroundScreen3 = new GameObject();
    backgroundScreen3->box.x = 0;
    backgroundScreen3->box.y = 0;
    ParallaxScrolling* parallaxScrolling3 = new ParallaxScrolling(backgroundScreen3, 0.3, "assets/fan_img/bg_final_3.png", "assets/fan_map/backgroundMap.txt");
    backgroundScreen3->AddComponent(parallaxScrolling3);
    this->objectArray.emplace_back(backgroundScreen3);

    /* Adicionando efeitos de partículas e efeitos de luz *//*
    GameObject* backgroundScreen4 = new GameObject();
    backgroundScreen4->box.x = 0;
    backgroundScreen4->box.y = 0;
    ParallaxScrolling* parallaxScrolling4 = new ParallaxScrolling(backgroundScreen4, 1.05, "assets/fan_img/bg_final_4_particles.png", "assets/fan_map/backgroundMap.txt");
    backgroundScreen4->AddComponent(parallaxScrolling4);
    this->objectArray.emplace_back(backgroundScreen4);

    GameObject* backgroundScreen5 = new GameObject();
    backgroundScreen5->box.x = 0;
    backgroundScreen5->box.y = 0;
    ParallaxScrolling* parallaxScrolling5 = new ParallaxScrolling(backgroundScreen5, 1.1, "assets/fan_img/bg_final_5_light.png", "assets/fan_map/backgroundMap.txt");
    backgroundScreen5->AddComponent(parallaxScrolling5);
    this->objectArray.emplace_back(backgroundScreen5);
*/
    /* O GameObject goGround representa o chão do jogo */
    GameObject* goGround = new GameObject();
    goGround->box.w = 0;
    goGround->box.h = 5;
    goGround->box.x = 0;
    goGround->box.y = 0;
    TileSet* groundSet = new TileSet(314, 143, "assets/fan_img/floor_tileset.png");
    TileMap* groundMap = new TileMap(goGround, "assets/fan_map/tileMap.txt", groundSet, true);
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
    gravesprite->Open("assets/fan_img/tomb_1.png");
    gravesprite->SetClip(0,0, gravesprite->Sprite::GetHeight(),gravesprite->Sprite::GetWidth());
    grave->GameObject::AddComponent(gravesprite);
    Vec2 graveScale = Vec2(0,-100);
    Collider* grave_collider = new Collider(grave,graveScale);
    grave->GameObject::AddComponent(grave_collider);
    this->objectArray.emplace_back(grave);

    GameObject* grave2 = new GameObject();
    grave2->box.w = 130;
    grave2->box.h = 135;
    grave2->box.x = 0;
    grave2->box.y = 480;
    Grave* grave_component2 = new Grave(grave2);
    grave2->GameObject::AddComponent(grave_component2);
    Sprite* gravesprite2 = new Sprite(grave2);
    gravesprite2->Open("assets/fan_img/tomb_1.png");
    gravesprite2->SetClip(0,0, gravesprite2->Sprite::GetHeight(),gravesprite2->Sprite::GetWidth());
    grave2->GameObject::AddComponent(gravesprite2);
    Vec2 graveScale2 = Vec2(0,-100);
    Collider* grave_collider2 = new Collider(grave2,graveScale2);
    grave2->GameObject::AddComponent(grave_collider2);
    this->objectArray.emplace_back(grave2);

    GameObject* grave3 = new GameObject();
    grave3->box.w = 130;
    grave3->box.h = 135;
    grave3->box.x = 0;
    grave3->box.y = 280;
    Grave* grave_component3 = new Grave(grave3);
    grave3->GameObject::AddComponent(grave_component3);
    Sprite* gravesprite3 = new Sprite(grave3);
    gravesprite3->Open("assets/fan_img/tomb_1.png");
    gravesprite3->SetClip(0,0, gravesprite3->Sprite::GetHeight(),gravesprite3->Sprite::GetWidth());
    grave2->GameObject::AddComponent(gravesprite3);
    Vec2 graveScale3 = Vec2(0,-100);
    Collider* grave_collider3 = new Collider(grave3,graveScale3);
    grave3->GameObject::AddComponent(grave_collider3);
    this->objectArray.emplace_back(grave3);

    GameObject* boneFrog = new GameObject();
    boneFrog->box.w = 100;
    boneFrog->box.h = 30;
    boneFrog->box.x = 1000;
    boneFrog->box.y = 600;
    BoneFrog* boneFrog_component = new BoneFrog(boneFrog);
    boneFrog->GameObject::AddComponent(boneFrog_component);
    Sprite* boneFrogsprite = new Sprite(boneFrog);
    boneFrogsprite->Open("assets/img/cubngun.png");
    boneFrog->GameObject::AddComponent(boneFrogsprite);
    Collider* boneFrog_collider = new Collider(boneFrog);
    boneFrog->GameObject::AddComponent(boneFrog_collider);
    this->objectArray.emplace_back(boneFrog);
/*
    GameObject* deathGhost = new GameObject();
    deathGhost->box.w = 173;
    deathGhost->box.h = 158;
    deathGhost->box.x = 1000;
    deathGhost->box.y = 300;
    DeathGhost* deathGhost_component = new DeathGhost(deathGhost,0);
    deathGhost->GameObject::AddComponent(deathGhost_component);
    Collider* deathGhost_collider = new Collider(deathGhost);
    deathGhost->GameObject::AddComponent(deathGhost_collider);
    this->objectArray.emplace_back(deathGhost);
*/
    GameObject* deathGhost2 = new GameObject();
    deathGhost2->box.w = 173;
    deathGhost2->box.h = 158;
    deathGhost2->box.x = 3700;
    deathGhost2->box.y = 1100;
    DeathGhost* deathGhost_component2 = new DeathGhost(deathGhost2,0);
    deathGhost2->GameObject::AddComponent(deathGhost_component2);
    Collider* deathGhost_collider2 = new Collider(deathGhost2);
    deathGhost2->GameObject::AddComponent(deathGhost_collider2);
    this->objectArray.emplace_back(deathGhost2);

    GameObject* BonePilego = new GameObject();
    BonePilego->box.w = 50;
    BonePilego->box.h = 5;
    BonePilego->box.x = 2500;
    BonePilego->box.y = 500;
    BonePile* bonePile_component = new BonePile(BonePilego,300);
    BonePilego->GameObject::AddComponent(bonePile_component);
    Collider* BonePile_collider = new Collider(BonePilego);
    Vec2 offset_bonepile = Vec2(0,-60);
    BonePile_collider->SetOffset(offset_bonepile);
    BonePilego->GameObject::AddComponent(BonePile_collider);
    this->objectArray.emplace_back(BonePilego);

    /* Adding ChainHead (Beginning) */
GameObject* goChainHead = new GameObject();
goChainHead->box.x = 300 - goChainHead->box.w/2;
goChainHead->box.y = 500 - goChainHead->box.h/2;
ChainHead* chainHead = new ChainHead(goChainHead, 15, 0);
goChainHead->AddComponent(chainHead);
this->objectArray.emplace_back(goChainHead);

/* Adding ChainTail (End)*/
GameObject* goChainTail = new GameObject();
ChainTail* chainTail = new ChainTail(goChainTail, chainHead->GetAngle());
goChainTail->AddComponent(chainTail);
goChainTail->box.x = chainHead->GetLastChainPosition().x + chainHead->GetChainWidth();
goChainTail->box.y = chainHead->GetLastChainPosition().y - goChainTail->box.h/2;
this->objectArray.emplace_back(goChainTail);

    /* O GameObject goFantome representa o presonagem principal do jogo */
    GameObject* goFantome = new GameObject();
    goFantome->box.x = 300;
    goFantome->box.y = 290;

    Sprite* sprite = new Sprite(goFantome, 6, 0.1);
    sprite->Open("assets/fan_img/FANTOME PARADO - quadro de  96 px.png");
    goFantome->GameObject::AddComponent(sprite);
    goFantome->box.w = sprite->GetHeight();
    goFantome->box.h = sprite->GetWidth();
    Fantome* fantome_component = new Fantome(goFantome);
    goFantome->GameObject::AddComponent(fantome_component);

    Collider* fantome_collider = new Collider(goFantome);
    goFantome->GameObject::AddComponent(fantome_collider);
    //Vec2 offset = Vec2(0,120);
    //fantome_collider->SetOffset(offset);

    this->objectArray.emplace_back(goFantome);

    this->fantomeExist = true;

    /* Seguindo Fantome */
    Camera::Follow(goFantome);

}

FantomeState::~FantomeState(){
	this->objectArray.clear();
}

bool FantomeState::QuitRequested(){
    return this->quitRequested;
}

void FantomeState::LoadAssets(){

    /* Pré-Carregar os assets usados */
    GameObject* go = new GameObject();
    Sprite* sprite = new Sprite(go);
    sprite->Open("assets/fan_img/bg character.png");
    sprite->Open("assets/fan_img/bg test 2.png");
    sprite->Open("assets/fan_img/bg test 3.png");
    sprite->Open("assets/fan_img/bg test 4.png");
    sprite->Open("assets/fan_img/bg_test_2_pequeno.png");
    sprite->Open("assets/fan_img/bg_test_3_pequeno.png");
    sprite->Open("assets/fan_img/bg_test_4_pequeno.png");
    sprite->Open("assets/fan_img/bg_test_pequeno.png");
    sprite->Open("assets/fan_img/bg_test.png");
    sprite->Open("assets/fan_img/bg_test1.png");
    sprite->Open("assets/fan_img/fantasma_fantome.png");
    sprite->Open("assets/fan_img/floor_tile1.png");
    sprite->Open("assets/fan_img/floor_tile2.png");
    sprite->Open("assets/fan_img/floor_tile3.png");
    sprite->Open("assets/fan_img/floor_tileset.png");
    sprite->Open("assets/fan_img/tomb_1.png");

    Sound* sound = new Sound(go,"assets/fan_audio/Super Mario 64 - First Level (Super Mario 64 Theme).ogg");
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
  //for(std::vector<std::shared_ptr<GameObject>>::iterator it = this->objectArray.begin(); it!=this->objectArray.end(); it++){
    //if((*it).get() == go){
      //std::weak_ptr <GameObject > pointer = (*it);//std::make_shared<GameObject>();
      //return pointer;
    //}
  //}
  for(int x = 0; x<=this->objectArray.size() - 1; x++){
    if(this->objectArray[x].get() == go){
      std::weak_ptr <GameObject > pointer = this->objectArray[x];//std::make_shared<GameObject>();
      return pointer;
    }
  }
  return std::weak_ptr<GameObject>();
}

void FantomeState::Update(){
  Game* game = Game::GetInstance();
  float dt = game->GetDeltaTime();

  InputManager* inputManager = InputManager::GetInstance();

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
  for(int i = 0; i<=this->objectArray.size() - 1; i++){
    for(int j = 0;j<=this->objectArray.size() - 1; j++){
      if(i<j){
        collider_object = (Collider*)this->objectArray[i]->GetComponent("Collider");
        second_object = (Collider*)this->objectArray[j]->GetComponent("Collider");
        if(collider_object && second_object){
          if(Collision::IsColliding(collider_object->box, second_object->box, 0, 0)){
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
      //iti.get->GetComponent()
			(*iti)->RemoveComponent((*iti)->GetComponent("Component"));
      this->objectArray.erase(std::next(iti).base());
		}
	}
}

bool FantomeState::WillCollideWithGround(Rect& objectBox)
{
    for(int i = 0; i <= this->objectArray.size() - 1; i++)
    {
      Collider* secondObject = (Collider*) this->objectArray[i]->GetComponent("Collider");
      Ground* groundComponent = (Ground*) this->objectArray[i]->GetComponent("Ground");
      if(secondObject && groundComponent)
      {
        if(Collision::IsColliding(objectBox, secondObject->box, 0, 0)) return true;
      }
    }
    return false;
}

bool FantomeState::WillCollideWithGrave(Rect& objectBox)
{
    for(int i = 0; i <= this->objectArray.size() - 1; i++)
    {
      Collider* secondObject = (Collider*) this->objectArray[i]->GetComponent("Collider");
      Grave* groundComponent = (Grave*) this->objectArray[i]->GetComponent("Grave");
      if(secondObject && groundComponent)
      {
        if(Collision::IsColliding(objectBox, secondObject->box, 0, 0)) return true;
      }
    }
    return false;
}

void FantomeState::StartArray(){

}

void FantomeState::UpdateArray(float dt){

}

void FantomeState::RenderArray(){

}

bool FantomeState::PopRequested(){

}

void FantomeState::Pause(){

}

void FantomeState::Resume(){

}


/* most likely obsolete */

/*GameObject* surface = new GameObject();
surface->box.w = 2250;
surface->box.h = 10;
surface->box.x = 0;
surface->box.y = 500;
Surface* surface_component = new Surface(surface);
surface->GameObject::AddComponent(surface_component);
Collider* surface_collider = new Collider(surface);
surface->GameObject::AddComponent(surface_collider);
this->objectArray.emplace_back(surface);*/

/*  GameObject* surface2 = new GameObject();
surface2->box.w = 1000;
surface2->box.h = 2;
surface2->box.x = 2250;
surface2->box.y = 357;
Surface* surface_component2 = new Surface(surface2);
surface2->GameObject::AddComponent(surface_component2);
Collider* surface_collider2 = new Collider(surface2);
surface2->GameObject::AddComponent(surface_collider2);
this->objectArray.emplace_back(surface2);*/

//GameObject* ground = new GameObject();
//ground->box.w = 2000;
//ground->box.h = 5;
//ground->box.x = 0;
//ground->box.y = 500;

//Ground* ground_component = new Ground(ground);
//ground->GameObject::AddComponent(ground_component);

//TileSet* tile_set = new TileSet(64,64,"assets/img/tileset.png");
//TileMap* tile_map = new TileMap(ground,"assets/map/tileMap.txt",tile_set);
//ground->GameObject::AddComponent(tile_map);
//Collider* ground_collider = new Collider(ground);
//ground->GameObject::AddComponent(ground_collider);
//this->objectArray.emplace_back(ground);

/*
GameObject* new_tile = new GameObject();
new_tile->box.w = 30;
new_tile->box.h = 30;
new_tile->box.x = 0;
new_tile->box.y = 0;
//std::cout  << "entrando"<<std::endl;
TileSet* tile_set = new TileSet(64,64,"assets/img/tileset.png");
TileMap* tile_map = new TileMap(new_tile,"assets/map/tileMap.txt",tile_set);
new_tile->GameObject::AddComponent(tile_map);
Collider* tile_collider = new Collider(new_tile);
new_tile->GameObject::AddComponent(tile_collider);
this->objectArray.emplace_back(new_tile);
*/
/*
//this->music->Open("assets/audio/stageState.ogg");
//this->music->Play(-1);
//std::cout  <<"teste 1"<< std::endl;
GameObject* PenguinBody_go = new GameObject();
//PenguinBody_go->box.x = 704;
//PenguinBody_go->box.y = 640;
PenguinBody_go->box.x = 460;
PenguinBody_go->box.y = 300;
PenguinBody_go->box.w = 100;
PenguinBody_go->box.h = 50;
PenguinBody* penguinBody = new PenguinBody(PenguinBody_go);
PenguinBody_go->GameObject::AddComponent(penguinBody);
Collider* PenguinBody_collider = new Collider(PenguinBody_go);
PenguinBody_go->GameObject::AddComponent(PenguinBody_collider);
this->objectArray.emplace_back(PenguinBody_go);
*/
/*
GameObject* alien_go = new GameObject();
//alien_go->box.w = 100;
//alien_go->box.h = 100;
//std::cout << "weigth alien = "<<alien_go->box.w << std::endl;
alien_go->box.x = 512;
alien_go->box.y = 300;
alien_go->box.w = 160;
alien_go->box.h = 160;
Alien* alien = new Alien(alien_go,5,PenguinBody_go);
alien_go->GameObject::AddComponent(alien);
Collider* alien_collider = new Collider(alien_go);
alien_go->GameObject::AddComponent(alien_collider);
AddObject(alien_go);

GameObject* alien2_go = new GameObject();
//alien_go->box.w = 100;
//alien_go->box.h = 100;
//std::cout << "weigth alien = "<<alien_go->box.w << std::endl;
alien2_go->box.x = 1000;
alien2_go->box.y = 300;
alien2_go->box.w = 160;
alien2_go->box.h = 160;
Alien* alien2 = new Alien(alien2_go,2,PenguinBody_go);
alien2_go->GameObject::AddComponent(alien2);
Collider* alien2_collider = new Collider(alien2_go);
alien2_go->GameObject::AddComponent(alien2_collider);
AddObject(alien2_go);
*/
//Camera* camera = Camera::GetInstance();
//camera->Follow(PenguinBody_go);

/*  GameObject* backGround1 = new GameObject();
  backGround1->box.x = 0;
  backGround1->box.y = 0;
  ParallaxScrolling* parallax_background = new ParallaxScrolling(backGround1,0.4,"assets/fan_img/bg_test_2_pequeno.png","assets/fan_map/backgroundMap.txt");
  backGround1->GameObject::AddComponent(parallax_background);
  this->objectArray.emplace_back(backGround1);

  GameObject* backGround2 = new GameObject();
  backGround2->box.x = 0;
  backGround2->box.y = 0;
  ParallaxScrolling* parallax_background_2 = new ParallaxScrolling(backGround2,0.7,"assets/fan_img/bg_test_3_pequeno.png","assets/fan_map/backgroundMap.txt");
  backGround2->GameObject::AddComponent(parallax_background_2);
  this->objectArray.emplace_back(backGround2);

  GameObject* backGround3 = new GameObject();
  backGround3->box.x = 0;
  backGround3->box.y = 0;
  ParallaxScrolling* parallax_background_3 = new ParallaxScrolling(backGround3,0.9,"assets/fan_img/bg_test_4_pequeno.png","assets/fan_map/backgroundMap.txt");
  backGround3->GameObject::AddComponent(parallax_background_3);
  this->objectArray.emplace_back(backGround3);*/
