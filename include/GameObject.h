#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef GAMEOBJECT_HEADER
#define GAMEOBJECT_HEADER

class Component;

class GameObject{
	private:
		std::vector <Component*> components;
		bool isDead;
		bool started;
	public:
		double angleDeg;
	public:
		Rect box;
    Rect futureBox; /* Box para a próxima posição do GameObject */
	public:
		GameObject();
	public:
		~GameObject();
	public:
		void Update(float dt);
	public:
		void Render();
	public:
		void Start();
	public:
		bool IsDead();
	public:
		void RequestDelete();
	public:
		void AddComponent(Component* cpt);
	public:
		void RemoveComponent(Component* cpt);
	public:
		Component* GetComponent(std::string type);
	public:
		int SizeComponent();
	public:
		void NotifyCollision(GameObject& other);
};

#endif
