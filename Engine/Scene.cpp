#include "Scene.h"

Scene::Scene(std::string name, sf::Vector2f size)
{
	window = sf::RenderWindow(sf::VideoMode({ 800, 600 }), name);
	this->name = name;
}

void Scene::AddGameObject(GameObject obj)
{
	objects.push_back(obj);
}

void Scene::Start()
{

	for (GameObject& object : objects)
	{
		object.Start();
	}
}

void Scene::Update()
{
	for (GameObject& object : objects)
	{
		object.Update();
	}
}

void Scene::Render()
{
		window.clear();
		for (GameObject& object : objects)
		{
			object.Render(window); 
		}
		window.display();
}

void Scene::Destroy()
{
	objects.clear();
	name = nullptr;
}