#pragma once
#include "GameObject.h"

class GameObject;



class Scene
{
private:
	std::string name;
	std::vector<GameObject> objects;
	sf::RenderWindow window;

public:
	sf::RenderWindow& getWindow() { return window; }
	Scene(std::string name, sf::Vector2u size);
	void AddGameObject(GameObject& obj);
	void Start();
	void Update();
	void Render();
	void Destroy();
};

