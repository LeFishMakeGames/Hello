#pragma once
// 1. On inclut les bibliothèques indispensables ici
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// 2. On déclare GameObject pour éviter la boucle d'include
class GameObject;

// 3. On déplace l'enum Direction ICI pour que tout le monde puisse l'utiliser facilement
enum class Direction
{
	Up, Down, Left, Right
};

class Component
{
protected:
	GameObject* owner;

public:
	void setOwner(GameObject* o);
	virtual void Start();
	virtual void Update();
	virtual void Render(sf::RenderWindow& window);
	virtual void Destroy();
};


class SpriteRenderer : public Component
{
private:
	std::string texturePath;
	sf::Texture texture;
	sf::Sprite sprite;
	int currentFrame = 0;
	sf::Clock animationClock;

public:
	SpriteRenderer(std::string s);
	void Start() override;
	void Update() override;
	virtual void Render(sf::RenderWindow& window) override;
};


class AudioManager : public Component
{
private:
	std::string soundPath;
	sf::SoundBuffer	soundBuffer;
	sf::Sound sound;

public:
	AudioManager(std::string s);
	void Start() override;
	void Update() override;
};

class Player : public Component
{
private:
	Direction direction;
public:
	Player();
	Direction getDirection();
	void Start();
	void Update() override;
};