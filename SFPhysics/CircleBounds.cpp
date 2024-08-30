#include "pch.h"
#include "CircleBounds.h"
#include <math.h>
#include "AABB.h"

// using namespace std;

sfp::CircleBounds::CircleBounds() :
    CircleBounds(sf::Vector2f(0.5, 0.5), 1)
{
}

sfp::CircleBounds::CircleBounds(sf::Vector2f position, float radius):
    position(position), radius(radius), visual(10.0f)
{
}

bool sfp::CircleBounds::intersectsWith(CircleBounds &other)
{
	float r = radius + other.radius;
	r *= r;
	return r < (powf(position.x + other.position.x,2) + powf(position.y + other.position.y, 2));
}

sfp::BoundsCollisionResult sfp::CircleBounds::collideWith(Bounds& other)
{
    return reverseCollsionObjects(other.collideWithCircle(*this));
}

sfp::BoundsCollisionResult sfp::CircleBounds::collideWithCircle(CircleBounds& other)
{
    // Setup a couple pointers to each object
    CircleBounds* A = this;
    CircleBounds* B = &other;
    

    // Vector from A to B
    sf::Vector2f n = B->position - A->position;
    float distSquared = powf(n.x, 2) + powf(n.y, 2);

    float r = A->radius + B->radius;
   

    if (distSquared > pow(r,2)) {
        return BoundsCollisionResult(*this, other);
    }

    // Circles have collided, now compute manifold
    float d = sqrt(distSquared); // perform actual sqrt

    // If distance between circles is not zero
    if (d != 0)
    {
        // Distance is difference between radius and distance
        float penetration = r - d;

        // Utilize our d since we performed sqrt on it already within Length( )
        // Points from A to B, and is a unit vector
        sf::Vector2f normal = (position-other.position) / d;
        return BoundsCollisionResult(*this, other, penetration, normal);
    }

// Circles are on same position
    else
    {
        // Choose random (but consistent) values
        float penetration = A->radius;
        sf::Vector2f normal = sf::Vector2f(1, 0);
        return BoundsCollisionResult(*this, other, penetration, normal);
    }
}

sfp::BoundsCollisionResult sfp::CircleBounds::collideWithAABB(AABB& other)
{
    BoundsCollisionResult result = other.collideWithCircle(*this);
    if (result.hasCollided) {
        //have to reverse bounds and normal
        return BoundsCollisionResult(result.object2, result.object1,
            result.penetration, result.normal * -1.0f);
    }
    return result;
}

sf::Vector2f sfp::CircleBounds::getPosition()
{
    return position;
}

void sfp::CircleBounds::setPosition(sf::Vector2f center)
{
    if (onMove){
        onMove(center);
    }
   
    position = center;
}

void sfp::CircleBounds::setRadius(float r)
{
    radius = r;
}

float sfp::CircleBounds::getRadius()
{
    return radius;
}

void sfp::CircleBounds::setSize(sf::Vector2f extents)
{
    setRadius(std::max(extents.x, extents.y)/2);
}

sf::Vector2f sfp::CircleBounds::getSize()
{
    return sf::Vector2f(radius,radius);
}

void sfp::CircleBounds::visualize(sf::RenderWindow& window)
{
    visual.setRadius(radius);
    visual.setPosition(position- sf::Vector2f(radius,radius));
    visual.setFillColor(sf::Color::Transparent);
    visual.setOutlineColor(sf::Color::White);
    visual.setOutlineThickness(2);
    window.draw(visual);
}
