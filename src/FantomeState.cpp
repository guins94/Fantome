#include<vector>
#include<iostream>
#include<memory>
#include<string>
#include<map>
#include<queue>
#include<algorithm>

#include"FantomeState.h"
#include"Face.h"
#include"Vec2.h"
#include"Sound.h"
#include"TileMap.h"
#include"InputManager.h"
#include"Camera.h"
#include"GAME.h"
#include"CameraFollower.h"
#include"Alien.h"
#include"Bullet.h"
#include"PenguinBody.h"
#include"PenguinCannon.h"
#include"Collider.h"
#include"EndState.h"
#include"Timer.h"
#include"TitleState.h"
#include"Ground.h"
#include"Fantome.h"


#include"SDL2/SDL.h"
#include"SDL2/SDL_image.h"
#include"SDL2/SDL_mixer.h"
#include"SDL2/SDL_ttf.h"


FantomeState::FantomeState(){
    this->quitRequested = false;
    this->started = false;

    GameObject* initial_screen = new GameObject();
    CameraFollower* cameraFollower = new CameraFollower(initial_screen);

    initial_screen->box.x = 0;
    initial_screen->box.y = 0;
    initial_screen->GameObject::AddComponent(cameraFollower);
    this->objectArray.emplace_back(initial_screen);

    GameObject* ground = new GameObject();
    ground->box.w = 2000;
    ground->box.h = 5;
    ground->box.x = 0;
    ground->box.y = 500;
    //Ground* ground_component = new Ground(ground);
    //ground->GameObject::AddComponent(ground_component);
    TileSet* tile_set = new TileSet(64,64,"assets/img/tileset.png");
    TileMap* tile_map = new TileMap(ground,"assets/map/tileMap.txt",tile_set);
    ground->GameObject::AddComponent(tile_map);
    Collider* ground_collider = new Collider(ground);
    ground->GameObject::AddComponent(ground_collider);
    this->objectArray.emplace_back(ground);

    GameObject* fantome = new GameObject();
    fantome->box.w = 146;
    fantome->box.h = 163;
    fantome->box.x = 200;
    fantome->box.y = 0;
    Fantome* fantome_component = new Fantome(fantome);
    fantome->GameObject::AddComponent(fantome_component);
    Collider* fantome_collider = new Collider(fantome);
    fantome->GameObject::AddComponent(fantome_collider);
    this->objectArray.emplace_back(fantome);
/*
    GameObject* backGround1 = new GameObject();
    Sprite* sprite = new Sprite(backGround1);
    sprite->Open("assets/img/bg_test_pequeno.png");
    backGround1->GameObject::AddComponent(sprite);
    this->objectArray.emplace_back(backGround1);

    GameObject* backGround2 = new GameObject();
    Sprite* sprite2 = new Sprite(backGround2);
    sprite2->Open("assets/img/bg_test_2_pequeno.png");
    backGround2->GameObject::AddComponent(sprite2);
    this->objectArray.emplace_back(backGround2);

    GameObject* backGround3 = new GameObject();
    Sprite* sprite3 = new Sprite(backGround3);
    sprite3->Open("assets/img/bg_test_3_pequeno.png");
    backGround3->GameObject::AddComponent(sprite3);
    this->objectArray.emplace_back(backGround3);

    GameObject* backGround4 = new GameObject();
    Sprite* sprite4 = new Sprite(backGround4);
    sprite2->Open("assets/img/bg_test_4_pequeno.png");
    backGround4->GameObject::AddComponent(sprite4);
    this->objectArray.emplace_back(backGround4);
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
}

FantomeState::~FantomeState(){
	this->objectArray.clear();
}

bool FantomeState::QuitRequested(){
    return this->quitRequested;
}

void FantomeState::LoadAssets(){

}


void FantomeState::Render(){
  for(int x = 0; x<=this->objectArray.size() - 1; x++){
    objectArray[x]->Render();
  }
}

void FantomeState::AddObject(int mouseX,int mouseY){
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

static inline float Mag(const Vec2& p) {
  return std::sqrt(p.x * p.x + p.y * p.y);
}

static inline Vec2 Norm(const Vec2& p) {
  return p * (1.f / Mag(p));
}

static inline float Dot(const Vec2& a, const Vec2& b) {
  return a.x * b.x + a.y * b.y;
}

static inline Vec2 Rotate(const Vec2& p, float angle) {
  float cs = std::cos(angle), sn = std::sin(angle);
  return Vec2 ( p.x * cs - p.y * sn, p.x * sn + p.y * cs );
}


// Observação: IsColliding espera ângulos em radianos!
// Para usar graus, forneça a sua própria implementação de Rotate,
// ou transforme os ângulos no corpo de IsColliding.
static inline bool IsColliding(Rect& a, Rect& b, float angleOfA, float angleOfB) {
  Vec2 A[] = { Vec2( a.x, a.y + a.h ),
          Vec2( a.x + a.w, a.y + a.h ),
          Vec2( a.x + a.w, a.y ),
          Vec2( a.x, a.y )
        };

        std::cout << "box Ax " << a.x<<std::endl;
        std::cout << "box Ay " << a.y<<std::endl;
        std::cout << "box Aw " << a.w<<std::endl;
        std::cout << "box Ah " << a.h<<std::endl;

  Vec2 B[] = { Vec2( b.x, b.y + b.h ),
          Vec2( b.x + b.w, b.y + b.h ),
          Vec2( b.x + b.w, b.y ),
          Vec2( b.x, b.y )
        };

        std::cout << "box Bx " << b.x<<std::endl;
        std::cout << "box By " << b.y<<std::endl;
        std::cout << "box Bw " << b.w<<std::endl;
        std::cout << "box Bh " << b.h<<std::endl;

  for (auto& v : A) {
    v = Rotate(v - a.GetCenter(), angleOfA) + a.GetCenter();
  }

  for (auto& v : B) {
    v = Rotate(v - b.GetCenter(), angleOfB) + b.GetCenter();
  }

  Vec2 axes[] = { Norm(A[0] - A[1]), Norm(A[1] - A[2]), Norm(B[0] - B[1]), Norm(B[1] - B[2]) };

  for (auto& axis : axes) {
    float P[4];

    for (int i = 0; i < 4; ++i) P[i] = Dot(A[i], axis);

    float minA = *std::min_element(P, P + 4);
    float maxA = *std::max_element(P, P + 4);

    for (int i = 0; i < 4; ++i) P[i] = Dot(B[i], axis);

    float minB = *std::min_element(P, P + 4);
    float maxB = *std::max_element(P, P + 4);

    if (maxA < minB || minA > maxB){
      std::cout << "nao COLIDINDO " << std::endl;
      return false;
    }
  }

  std::cout << "COLIDINDO " << std::endl;
  return true;
}

void FantomeState::Update(){
  InputManager* inputManager = InputManager::GetInstance();

  Camera* camera = Camera::GetInstance();
  Game* game = Game::getInstance();
  float dt = game->GetDeltaTime();
  camera->Update(dt);

	//for(std::vector<std::shared_ptr<GameObject>>::iterator it = this->objectArray.begin(); it!=this->objectArray.end(); it++){
		//(*it)->Update(dt);
	//}

  for(int x = 0; x<=this->objectArray.size() - 1; x++){
    objectArray[x]->Update(dt);
  }


  Collider* collider_object;
  Collider* second_object;
  for(int i = 0; i<=this->objectArray.size() - 1; i++){
    for(int j = 0;j<=this->objectArray.size() - 1; j++){
      if(i<j){
        std::cout << "testando colisão " << std::endl;
        collider_object = (Collider*)this->objectArray[i]->GetComponent("Collider");
        second_object = (Collider*)this->objectArray[j]->GetComponent("Collider");
        if(collider_object != nullptr && second_object != nullptr){
          if(IsColliding(collider_object->box,second_object->box,0,0) == true){
            this->objectArray[j]->NotifyCollision(*this->objectArray[i]);
            this->objectArray[i]->NotifyCollision(*this->objectArray[j]);
            collider_object = nullptr;
            second_object = nullptr;
          }
        }
      }
    }
  }

	std::vector<std::shared_ptr<GameObject>>::reverse_iterator iti = this->objectArray.rbegin();
	for(; iti!=this->objectArray.rend(); iti++){
	   if((*iti)->IsDead() == true){
      //iti.get->GetComponent()
			(*iti)->RemoveComponent((*iti)->GetComponent("Component"));
      this->objectArray.erase( std::next(iti).base());
		}
	}
/*
  if(nAliens <= 0){
    //game->Push(new EndState());
    //State::QuitRequested();
  }
*/
}
void FantomeState::StartArray(){

}

void FantomeState::UpdateArray(float dt){

}

void FantomeState::RenderArray(){

}

bool FantomeState::PopRequested(){

}

void FantomeState::Pause (){

}

void FantomeState::Resume (){

}
