#include "GameObject.h"

GameObject::GameObject()
{
	/* Initializing GameObject Variables */
	this->isDead = false;
	this->started = false;
	this->angleDeg = 0;
}

GameObject::~GameObject()
{
	/* Clearing Component Array */
	this->components.clear();
}

void GameObject::Start()
{
	int i;
	/* Call Start Method for Every Component of The GameObject */
	if(!this->started)
	{
		for(i = 0; i <= this->components.size() - 1; i++)
		{
	    this->components[i]->Start();
	  }
	}

	/* Setting This GameObject Started as True */
	this->started = true;
}

void GameObject::Update(float dt)
{
	int i;
	/* Calling Update Method for Every Component of The GameObject */
	for(i = 0; i <= this->components.size() - 1; i++)
	{
    components[i]->Update(dt);
  }
}

void GameObject::Render()
{
	int i;
	/* Calling Render Method for Every Component of The GameObject */
	for(i = 0; i <= this->components.size() - 1; i++){
    components[i]->Render();
  }
}

bool GameObject::IsDead()
{
	return this->isDead;
}

void GameObject::RequestDelete()
{
	this->isDead = true;
}

void GameObject::AddComponent(Component* cpt)
{
	this->components.push_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt)
{
	if ( std::find(this->components.begin(), this->components.end(), cpt) != this->components.end()){
   		this->components.erase(std::remove(this->components.begin(), this->components.end(), cpt), this->components.end());
   	}
}

Component* GameObject::GetComponent(std::string type)
{
	int i;
	for(i = 0; i <= this->components.size() - 1; i++)
	{
		if(components[i]->Is(type))
			return this->components[i];
	}
		return nullptr;
}

int GameObject::SizeComponent()
{
	return this->components.size();
}

void GameObject::NotifyCollision(GameObject& other)
{
	int i;
	/* Calling Notify Collision Method for Every Component of The GameObject */
	for(int i = 0; i <= this->components.size() - 1; i++)
	{
		this->components[i]->NotifyCollision(other);
	}
}
