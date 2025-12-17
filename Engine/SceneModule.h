#pragma once

class Scene;

class SceneModule
{

private:
	Scene* activeScene;

public:
	void SetActiveScene(Scene* scene);
	Scene* GetActiveScene();
	void Start();
	void Update();
};

