#include "pch.h"
#include "PhysicsSprite.h"

void sfp::PhysicsSprite::setTexture(sf::Texture& img)
{
	CenteredSprite::setTexture(img);
	sf::IntRect sz = CenteredSprite::getTextureRect();
	PhysicsBodyT<AABB>::getBounds().setSize(sf::Vector2f(sz.width, sz.height));
	setCenter(CenteredSprite::getCenter());
}
