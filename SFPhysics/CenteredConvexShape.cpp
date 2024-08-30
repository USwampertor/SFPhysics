#include "pch.h"
#include "CenteredConvexShape.h"

void sfp::CenteredConvexShape::setCenter(sf::Vector2f center)
{
    setPosition(center);
}

sf::Vector2f sfp::CenteredConvexShape::getCenter()
{
    return getPosition();
}

void sfp::CenteredConvexShape::setSize(sf::Vector2f size)
{
  sf::FloatRect bounds = getLocalBounds();
    setScale(sf::Vector2f(size.x / bounds.width, size.y / bounds.height));
}

sf::Vector2f sfp::CenteredConvexShape::getSize()
{
  sf::Vector2f scale = getScale();
  sf::FloatRect bounds =getLocalBounds();
    return sf::Vector2f(scale.x*bounds.width,scale.y*bounds.height);
}
