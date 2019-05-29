#pragma once
#include"Component.h"
class Face : public Component{
	private:
		int hitpoints = 30;

	public:
		Face(GameObject* associated);
	public:
		void Damage(int damage);
	public:
		void Update(float dt);
	public:
		void Render();
	public:
		void Start();
	public:
		bool Is(std::string type);

};
