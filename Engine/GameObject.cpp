#include "GameObject.h"

#include "Component.h"
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

Component* GameObject::AddComponent(Component* component)
{
    component->setOwner(this);
    components.push_back(component);
    return component;
}

void GameObject::Destroy()
{
    // Appelle Destroy sur tous les composants pour faire le ménage
    for (Component* component : components)
    {
        if (component != nullptr)
        {
            component->Destroy();
        }
    }
    // Si tes composants sont des pointeurs (Component*), c'est ici qu'on ferait le nettoyage mémoire (delete) plus tard.
}