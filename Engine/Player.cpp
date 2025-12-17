#include "Component.h"




Player::Player()
{

}

void Player::Start()
{

}

Direction Player::getDirection()
{
	return direction;
}


void Player::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		owner->getTransform()->y -= 0.1f;
		direction = Direction::Up;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		owner->getTransform()->y += 0.1f;
		direction = Direction::Down;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		owner->getTransform()->x -= 0.1f;
		direction = Direction::Left;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		owner->getTransform()->x += 0.1f;
		direction = Direction::Right;
	}
}