#include "Component.h"


AudioManager::AudioManager(std::string s):
	soundBuffer(),sound(soundBuffer)
{
	this->soundPath = s;
}