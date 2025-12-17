#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SceneModule.h"
#include <vector>
#include <iostream>
#include <string>

enum class Direction
{
	Up, Down, Left, Right
};




class Engine
{
private:
	SceneModule sceneModule;
	static Engine* instance;
public:
	Engine();
	static Engine* GetInstance() { return instance;}
	SceneModule &getSceneModule() { return sceneModule;}
	void Init();
	void Start();
	void Update();
	void ShutDown();
};