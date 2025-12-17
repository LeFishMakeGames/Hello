#include "Engine.h"
#include "Scene.h"

GameObject createPlayer()
{
	GameObject Player;
	SpriteRenderer* sr = new SpriteRenderer("image.png");
	Player.AddComponent(sr);
	return Player;
}


int main()
{
	Engine engine;
	Scene lvl1("heelo", {800,800});
	GameObject player = createPlayer();
	lvl1.AddGameObject(player);

	engine.getSceneModule().SetActiveScene(&lvl1);
	engine.Start();
}