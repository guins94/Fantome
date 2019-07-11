#include"HolyLight.h"

HolyLight::HolyLight(GameObject* associated, bool isSFXEnabled)
{
  this->associated = associated;

  /* Initializing Control Variables */
  this->isSFXEnabled = isSFXEnabled;

  /* Adding HolyLight Sprite & Collider */
  Sprite* sprite = new Sprite(this->associated, "assets/img/holylight/holyLight.png", 22, 0.1, 0);
  this->associated->box.w = sprite->GetHeight();
  this->associated->box.h = sprite->GetWidth();
  this->associated->AddComponent(sprite);

  /* Adding HolyLight Collider */
  Collider* holyLightCollider = new Collider(this->associated, Vec2(1,1), Vec2(0,0));
  this->associated->AddComponent(holyLightCollider);

  /* Initializing Timer */
  this->soundCooldownTimer.Restart();

  /* Initializing HolyLight Sound */
  Sound* sound = new Sound(this->associated,"assets/SFX/light.ogg");
  this->lightSound = sound;
}

HolyLight::~HolyLight()
{

}

void HolyLight::Start()
{

}

void HolyLight::Update(float dt)
{
  /* Retrieving Fantome State Instance */
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();

  /* Updating SFX Cooldown Timer */
  this->soundCooldownTimer.Update(dt);

  /* Calculating Distance Between the HolyLight & Fantome */
  float distanceFromFantome = fantomeState->PlayerPosition.x - this->associated->box.x;

  /* If Fantome is Close Enough, Play the HolyLight SFX */
  if(fabs(distanceFromFantome) <= HOLYLIGHT_SFX_MIN_DISTANCE)
  {
    if(this->soundCooldownTimer.Get() >= HOLYLIGHT_SOUND_COOLDOWN)
    {
      if(this->isSFXEnabled)
      {
        this->lightSound->Play(1);
        this->soundCooldownTimer.Restart();
      }
    }
  }


}

void HolyLight::Render()
{

}

bool HolyLight::Is(std::string type)
{
  return (type == "HolyLight");
}

void HolyLight::NotifyCollision(GameObject& other)
{

}
