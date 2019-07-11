#include "Chain.h"

Chain::Chain(GameObject* associated, GameObject* chainHead, int chainCode) : Component(associated)
{
  this->associated = associated;
  this->travelCooldown = new Timer();
  this->chainCode = chainCode;
  this->isPlaying = false;
  this->wasCurrentChainModified = false;

  if(chainHead)
  this->chainHead = (ChainHead*) chainHead->GetComponent("ChainHead");

  /* Adicionando Sprite */
  Sprite* sprite = new Sprite(associated, 1, 0);
  sprite->Open("assets/img/chain/chain.png");
  this->associated->box.w = sprite->GetHeight();
  this->associated->box.h = sprite->GetWidth();
  this->associated->AddComponent(sprite);

  /* Adicionando Collider */
  Collider* collider = new Collider(associated, Vec2(1,1), Vec2(0,0));
  this->associated->AddComponent(collider);
}

Chain::~Chain()
{

}

int Chain::GetChainCode()
{
  return this->chainCode;
}

void Chain::Update(float dt)
{

  if(!this->chainHead) return;

  if(this->chainCode != this->chainHead->currentChain) this->isPlaying = false;

  /* Getting The Chain Sprite */
  Sprite* sprite = (Sprite*) this->associated->GetComponent("Sprite");

  if(this->isPlaying)
  {
    if(this->chainCode == 1)
    std::cout << "chaincode: " << this->chainCode << " " << this->chainHead->currentChain << '\n';

    /* Updating Chain Travel Cooldown Timer */
    this->travelCooldown->Update(dt);

    /* Setting Scale Up */
    sprite->SetScaleX(2); sprite->SetScaleY(2);
  }
  else
  {
    /* The Timer Keeps At Zero Until Fantome Possesses This Chain */
    this->travelCooldown->Restart();

    /* Setting Scale Back to Normal*/
    sprite->SetScaleX(1); sprite->SetScaleY(1);
  }
}

void Chain::Render()
{

}

void Chain::Start()
{

}

bool Chain::Is(std::string type)
{
  if(type == "Chain")
    return true;
  else
    return false;
}

void Chain::NotifyCollision(GameObject& other)
{
  /* Retrieving InputManager Instance */
  InputManager* inputManager = InputManager::GetInstance();

  /* Retrieving FantomeState */
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();

  /* Resolving Chain Collision With Another Chain */
  if(Chain* chain = (Chain*) other.GetComponent("Chain"))
  {
    /* If ChainHead Is Being Controlled by Fantome */
    if(this->isPlaying)
    {std::cout << "Playing Chain Code: " << this->chainCode << '\n';
      if(!inputManager->KeyRelease(SDLK_d) && this->travelCooldown->Get() >= CHAIN_TRAVEL_LIMIT)
      {std::cout << "Yeah, going right! " << this->chainCode << '\n';

        /* Increments currentChain value */
        if(!this->wasCurrentChainModified)
        {
          this->chainHead->currentChain++;
          this->wasCurrentChainModified = true;
        }

        /* If currentChain is a valid value for a chain */
        if(this->chainHead->currentChain >= 0 && this->chainHead->currentChain < this->chainHead->chainArray.size())
        {std::cout << "Valid currentChain value! " << this->chainHead->currentChain << " Other chaincode: " << chain->GetChainCode() << '\n';
          /* If The Chain Has The Right Code, Start Following It */
          if(chain->GetChainCode() == this->chainHead->currentChain)
          {std::cout << "This means the chain we want is: " << chain->GetChainCode() << " and the current chain is " << this->chainHead->currentChain << '\n';
            /* Restarting Travel Timer */
            this->travelCooldown->Restart();

            /* Retrieve Chain Sprite and Scale It Up */
            Sprite* sprite = (Sprite*) this->chainHead->chainArray[this->chainHead->currentChain].lock().get()->GetComponent("Sprite");
            sprite->SetScaleX(2); sprite->SetScaleY(2);
            this->isPlaying = false;
            this->wasCurrentChainModified = false;
            chain->isPlaying = true;
            chain->travelCooldown->Restart();
            Camera::Follow(&other);
          }
        }
      }

      if(!inputManager->KeyRelease(SDLK_a) && this->travelCooldown->Get() >= CHAIN_TRAVEL_LIMIT && this->chainCode != 0)
      {
        /* Restart Timer */
        this->travelCooldown->Restart();

        /* Increments currentChain value */
        if(!this->wasCurrentChainModified)
        {
          this->chainHead->currentChain--;
          this->wasCurrentChainModified = true;
        }

        /* If currentChain is a valid value for a chain */
        if(this->chainHead->currentChain >= 0 && this->chainHead->currentChain < this->chainHead->chainArray.size())
        {
          /* If The Chain Has The Right Code, Start Following It */
          if(chain->GetChainCode() == this->chainHead->currentChain)
          {
            /* Retrive Chain Sprite and Scale It */
            Sprite* sprite = (Sprite*) this->chainHead->chainArray[this->chainHead->currentChain].lock().get()->GetComponent("Sprite");
            sprite->SetScaleX(2); sprite->SetScaleY(2);
            this->isPlaying = false;
            this->wasCurrentChainModified = false;
            chain->isPlaying = true;
            chain->travelCooldown->Restart();
            Camera::Follow(&other);
          }
        }
      }
    }
  }

  /* Resolving Chain Collision With ChainTail */
  if(ChainTail* chainTail = (ChainTail*) other.GetComponent("ChainTail"))
  {
    if(!inputManager->KeyRelease(SDLK_d) && this->chainHead->currentChain == this->chainHead->chainArray.size() - 1 && this->travelCooldown->Get() >= CHAIN_TRAVEL_LIMIT)
    {
      /* Restart Timer */
      this->travelCooldown->Restart();

      /* Increments currentChain value */
      this->chainHead->currentChain++;

      /* This Chain Is Not Being Controlled Anymore */
      this->isPlaying = false;
      this->wasCurrentChainModified = false;

      /* Sets The Flag That Indicates ChainTail is Being Controlled By Fantome */
      chainTail->playing = true;

      /* Follow ChainTail */
      Camera::Follow(&other);
    }
  }
}
