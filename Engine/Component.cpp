#include "Component.h"

void Component::setOwner(GameObject *o)
{
	this->owner = o;
}

// Dans Component.cpp

// ... après setOwner ...

void Component::Start()
{
    // Vide par défaut
}

void Component::Update()
{
    // Vide par défaut
}

void Component::Render(sf::RenderWindow& window)
{
    // Vide par défaut
}

void Component::Destroy()
{
    // Vide par défaut
}