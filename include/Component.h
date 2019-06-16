#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef COMP_HEADER
#define COMP_HEADER

class GameObject;

class Component{
	protected:
		GameObject* associated;

	public:
		Component(GameObject* associated);
	public:
		Component();
	public:
 		~Component();
 	public:
		void virtual Update (float dx) = 0;
	public:
		void virtual Render () = 0;
	public:
		void virtual Start();
	public:
		bool virtual Is(std::string type)= 0;
	public:
		void virtual NotifyCollision(GameObject& other);
};

#endif
