#pragma once
#include "Engine.h"
#include "Component.h"
#include "Transform.h"


class Component;



class GameObject
{
private:
	std::string name;
	bool active;
	Transform* transform;
	std::vector<Component*> components;
public:

	Transform* getTransform();



	template<typename T>
	T* AddComponent(Component* c)
	{
		T* component = new T();
		component->SetOwner(this);
		components.push_back(component);
		return component;
	}

	template<typename T>
	T* GetComponent()
	{
		for (Component* component : components)
		{
			T* casted_component = dynamic_cast<T*>(component);
			if (casted_component != nullptr)
			{
				return casted_component;
			}
		}
		return nullptr;
	}




	void Start();
	void Update();
	void Render(sf::RenderWindow& window);
	void Destroy();
};

