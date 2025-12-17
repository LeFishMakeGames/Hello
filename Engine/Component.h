#pragma once
#include "GameObject.h"

class GameObject;

class Component
{	
protected:
	GameObject* owner;

public:
	void setOwner(GameObject *o);
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Render(sf::RenderWindow& window) = 0;
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
	SpriteRenderer();
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
