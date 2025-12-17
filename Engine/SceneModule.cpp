#include "SceneModule.h"
#include "Scene.h"

void SceneModule::SetActiveScene(Scene* scene)
{
	activeScene = scene;
}

Scene* SceneModule::GetActiveScene()
{
	return activeScene;
}

void SceneModule::Start()
{
	if (activeScene != nullptr)
		activeScene->Start();
}

void SceneModule::Update()
{
	if (activeScene != nullptr)
		activeScene->Update();
}