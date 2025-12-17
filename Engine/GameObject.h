#pragma once
#include "Engine.h"
#include "Transform.h"

// IMPORTANT : On n'inclut PAS "Component.h" ici pour éviter la boucle infinie.
// On dit juste au compilateur que la classe Component existe.
class Component;

class GameObject
{
private:
    std::string name;
    bool active;
    Transform* transform;

    // CORRECTION : On stocke des POINTEURS de composants (*)
    std::vector<Component*> components;

public:
    Transform* getTransform(); // Renvoie un pointeur

    Component* AddComponent(Component* component);

    template<typename T>
    T* GetComponent()
    {
        // CORRECTION : La boucle doit parcourir des pointeurs
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