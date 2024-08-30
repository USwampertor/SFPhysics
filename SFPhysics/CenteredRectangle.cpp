#include "pch.h"
#include "CenteredRectangle.h"

sfp::CenteredRectangle::CenteredRectangle()
{
    setCenter(sf::Vector2f(0.5, 0.5));
    setSize(sf::Vector2f(1, 1));
}

sfp::CenteredRectangle::CenteredRectangle(sf::Vector2f size):
  sf::RectangleShape(size)
{
}

void sfp::CenteredRectangle::setCenter(sf::Vector2f center)
{
  sf::Vector2f size = getSize();
  sf::RectangleShape::setPosition(center - (size / 2.0f));
}

sf::Vector2f sfp::CenteredRectangle::getCenter()
{
  sf::Vector2f size = getSize();
    return sf::RectangleShape::getPosition() + (size / 2.0f);
}

void sfp::CenteredRectangle::setSize(sf::Vector2f size)
{
  sf::Vector2f center = getCenter();
  sf::RectangleShape::setSize(size);
    setCenter(center);
}

sf::Vector2f sfp::CenteredRectangle::getSize()
{
    return sf::RectangleShape::getSize();
}
