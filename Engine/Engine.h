#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SceneModule.h"
#include <vector>
#include <iostream>

// SUPPRIME L'ENUM DIRECTION D'ICI (il est maintenant dans Component.h)

class Engine
{
private:
	SceneModule sceneModule;
	static Engine* instance;
public:
	static Engine* GetInstance() { return instance; }
	SceneModule getSceneModule() { return sceneModule; }
	void Init();
	void Start();
	void Update();
	void ShutDown();
};