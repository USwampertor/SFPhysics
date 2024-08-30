#include "pch.h"
#include "PhysicsConvexPolygon.h"

using namespace sfp;

void sfp::PhysicsConvexPolygon::resetBounds()
{
	sf::FloatRect bounds = CenteredConvexShape::getGlobalBounds();
	PhysicsBodyT<CircleBounds>::getBounds().setSize(sf::Vector2f(bounds.width, bounds.height));
	
}

void sfp::PhysicsConvexPolygon::setPoint(int ptIdx, sf::Vector2f value)
{
	CenteredConvexShape::setPoint(ptIdx, value);
	resetBounds();
}
