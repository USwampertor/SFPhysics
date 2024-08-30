#include "pch.h"
#include "CenteredCircle.h"

sfp::CenteredCircle::CenteredCircle():CircleShape()
{
}

void sfp::CenteredCircle::setCenter(sf::Vector2f center)
{
	float radius = getRadius();
	CircleShape::setPosition(center- sf::Vector2f(radius,radius));
}

sf::Vector2f sfp::CenteredCircle::getCenter()
{
	return CircleShape::getPosition();
}

void sfp::CenteredCircle::setSize(sf::Vector2f sz)
{
	sf::Vector2f center = getCenter();
	float radius = std::min(sz.x, sz.y);
	setRadius(radius);
	setCenter(center);
}

sf::Vector2f sfp::CenteredCircle::getSize()
{
	float radius = getRadius();
	return sf::Vector2f(radius,radius);
}
