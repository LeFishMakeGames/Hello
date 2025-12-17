#pragma once
#include <iostream>
#include <string>              // Pour std::string
#include <SFML/Graphics.hpp>   // Pour sf::RenderWindow, sf::Sprite, etc.
#include <SFML/Audio.hpp>      // Pour sf::Sound, sf::SoundBuffer

class GameObject;

class Component
{	
protected:
	GameObject* owner;

public:
	void setOwner(GameObject *o);
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
