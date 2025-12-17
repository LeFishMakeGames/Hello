#include "GameObject.h"


Transform* GameObject::getTransform()
{
	return transform;
}

void GameObject::Start()
{
    for (Component* component : components)
    {
        if (component != nullptr)
        {
            component->Start();
        }
    }
}

void GameObject::Update()
{
    for (Component* component : components)
    {
        if (component != nullptr)
        {
            component->Update();
        }
    }
}

void GameObject::Render(sf::RenderWindow& window)
{
    for (Component* component : components)
    {
        if (component != nullptr)
        {
            component->Render(window);
        }
    }
}