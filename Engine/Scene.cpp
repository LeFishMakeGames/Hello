#include "Scene.h"

Scene::Scene(std::string name, sf::Vector2u size)
{
	window = sf::RenderWindow(sf::VideoMode(size), name);
	this->name = name;
}

void Scene::AddGameObject(GameObject& obj)
{
	objects.push_back(obj);
}

void Scene::Start()
{
	for (GameObject& object : objects)
	{
		object.Start();
	}
	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}
		window.clear();
		Update();
		Render();
		window.display();
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
	name.clear();
}