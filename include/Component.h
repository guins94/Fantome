#pragma once

#include<iostream>
#include<string>

#include"GameObject.h"

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
