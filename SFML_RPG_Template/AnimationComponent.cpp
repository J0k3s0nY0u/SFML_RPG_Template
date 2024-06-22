#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet)
	:sprite(sprite), textureSheet(texture_sheet)
{
}

AnimationComponent::~AnimationComponent()
{
}

//Functions


void AnimationComponent::addAnimation(const std::string key)
{
}

void AnimationComponent::play(const std::string key, const float& dt)
{
	this->animations[key].play(dt);
}
