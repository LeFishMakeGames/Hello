#include "Component.h"

SpriteRenderer::SpriteRenderer():
	sprite(texture)
{

}

SpriteRenderer::SpriteRenderer(std::string s) :
	sprite(texture)
{
	texturePath = s;
}

void SpriteRenderer::Start()
{
	if (!texture.loadFromFile(texturePath)) {
		std::cout << "erreur avec le chargement de la texture";
	}
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect({ 0,0 }, { 64,64 }));
}

void SpriteRenderer::Update()
{
	float x = owner->getTransform()->x;
	float y = owner->getTransform()->y;
	float scale_x = owner->getTransform()->scale_x;
	float scale_y = owner->getTransform()->scale_y;
	sprite.setPosition({ x,y });
	sprite.setScale({ scale_x,scale_y });
	
}


void SpriteRenderer::Render(sf::RenderWindow& window)
{
	Player* p = owner->GetComponent<Player>();
	if (p != nullptr) {
		if (p->getDirection() == Direction::Up)
		{
			if (animationClock.getElapsedTime().asMilliseconds() > 80)
			{
				currentFrame = (currentFrame + 1) % 9;
				sprite.setTextureRect(sf::IntRect({ currentFrame * 64, 0 }, { 64, 64 }));
				animationClock.restart();
			}
		}
		else if (p->getDirection() == Direction::Down)
		{
			if (animationClock.getElapsedTime().asMilliseconds() > 80)
			{
				currentFrame = (currentFrame + 1) % 9;
				sprite.setTextureRect(sf::IntRect({ currentFrame * 64, 64 }, { 64, 64 }));
				animationClock.restart();
			}
		}
		else if (p->getDirection() == Direction::Left)
		{
			if (animationClock.getElapsedTime().asMilliseconds() > 80)
			{
				currentFrame = (currentFrame + 1) % 9;
				sprite.setTextureRect(sf::IntRect({ currentFrame * 64, 128 }, { 64, 64 }));
				animationClock.restart();
			}
		}
		else if (p->getDirection() == Direction::Right)
		{
			if (animationClock.getElapsedTime().asMilliseconds() > 80)
			{
				currentFrame = (currentFrame + 1) % 9;
				sprite.setTextureRect(sf::IntRect({ currentFrame * 64, 192 }, { 64, 64 }));
				animationClock.restart();
			}
		}
		window.draw(sprite);
	}
}

